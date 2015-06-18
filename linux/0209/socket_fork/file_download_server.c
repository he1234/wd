/********************************************************************
	> File Name: ./file_down_server.c
	> Author: he_CentOS
	> Mail:1778195296@qq.com 
	> Created Time: 2015年02月09日 星期一 22时24分28秒
 *******************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<fcntl.h>
#include<netinet/in.h>
#include<sys/stat.h>
#include<arpa/inet.h>
#include<signal.h>
#define SER_IP "192.168.1.101"
#define SER_PORT 1234

int send_buf(int sfd,char* buf,int len);
int recv_buf(int sfd,char* buf,int len);
void child_main(int fd_listen);
void child_handle(int signum)
{
	wait(NULL);
}

int main(int argc,char* argv[])
{//实现下载文件
	int fd_listen;
	int fd_client;
	//处理SIGCHLD信号
	signal(17,child_handle);

	fd_listen=socket(AF_INET,SOCK_STREAM,0);
	if(-1==fd_listen)
	{
		perror("socket");
		exit(1);
	}

	struct sockaddr_in server_addr,client_addr;
	socklen_t sock_len=sizeof(struct sockaddr);
	memset(&server_addr,0,sock_len);
	server_addr.sin_family=AF_INET;
	server_addr.sin_port=htons(SER_PORT);
	server_addr.sin_addr.s_addr=inet_addr(SER_IP);

	if(-1==bind(fd_listen,(struct sockaddr*)&server_addr,sock_len))
	{
		perror("bind");
		close(fd_listen);
		exit(1);
	}
	if(-1==listen(fd_listen,5))
	{
		perror("listen");
		close(fd_listen);
		exit(1);
	}

	while(1)
	{
		sock_len=sizeof(client_addr);
		memset(&client_addr,0,sock_len);
		fd_client=accept(fd_listen,(struct sockaddr*)&client_addr,&sock_len);
		if(fork()==0)
		{
			close(fd_listen);
			char buf_addr[16]={0};
			strcpy(buf_addr,inet_ntoa(client_addr.sin_addr));
			int iport=ntohs(client_addr.sin_port);
			printf("client %s:%d connect!\n",buf_addr,iport);

			child_main(fd_client);
			printf("client %s:%d disconnect!\n",buf_addr,iport);
			close(fd_client);
			exit(1);
		}
		close(fd_client);
	}
	return 0;
}

int send_buf(int sfd,char* buf,int len)
{
	int send_sum=0;
	int send_ret;
	while(send_sum<len)
	{
		send_ret=send(sfd,buf+send_sum,len-send_sum,0);
		send_sum+=send_ret;
	}
	return send_sum;
}

int recv_buf(int sfd,char* buf,int len)
{
	int recv_sum=0;
	int recv_ret;
	while(recv_sum<len)
	{
		recv_ret=recv(sfd,buf+recv_sum,len-recv_sum,0);
		recv_sum+=recv_ret;
	}
	return recv_sum;
}

void child_main(int fd_client)
{
	int recv_len;
	int send_len;
	char file_name[128]="";
	char msg[1024];
	//接收客户端要下载的文件
	recv_buf(fd_client,(char*)&recv_len,4);
	recv_buf(fd_client,file_name,recv_len);
	int fd_file=open(file_name,O_RDONLY);
	//向客户端发送是否可以接收文件
	if(-1==fd_file)
	{
		memset(msg,0,1024);
		strcpy(msg,"error");
		send_buf(fd_client,(char*)&send_len,4);
		send_buf(fd_client,msg,send_len);
		return;
	}
	memset(msg,0,1024);
	strcpy(msg,"ok");
	send_len=strlen(msg);
	send_buf(fd_client,(char*)&send_len,4);
	send_buf(fd_client,msg,send_len);
	
	while(memset(msg,0,1024),(send_len=read(fd_file,msg,1024))!=0)
	{//发送文件
		send_buf(fd_client,(char*)&send_len,4);
		send_buf(fd_client,msg,send_len);
	}
	send_len=0;
	send_buf(fd_client,(char*)&send_len,4);
}
