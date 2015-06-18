/********************************************************************
	> File Name: ./main.c
	> Author: he_CentOS
	> Mail:1778195296@qq.com 
	> Created Time: 2015年02月07日 星期六 21时26分28秒
 *******************************************************************/

#include<stdio.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#define IP "192.168.0.101"
int main(int argc,char* argv[])
{
	struct in_addr my_addr;
	int iret;

	iret=inet_aton(IP,&my_addr);
	printf("iret=%d	%x\n",iret,my_addr.s_addr);

	printf("%x\n",inet_addr(IP));
	//AF_INET代表IPv4,AF_INET6代表IPv6
	iret=inet_pton(AF_INET,IP,&my_addr);
	printf("iret=%d	%x\n",iret,my_addr.s_addr);
	
	printf("------------------------------------------\n");
	my_addr.s_addr=0xac100ac4;
	printf("%s\n",inet_ntoa(my_addr));

	char ip[16];
	inet_ntop(AF_INET,&my_addr,ip,16);
	puts(ip);
	return 0;
}
