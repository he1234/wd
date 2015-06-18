/********************************************************************
	> File Name: epoll_server.c
	> Author: he_CentOS
	> Mail:1778195296@qq.com 
	> Created Time: 2015年02月28日 星期六 16时25分53秒
 *******************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<string.h>
#include<unistd.h>
#include<sys/epoll.h>
#define SER_IP "192.168.1.79"
#define SER_PORT 1234

#define MY_ASSERT(flag,msg) do	{\
									(flag)||(printf("%s\n",msg),exit(1),0);\
								}while(0)
int main(int argc,char* argv[])
{
	int fd_listen,fd_client;
	int index,ready_events;
	char buf[1024];
	
	MY_ASSERT((fd_listen=socket(AF_INET,SOCK_STREAM,0))!= -1,"socket");
	struct sockaddr_in ser_addr;
	memset(&ser_addr,0,sizeof(ser_addr));
	ser_addr.sin_family=AF_INET;
	ser_addr.sin_port=htons(SER_PORT);
	ser_addr.sin_addr.s_addr=inet_addr(SER_IP);

	MY_ASSERT(0==bind(fd_listen,(struct sockaddr*)&ser_addr,sizeof(ser_addr)),"bind");
	MY_ASSERT(0==listen(fd_listen,10),"listen");

	int fd_epoll;
	MY_ASSERT(-1!=(fd_epoll=epoll_create(1024)),"epoll create");
	
	struct epoll_event my_event,my_events[1024];
	memset(&my_event,0,sizeof(my_event));
	my_event.events=EPOLLIN;
	my_event.data.fd=fd_listen;

	MY_ASSERT(0==epoll_ctl(fd_epoll,EPOLL_CTL_ADD,fd_listen,&my_event),"epoll ctl");

	while(1)
	{
		memset(my_events,0,sizeof(my_events));
		MY_ASSERT(-1!=(ready_events=epoll_wait(fd_epoll,my_events,1024,-1)),"epoll wait");
		for(index=0;index<ready_events;index++)
		{
			if(my_events[index].events&EPOLLIN&&my_events[index].data.fd==fd_listen)
			{
				fd_client=accept(fd_listen,NULL,NULL);
				printf("a client connect!\n");

				memset(&my_event,0,sizeof(my_event));
				my_event.events=EPOLLIN;
				my_event.data.fd=fd_client;

				MY_ASSERT(0==epoll_ctl(fd_epoll,EPOLL_CTL_ADD,fd_client,&my_event),"epoll ctl add");
				printf("one client on!\n");
			}
			else if(my_events[index].events&EPOLLIN)
			{
				memset(buf,0,1024);
				if(0==recv(my_events[index].data.fd,buf,1024,0))
				{
					printf("one client exit!\n");
					MY_ASSERT(0==epoll_ctl(fd_epoll,EPOLL_CTL_DEL,my_events[index].data.fd,NULL),"epoll ctl del");
				}
				else
				{
					printf("from client:%s\n",buf);
				}

			}
		}
	}
	return 0;
}
