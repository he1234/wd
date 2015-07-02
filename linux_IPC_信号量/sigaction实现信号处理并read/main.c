/*************************************************************************
    > File Name: main.c
    > Author: 时中贺
    > Mail: shi_zhonghe@163.com 
    > Created Time: 2015年06月21日 星期日 14时49分50秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<signal.h>

int cnt = 0;
void sighandler_new(int signo, siginfo_t *psigninfo, void *pReserved)
{
	int count = ++cnt;
	printf("%d enter, signo: %d\n", count, signo);
	sleep(3);
	printf("%d leave, signo: %d\n", count, signo);
}

int main(void)
{
	struct sigaction act;
	act.sa_flags = SA_SIGINFO | SA_RESTART;
	act.sa_sigaction = sighandler_new;
	//假如SIGQUIT在信号屏蔽集合中，而程序正在执行SIGINT的信号处理函数，
	//此时来了一个SIGQUIT信号，则SIGQUIT暂时被屏蔽，
	//SIGINT信号处理函数执行完毕后才去执行SIGQUIT信号处理函数。
	sigemptyset(&act.sa_mask);
	sigaddset(&act.sa_mask, SIGQUIT);
	sigaction(SIGINT, &act, NULL);
//	sigaction(SIGQUIT, &act, NULL);

	char buf[8];
	int iret;
	do
	{
		iret = read(STDIN_FILENO, buf, sizeof(buf) - 1);
		if(-1 == iret)
		{
			perror("read error");
			exit(-1);
		}
		buf[iret] = '\0';
		puts(buf);
	}while(strcmp(buf, "quit\n"));

	return 0;
}
