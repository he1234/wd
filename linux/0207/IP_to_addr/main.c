/********************************************************************
	> File Name: ./main.c
	> Author: he_CentOS
	> Mail:1778195296@qq.com 
	> Created Time: 2015年02月07日 星期六 20时14分09秒
 *******************************************************************/

#include<stdio.h>
#include<string.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#define IP "180.97.33.107"//B461216B

int main(int argc,char* argv[])
{
	struct in_addr addr;
	memset(&addr,0,sizeof(addr));
	inet_aton(IP,&addr);
	printf("%x\n",addr.s_addr);
	memset(&addr,0,sizeof(addr));
	addr.s_addr=inet_addr(IP);
	printf("%x\n",addr.s_addr);
	char* pstr=inet_ntoa(addr);
	puts(pstr);
	return 0;
}
