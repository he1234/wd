/********************************************************************
	> File Name: ./cl3/cl3.c
	> Author: he_CentOS
	> Mail:1778195296@qq.com 
	> Created Time: 2015年01月29日 星期四 04时55分41秒
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
	int fb23,fb13,fb31,fb32;
	char buf[1024];
	int res;

	fb13=open("13",O_RDONLY);
	fb23=open("23",O_RDONLY);
	fb31=open("31",O_WRONLY);
	fb32=open("32",O_WRONLY);
	printf("23 13 31 32 is OK!\n");
	while(1)
	{
		printf("reading 2\n");
		memset(buf,0,1024);
		res=read(fb23,buf,1024);
		if(res==0)
		{
			printf("exit 2\n");
		}
		printf("from 2:%s",buf);

		//
		printf("reading 1\n");
		memset(buf,0,1024);
		res=read(fb13,buf,1024);
		if(res==0)
		{
			printf("exit 1\n");
		}
		printf("from 1:%s",buf);

		//
		printf("input:\n");
		memset(buf,0,1024);
		res=read(0,buf,1024);
		if(res==0)
		{
			printf("*****\n");
			break;
		}
		write(fb31,buf,strlen(buf));
		write(fb32,buf,strlen(buf));
	}
	close(fb13);
	close(fb23);
	close(fb31);
	close(fb32);
	return 0;
}
