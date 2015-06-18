/********************************************************************
	> File Name: ./tcp_func.c
	> Author: he_CentOS
	> Mail:1778195296@qq.com 
	> Created Time: 2015年02月08日 星期日 21时11分10秒
 *******************************************************************/

#include "tcp.h"

int ftp_init()
{//socket(),bind(),listen(),返回socket描述符
	int sfd=socket(AF_INET,SOCK_STREAM,0);
	if(-1==sfd)
	{
		perror("sfd");
		exit(1);
	}
	//
	struct sockaddr_in server_addr;
	server_addr.sin_family=AF_INET;
	server_addr.sin_port=htons(PORT);
	server_addr.sin_addr.s_addr=inet_addr(IP);
	int addr_len=sizeof(struct sockaddr);
	//绑定
	if(-1==bind(sfd,(struct sockaddr*)&server_addr,(socklen_t)addr_len))
	{
		perror("bind");
		close(sfd);
		exit(1);
	}
	//监听
	if(-1==listen(sfd,5))
	{
		perror("listen");
		close(sfd);
		exit(1);
	}
	return sfd;
}

int ftp_accept(int sfd)
{//同意connect()
	struct sockaddr_in client_addr;
	int len=sizeof(struct sockaddr);
	//
	int sfd_new=accept(sfd,(struct sockaddr*)&client_addr,(socklen_t*)&len);
	if(-1==sfd_new)
	{
		perror("accept");
		close(sfd);
		close(sfd_new);
		exit(1);
	}
	//
	printf("%s %d success connect...\n",inet_ntoa(client_addr.sin_addr),ntohs(client_addr.sin_port));
	return sfd_new;
}

int tcp_connect()
{//客户端连接
	//生成socket描述符
	int sfd=socket(AF_INET,SOCK_STREAM,0);
	if(-1==sfd)
	{
		perror("socket");
		exit(1);
	}
	//
	struct sockaddr_in server_addr;
	server_addr.sin_family=AF_INET;
	server_addr.sin_port=htons(PORT);
	server_addr.sin_addr.s_addr=inet_addr(IP);
	int len=sizeof(struct sockaddr);
	//连接
	printf("connecting...\n");
	if(-1==connect(sfd,(const struct sockaddr*)&server_addr,(socklen_t)len))
	{
		perror("connect");
		close(sfd);
		exit(1);
	}
	printf("connected success!\n");
	return sfd;
}

void signal_handle(void)
{//ctrl+c ctrl+d信号处理
/*
	sigset_t sigset;
	sigemptyset(&sigset);
	sigaddset(&sigset,SIGINT);
	sigaddset(&sigset,SIGQUIT);
	sigprocmask(SIG_BLOCK,&sigset,NULL);
*/
}
