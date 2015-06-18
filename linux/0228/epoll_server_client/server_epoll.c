/********************************************************************
	> File Name: ./server_epoll.c
	> Author: he_CentOS
	> Mail:1778195296@qq.com 
	> Created Time: 2015年02月28日 星期六 08时51分04秒
 *******************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/epoll.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<arpa/inet.h>
#define SER_IP "192.168.1.79"
#define SER_PORT 1234

//以下宏定义中'\'不能省略
//如果flag为真,继续；为假，打印msg，并异常退出
#define MY_ASSERT(flag,msg) do	{\
									(flag)||(printf("%s\n",msg),exit(1),0);\
								}while(0)

int main(int argc,char* argv[])
{
	int fd_listen,fd_client;
	int epoll_fd;
	MY_ASSERT((fd_listen=socket(AF_INET,SOCK_STREAM,0))!= -1,"listen socket init");
	struct sockaddr_in seraddr;
	memset(&seraddr,0,sizeof(seraddr));
	seraddr.sin_family=AF_INET;
	seraddr.sin_port=htons(SER_PORT);
	seraddr.sin_addr.s_addr=inet_addr(SER_IP);
	MY_ASSERT(bind(fd_listen,(struct sockaddr*)&seraddr,sizeof(seraddr))==0,"bind");
	MY_ASSERT(listen(fd_listen,10)==0,"listen");
	//创建epoll描述符
	MY_ASSERT((epoll_fd=epoll_create(1024))!= -1,"epoll create");

	struct epoll_event my_event,my_events[1024];
	char buf[1024];
	int ready_events,index;
	//初始化my_event结构体
	memset(&my_event,0,sizeof(my_event));
	my_event.events=EPOLLIN;
	my_event.data.fd=fd_listen;
	//注册需要监听的描述符fd_listen，和要监听的事件类型my_event，以及对该描述符采取的动作EPOLL_CTL_ADD
	MY_ASSERT(epoll_ctl(epoll_fd,EPOLL_CTL_ADD,fd_listen,&my_event)==0,"epoll ctl");

	while(1)
	{
		memset(my_events,0,sizeof(my_events));
		//监听,实参-1表示一直阻塞，my_events表示存放发生事件的集合，epoll_wait()返回该集合的大小
		ready_events=epoll_wait(epoll_fd,my_events,1024,-1);
		for(index=0;index<ready_events;index++)
		{
			if(my_events[index].events&EPOLLIN&&my_events[index].data.fd==fd_listen)
			{//如果fd_listen发生读变化
				fd_client=accept(my_events[index].data.fd,NULL,NULL);
				printf("a client connect!\n");

				memset(&my_event,0,sizeof(my_event));
				my_event.events=EPOLLIN;
				my_event.data.fd=fd_client;

				MY_ASSERT(epoll_ctl(epoll_fd,EPOLL_CTL_ADD,fd_client,&my_event)==0,"epoll ctl client");
			}
			else if(my_events[index].events&EPOLLIN)
			{//如果除fd_listen之外的其它描述符发生读变化
				memset(buf,0,1024);
				if(recv(my_events[index].data.fd,buf,1024,0)==0)
				{//如果未接收到数据
					printf("a client exit!\n");
					//取消注册描述符
					MY_ASSERT(epoll_ctl(epoll_fd,EPOLL_CTL_DEL,my_events[index].data.fd,NULL)==0,"epoll del");
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

