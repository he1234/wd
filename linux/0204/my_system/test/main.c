/********************************************************************
	> File Name: ./main.c
	> Author: he_CentOS
	> Mail:1778195296@qq.com 
	> Created Time: 2015年02月04日 星期三 08时35分28秒
 *******************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc,char* argv[])
{
	char line[1024];
	int iret=getpid();
	printf("pid:%d\n",iret);
	while(memset(line,0,1024),fgets(line,1024,stdin)!=NULL)
	{
		puts(line);
	}
	return 0x08;
}
