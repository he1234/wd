/********************************************************************
	> File Name: epoll_server.c
	> Author: he_CentOS
	> Mail:1778195296@qq.com 
	> Created Time: 2015年03月01日 星期日 10时40分22秒
 *******************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<sys/epoll.h>
#include<errno.h>

#define SER_IP "192.168.1.79"
#define SER_PORT 1234
#define MY_ASSERT(flag,msg) do	{\
									(flag)||(printf("%s\n",msg),exit(1),0);\
								}while(0)

void setnonblock(int sfd)
{
	int flag=fcntl(sfd,F_GETFL);
	flag=flag|O_NONBLOCK;
	fcntl(sfd,F_SETFL,flag);
}
int main(int argc,char* argv[])
{
	int fd_listen,fd_client;
	MY_ASSERT(-1!=(fd_listen=socket(AF_INET,SOCK_STREAM,0)),"socket init");
	struct sockaddr_in ser_addr;
	ser_addr.sin_family=AF_INET;
	ser_addr.sin_port=htons(SER_PORT);
	ser_addr.sin_addr.s_addr=inet_addr(SER_IP);

	MY_ASSERT(0==bind(fd_listen,(struct sockaddr*)&ser_addr,sizeof(ser_addr)),"bind");
	MY_ASSERT(0==listen(fd_listen,1024),"listen");

	int fd_epoll;
	MY_ASSERT(-1!=(fd_epoll=epoll_create(1024)),"epoll create");

	struct epoll_event my_event,my_events[1024];
	my_event.events=EPOLLIN;
	my_event.data.fd=fd_listen;

	MY_ASSERT(0==epoll_ctl(fd_epoll,EPOLL_CTL_ADD,fd_listen,&my_event),"epoll ctl listen");

	int index,ready_events;
	int recv_ret,recv_sum;
	char buf[1024];
	
	while(1)
	{
		memset(my_events,0,sizeof(my_events));
		ready_events=epoll_wait(fd_epoll,my_events,1024,-1);
		for(index=0;index<ready_events;index++)
		{
			if(my_events[index].events & EPOLLIN && my_events[index].data.fd==fd_listen)
			{
				MY_ASSERT(-1!=(fd_client=accept(fd_listen,NULL,NULL)),"accept");
				printf("one client on!\n");
				setnonblock(fd_client);//

				memset(&my_event,0,sizeof(my_event));
				my_event.events=EPOLLIN | EPOLLET;//
				my_event.data.fd=fd_client;
				
				MY_ASSERT(0==epoll_ctl(fd_epoll,EPOLL_CTL_ADD,fd_client,&my_event),"epoll ctl fd_client");
			}
			else if(my_events[index].events & EPOLLIN)
			{
				memset(buf,0,1024);
				recv_sum=0;
				while(1)
				{//从一个客户端接收数据
					recv_ret=recv(my_events[index].data.fd,buf+recv_sum,1024-recv_sum,0);
					if(recv_ret==0)
					{
						printf("one client exit!\n");
						MY_ASSERT(0==epoll_ctl(fd_epoll,EPOLL_CTL_DEL,my_events[index].data.fd,NULL),"epoll ctl del");
						break;
					}
					else if(recv_ret>0)
					{
						recv_sum+=recv_ret;
					}
					else if(-1==recv_ret && errno==EAGAIN)
					{
						printf("recv from client:%s\n",buf);
						break;
					}
				}
			}
		}
	}
	return 0;
}
