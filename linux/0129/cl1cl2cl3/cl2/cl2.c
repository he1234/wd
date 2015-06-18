/********************************************************************
	> File Name: ./cl2/cl2.c
	> Author: he_CentOS
	> Mail:1778195296@qq.com 
	> Created Time: 2015年01月29日 星期四 16时23分37秒
 *******************************************************************/

#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>
#include<unistd.h>
int main(int argc,char* argv[])
{
	int fd21=open("21.fifo",O_WRONLY);
	char buf[1024];
	printf("OK!\n");
	while(1)
	{
		memset(buf,0,1024);
		read(0,buf,1023);
		write(fd21,buf,strlen(buf));
	}
	close(fd21);
	return 0;
}
