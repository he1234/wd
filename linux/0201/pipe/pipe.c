/********************************************************************
	> File Name: ./pipe.c
	> Author: he_CentOS
	> Mail:1778195296@qq.com 
	> Created Time: 2015年01月31日 星期六 18时05分13秒
 *******************************************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(int argc,char* argv[])
{
	int fds[2]={0};
	char buf[1024];
	memset(buf,0,1024);
	pipe(fds);
	if(fork()==0)
	{
		close(fds[1]);
		printf("in child process!\n");
		sleep(2);//确保父进程关闭读，并往管道写
		if(-1==read(fds[0],buf,sizeof(buf)))
		{
			perror("read error:");
			exit(1);
		}
		puts(buf);
		close(fds[0]);
		exit(0);
	}
	else
	{
		close(fds[0]);
		printf("in father process!\n");
		if(-1==write(fds[1],"how are you!",11))
		{
			perror("write error:");
			exit(1);
		}
		printf("father writer success!\n");
		waitpid(fds[0],NULL,0);//等子进程关闭读
		close(fds[1]);
		exit(0);
	}
	return 0;
}
