/********************************************************************
	> File Name: client_func.c
	> Author: he_CentOS
	> Mail:1778195296@qq.com 
	> Created Time: 2015年03月02日 星期一 21时41分16秒
 *******************************************************************/

#include "client.h"	

int socket_init()
{
	int sfd_client=socket(AF_INET,SOCK_STREAM,0);
	if(-1==sfd_client)
	{
		perror("socket init");
		exit(1);
	}
	struct sockaddr_in ser_addr;
	ser_addr.sin_family=AF_INET;
	ser_addr.sin_port=htons(SER_PORT);
	ser_addr.sin_addr.s_addr=inet_addr(SER_IP);
	socklen_t sockaddr_len=sizeof(struct sockaddr);

	if(-1==connect(sfd_client,(struct sockaddr*)&ser_addr,sockaddr_len))
	{
		perror("connect");
		close(sfd_client);
		exit(1);
	}
	return sfd_client;
}

int send_buf(int sfd,char* buf,int len)
{//发送len个char型数据
	int send_ret,send_sum=0;
	while(send_sum!=len)
	{
		send_ret=send(sfd,buf+send_sum,len-send_sum,0);
		send_sum+=send_ret;
	}
	return send_sum;
}

int recv_buf(int sfd,char* buf,int len)
{
	int recv_ret,recv_sum=0;
	while(recv_sum!=len)
	{
		recv_ret=recv(sfd,buf+recv_sum,len-recv_sum,0);
		recv_sum+=recv_ret;
	}
	return recv_sum;
}

int get_name(char* file_name,int file_name_len,char* name)
{//获取文件名(不包含路径部分)
	int index;
	for(index=file_name_len-1;index>0;index--)
	{
		if(file_name[index]=='/')
			break;
	}
	strcpy(name,file_name+index+1);
	return (file_name_len-index-1);
}

int writen(int fd,char* buf,int len)
{
	int write_sum=0,write_ret;
	while(write_sum!=len)
	{
		write_ret=write(fd,buf+write_sum,len-write_sum);
		write_sum+=write_ret;
	}
	return write_sum;
}

int receive_from_server(int sfd,char* file_name)
{
	int fd_write=open(file_name,O_WRONLY | O_CREAT,0666);
	if(-1==fd_write)
	{
		perror("open");
		return -1;
	}
	char *buf=calloc(1024*8,sizeof(char));
	int recv_ret;
	while(1)
	{
		recv(sfd,(char*)&recv_ret,4,0);
		if(0==recv_ret)
		{//
			break;
		}
		recv_buf(sfd,buf,recv_ret);
		writen(fd_write,buf,recv_ret);
	}
	close(fd_write);
	return 0;
}
