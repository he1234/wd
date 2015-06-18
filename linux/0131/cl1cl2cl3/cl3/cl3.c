/********************************************************************
	> File Name: cl3/cl3.c
	> Author: he_CentOS
	> Mail:1778195296@qq.com 
	> Created Time: 2015年01月31日 星期六 06时11分29秒
 *******************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<sys/time.h>
#include<sys/select.h>
int main(int argc,char* argv[])
{
	int fd31,fd32,fd13,fd23;
	fd31=open("31",O_WRONLY);
	fd32=open("32",O_WRONLY);
	fd13=open("13",O_RDONLY);
	fd23=open("23",O_RDONLY);
	printf("OK!\n");

	fd_set read_sets;
	fd_set write_sets;
	int iret,iwrt;
	char buf[1024];
	struct timeval tm;
	while(1)
	{
		tm.tv_sec=1;
		tm.tv_usec=0;
		FD_ZERO(&read_sets);
		FD_ZERO(&write_sets);

		FD_SET(fd13,&read_sets);
		FD_SET(fd23,&read_sets);
		FD_SET(0,&write_sets);

		iret=select(10,&read_sets,NULL,NULL,&tm);
		iwrt=select(10,&write_sets,NULL,NULL,&tm);
		if(iret!=0)
		{
			printf("active:%d\n",iret);
			if(FD_ISSET(fd13,&read_sets))
			{
				memset(buf,0,1024);
				read(fd13,buf,1023);
				printf("from 1:%s\n",buf);
			}
			if(FD_ISSET(fd23,&read_sets))
			{
				memset(buf,0,1024);
				read(fd23,buf,1023);
				printf("from 2:%s\n",buf);
			}
		}

		if(iwrt!=0)
		{
			printf("active:%d\n",iwrt);
			if(FD_ISSET(0,&write_sets))
			{
				memset(buf,0,128);
				read(0,buf,127);
				write(fd31,buf,strlen(buf));
				write(fd32,buf,strlen(buf));
			}
		}
	}

	return 0;
}
