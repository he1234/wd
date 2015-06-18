/********************************************************************
	> File Name: ./main.c
	> Author: he_CentOS
	> Mail:1778195296@qq.com 
	> Created Time: 2015年02月03日 星期二 20时30分56秒
 *******************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
int main(int argc,char* argv[])
{//fork一个子进程，通过read,write,文件描述符，父进程向子进程发送数据
	//见今天另外一个程序fork
	char buf[1024];
	int fds[2];
	pipe(fds);//创建无名管道
	pid_t pid;
	pid=fork();//克隆子进程
	if(pid>0)
	{
		close(fds[0]);
		while(memset(buf,0,1024),read(0,buf,1024)!=0)
		{
			write(fds[1],buf,strlen(buf));
			write(fds[1],buf,strlen(buf));
		}
		wait(NULL);//阻塞，等待直到子进程结束
		close(fds[1]);
	}
	else if(pid==0)
	{
		close(fds[1]);
		while(memset(buf,0,1024),read(fds[0],buf,1024)!=0)
		{
			printf("from father:%s\n",buf);
		}
		close(fds[0]);
	}
	return 0;
}
