/********************************************************************
	> File Name: server_func.c
	> Author: he_CentOS
	> Mail:1778195296@qq.com 
	> Created Time: 2015年03月02日 星期一 15时42分24秒
 *******************************************************************/

#include "server.h"

void signal_handle(int signum)
{
	while(waitpid(-1,NULL,WNOHANG)>0);//
}

int socket_init()
{
	int sfd_listen=socket(AF_INET,SOCK_STREAM,0);
	if(-1==sfd_listen)
	{
		perror("socket init");
		exit(1);
	}
	//struct sockaddr_in初始化
	struct sockaddr_in ser_addr;
	socklen_t sockaddr_len=sizeof(ser_addr);
	memset(&ser_addr,0,sockaddr_len);
	ser_addr.sin_family=AF_INET;
	ser_addr.sin_port=htons(SER_PORT);
	ser_addr.sin_addr.s_addr=inet_addr(SER_IP);

	if(0!=bind(sfd_listen,(struct sockaddr*)&ser_addr,sockaddr_len))
	{
		perror("bind");
		close(sfd_listen);
		exit(1);
	}

	if(0!=listen(sfd_listen,1024))
	{
		perror("listen");
		close(sfd_listen);
		exit(1);
	}
	return sfd_listen;
}

int socket_accept(int sfd,struct sockaddr* client_addr)
{
	socklen_t sockaddr_len=sizeof(struct sockaddr);
	int sfd_client=accept(sfd,client_addr,&sockaddr_len);
	if(-1==sfd_client)
	{
		perror("accept");
		close(sfd_client);
		close(sfd);
		exit(1);
	}
	return sfd_client;
}

static int recv_buf(int sfd,char* buf,int len)
{
	int recv_ret,recv_sum=0;
	while(recv_sum!=len)
	{
		recv_ret=recv(sfd,buf+recv_sum,len-recv_sum,0);
		recv_sum+=recv_ret;
	}
	return recv_sum;
}

static int send_buf(int sfd,char* buf,int len)
{
	int send_ret,send_sum=0;
	while(send_sum!=len)
	{
		send_ret=send(sfd,buf+send_sum,len-send_sum,0);
		send_sum+=send_ret;
	}
	return send_sum;
}

static int readn(int fd,char* buf,int len)
{//读取fd描述符的数据到buf
	int read_sum=0,read_ret;
	while(read_sum!=len)
	{
		read_ret=read(fd,buf+read_sum,len-read_sum);
		if(read_ret==0)
			break;
		read_sum+=read_ret;
	}
	buf[read_sum]='\0';
	return read_sum;
}

static int transfer_to_client(int sfd,char* file_name)
{//向客户端发送数据
	int fd_read=open(file_name,O_RDONLY);
	if(-1==fd_read)
	{
		return -1;
	}
	char *buf=calloc(1024*8,sizeof(char));
	int read_ret;
	while(1)
	{
		read_ret=readn(fd_read,buf,8192);
		send(sfd,(char*)&read_ret,4,0);
		send_buf(sfd,buf,read_ret);
		if(read_ret<8192)
			break;
	}
	read_ret=0;
	send(sfd,(char*)&read_ret,4,0);
	close(fd_read);
	return 0;
}

static int transfer_from_client(int sfd,char* file_name)
{//接收客户端上传的数据
}

void child_main(int sfd)
{
	int recv_len;
	char cmd[256];
	while(1)
	{
		//接收客户端命令行
		recv(sfd,(char*)&recv_len,4,0);
		if(0==recv_len)
		{
			break;
		}
		recv_buf(sfd,cmd,recv_len);

		if(0==strncmp("cd",cmd,2))
		{
			char dir[256]="";
			sscanf(cmd+3,"%s",dir);
			int len=strlen(dir);

			chdir(dir);

			send(sfd,(char*)&len,sizeof(int),0);
			send_buf(sfd,dir,len);
		}
		else if(0==strncmp("pwd",cmd,3))
		{
			char dir[256]="";
			sscanf(cmd+4,"%s",dir);
			strcpy(dir,getcwd(NULL,0));
			int len=strlen(dir);

			send(sfd,(char*)&len,sizeof(int),0);
			send_buf(sfd,dir,len);
		}
		else if(0==strncmp("ls",cmd,2))
		{
			printf("%s\n",getcwd(NULL,0));
			DIR* pdir=opendir("./");
			if(NULL!=pdir)
			{
				int flag= -1;
				send(sfd,(char*)&flag,4,0);
			}
			struct dirent* my_dir;
			struct stat my_stat;
			char buf[256];
			int send_len;
			while(bzero(my_dir,sizeof(my_dir)),NULL!=(my_dir=readdir(pdir)))
			{
				if(0==strncmp(".",my_dir->d_name,1)||0==strncmp("..",my_dir->d_name,2))
				{
					continue;
				}
				bzero(&my_stat,sizeof(my_stat));
				stat(my_dir->d_name,&my_stat);
				bzero(send_buf,256);
				sprintf(buf,"%s	%dB",my_dir->d_name,my_stat.st_size);
				send_len=strlen(buf);
				send(sfd,(char*)&send_len,4,0);
				send_buf(sfd,buf,send_len);
			}
			send_len=0;
			send(sfd,(char*)&send_len,4,0);
		}
		else if(0==strncmp("gets",cmd,4))
		{//客户端下载
			char file_name[256];
			int file_pos=5;
			while(bzero(file_name,256),1==sscanf(cmd+file_pos,"%s",file_name))
			{
				file_pos+=strlen(file_name)+1;
				if(0==transfer_to_client(sfd,file_name))
					printf("transfer file to client :%s success!\n",file_name);
				else
					printf("transfer to client :%s failure!\n",file_name);
			}
		}
		else if(0==strncmp("puts",cmd,4))
		{//客户端上传
		}
		else if(0==strncmp("remove",cmd,6))
		{//删除
		}
	}
}
