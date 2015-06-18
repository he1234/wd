/********************************************************************
	> File Name: cl1/cl1.c
	> Author: he_CentOS
	> Mail:1778195296@qq.com 
	> Created Time: 2015年01月29日 星期四 08时06分18秒
 *******************************************************************/

#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>
#include<unistd.h>
#include<sys/select.h>
#include<stdlib.h>
int main(int argc,char* argv[])
{
	int fd21,fd31;
	fd21=open("21.fifo",O_RDONLY);
	fd31=open("31.fifo",O_RDONLY);
	fd_set read_sets;
	int iret;
	char buf[1024];
	struct timeval tm;
	printf("OK!\n");
	while(1)
	{
		tm.tv_sec=8;
		tm.tv_usec=0;
		FD_ZERO(&read_sets);
		FD_SET(fd21,&read_sets);
		FD_SET(fd31,&read_sets);
		iret=select(1024,&read_sets,NULL,NULL,&tm);
//		printf("iret=%d\n",iret);
		if(iret==0)
		{
//			printf("timeout!\n");
			continue;
		}
		else if(iret== -1)
		{
			perror("select\n");
			exit(1);
		}
		else
		{
			printf("active:iret = %d\n",iret);
			if(FD_ISSET(fd21,&read_sets))
			{
				memset(buf,0,1024);
				read(fd21,buf,1024);
				printf("from 2:%s\n",buf);
			}
			if(FD_ISSET(fd31,&read_sets))
			{
				memset(buf,0,1024);
				read(fd31,buf,1024);
				printf("from 3:%s\n",buf);
			}
		}
	}
	close(fd21);
	close(fd31);
	return 0;
}
