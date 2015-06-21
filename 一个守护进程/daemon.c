/*************************************************************************
    > File Name: daemon.c
    > Author: 时中贺
    > Mail: shi_zhonghe@163.com 
    > Created Time: 2015年06月21日 星期日 00时26分57秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<time.h>

void init_daemon()
{
	pid_t pid;
	if(pid = fork())//结束父进程，子进程在后台运行
		exit(0);
	else if(pid < 0)
		exit(-1);
	setsid();	//让进程摆脱原会话的控制，让进程摆脱原进程组的控制，让进程摆脱原控制终端的控制
	if(pid = fork())//第一子进程为无终端的会话组长，使第一子进程不再成为会话组长从而禁止进程重新打开控制终端 ，所以结束第一子进程
		exit(0);
	else if(pid < 0)
		exit(-1);
	//以下是第二子进程
	for(int i = 0; i < 64; ++i)
		close(i);
	chdir("/");
	umask(0);
}

int main(void)
{
	signal(SIGCHLD, SIG_IGN);//父进程忽略SIGCHLD信号，子进程结束后交给init
	init_daemon();
	FILE *fp;
	time_t tt;
	for(int i = 0; i < 30; ++i)
	{
		sleep(3);
		if((fp = fopen("/home/he/Desktop/daemon.log", "a")) >= 0)
		{
			time(&tt);
			struct tm *ptm = gmtime(&tt);
			fprintf(fp, "%04d-%02d-%02d %02d : %02d :%02d\n", \
					ptm -> tm_year + 1900, ptm -> tm_mon + 1, ptm -> tm_mday,\
					ptm -> tm_hour + 8, ptm -> tm_min, ptm -> tm_sec);
			fclose(fp);
		}
	}
	return 0;
}
