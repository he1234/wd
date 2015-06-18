/*************************************************************************
	> File Name: client.c
	> Author: Comst
	> Mail:750145240@qq.com 
	> Created Time: Fri 27 Feb 2015 06:40:29 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#define SER_IP "192.168.1.79"
#define SER_PORT 1234
#define MY_ASSERT(flag, msg)  do	{\
										(flag) || (printf("%s\n",msg ) , exit(1) , 0  ) ;\
									}while(0)
int main(int argc, char* argv[])// ip port 
{
	int  fd_client ;
	MY_ASSERT( (fd_client = socket(AF_INET, SOCK_STREAM, 0)) != -1, "client socket init" );
	struct sockaddr_in seraddr ; 
	memset(&seraddr, 0, sizeof(seraddr));
	seraddr.sin_family = AF_INET ;
	seraddr.sin_port = htons( SER_PORT );
	seraddr.sin_addr.s_addr = inet_addr(SER_IP);
	MY_ASSERT(connect(fd_client, (struct sockaddr*)&seraddr, sizeof(seraddr)) == 0, "connect");
	char buf[1024] ;
	while(memset(buf, 0, 1024), fgets(buf, 1024, stdin) != NULL)
	{
		printf(  "sendn: %d\n",send(fd_client, buf, strlen(buf), 0) );
	}

	return 0 ;
}
