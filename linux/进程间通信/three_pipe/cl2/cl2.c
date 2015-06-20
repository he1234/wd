/********************************************************************
	> File Name: ./cl2/cl2.c
	> Author: he_CentOS
	> Mail:1778195296@qq.com 
	> Created Time: 2015年01月29日 星期四 04时49分44秒
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
	int fb12,fb32,fb21,fb23;
	char buf[1024];
	int res;
	
	fb12=open("12",O_RDONLY);
	fb21=open("21",O_WRONLY);

	fb23=open("23",O_WRONLY);
	fb32=open("32",O_RDONLY);
	printf("12 32 21 23 is OK!\n");
	while(1)
	{
		printf("reading 1\n");
		memset(buf,0,1024);
		res=read(fb12,buf,1024);
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
		write(fb21,buf,strlen(buf));
		write(fb23,buf,strlen(buf));

		//
		printf("reading 3\n");
		memset(buf,0,1024);
		res=read(fb32,buf,1024);
		if(res==0)
		{
			printf("exit 3\n");
		}
		printf("from 3:%s",buf);
	}
	close(fb12);
	close(fb32);
	close(fb21);
	close(fb23);
	return 0;
}
