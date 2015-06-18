/********************************************************************
	> File Name: ./file_download_client.c
	> Author: he_CentOS
	> Mail:1778195296@qq.com 
	> Created Time: 2015年02月09日 星期一 22时24分52秒
 *******************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<signal.h>
#define SER_IP "192.168.1.101"
#define SER_PORT 1234
int send_buf(int sfd,char* buf,int len);
int recv_buf(int sfd,char* buf,int len);
int main(int argc,char* argv[])
{//argv[1]输入服务器上的文件路径，argv[2]输入客户端下载路径
	int fd_client;
	int send_len,recv_len;
	char msg[1024];
	fd_client=socket(AF_INET,SOCK_STREAM,0);

	struct sockaddr_in server_addr;
	memset(&server_addr,0,sizeof(server_addr));
	server_addr.sin_family=AF_INET;
	server_addr.sin_port=htons(SER_PORT);
	server_addr.sin_addr.s_addr=inet_addr(SER_IP);
	if(-1==connect(fd_client,(struct sockaddr*)&server_addr,16))
	{
		perror("connect");
		close(fd_client);
		exit(1);
	}

	memset(msg,0,1024);
	strcpy(msg,argv[1]);
	send_len=strlen(msg);
	//发送要下载的文件
	send_buf(fd_client,(char*)&send_len,4);
	send_buf(fd_client,msg,send_len);
	if(strcmp(msg,"error")==0)
	{
		printf("error file file!\n");
		close(fd_client);
		return 0;
	}
	printf("begin recv file!\n");
	int fd_file=open(argv[2],O_WRONLY|O_CREAT,0666);
	if(-1==fd_file)
	{
		perror("open");
		close(fd_client);
		exit(1);
	}
	printf("begin recv file!\n");
	int recv_sum=0;
	while(1)
	{
		memset(msg,0,1024);
		//接收文件
		recv_buf(fd_client,(char*)&recv_len,4);
		if(recv_len==0)
		{
			close(fd_client);
			break;
		}
		recv_sum+=recv_buf(fd_client,msg,recv_len);
		write(fd_file,msg,recv_len);
		system("clear");
		printf("downloading... %.2fkbs\n",(double)recv_sum/1024);
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
