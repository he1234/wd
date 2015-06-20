/********************************************************************
	> File Name: ./cl1/cl1.c
	> Author: he_CentOS
	> Mail:1778195296@qq.com 
	> Created Time: 2015年01月29日 星期四 04时10分57秒
 *******************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>

int main(int argc,char* argv[])
{
	int fb12,fb13,fb21,fb31;
	char buf[1024];
	int res;
	fb12=open("12",O_WRONLY);
	fb13=open("13",O_WRONLY);

	fb21=open("21",O_RDONLY);
	fb31=open("31",O_RDONLY);
	printf("12 13 21 31 is OK!\n");

	while(1)
	{
		printf("input:\n");
		memset(buf,0,1024);
		res=read(0,buf,1024);
		if(res==0)
		{
			printf("*****\n");
			break;
		}
		write(fb12,buf,strlen(buf));
		write(fb13,buf,strlen(buf));

		//
		printf("reading 2\n");
		memset(buf,0,1024);
		res=read(fb21,buf,1024);
		if(res==0)
		{
			printf("exit 2\n");
		}
		printf("from 2:%s",buf);

		//
		printf("reading 3\n");
		memset(buf,0,1024);
		res=read(fb31,buf,1024);
		if(res==0)
		{
			printf("exit 3\n");
		}
		printf("from 3:%s",buf);
	}
	close(fb31);
	close(fb21);
	close(fb13);
	close(fb12);
	return 0;
}
