/*************************************************************************
    > File Name: main.c
    > Author: 时中贺
    > Mail: shi_zhonghe@163.com 
    > Created Time: 2015年06月21日 星期日 17时48分41秒
 ************************************************************************/

#include<stdio.h>
#include<signal.h>

int cnt = 0;
void sighandler_new(int signo, siginfo_t *psiginfo, void *pReversed)
{
	int count = ++cnt;
	printf("%d enter, signo: %d\n", count, signo);
	sleep(3);
	printf("%d leave, signo: %d\n", count, signo);
}

int main(void)
{
	sigset_t sigset;
	sigemptyset(&sigset);
	sigaddset(&sigset, SIGINT);
	sigaddset(&sigset, SIGQUIT);
	sigprocmask(SIG_BLOCK, &sigset, NULL);

	struct sigaction act;
	act.sa_flags = SA_SIGINFO;
	act.sa_sigaction = sighandler_new;
	sigemptyset(&act.sa_mask);
	sigaction(SIGINT, &act, NULL);
	sigaction(SIGQUIT, &act, NULL);

	int icount = 0;
	while(1)
	{
		if(icount > 3)
		{
			sigset_t sigset2;
			sigemptyset(&sigset2);
			sigaddset(&sigset2, SIGINT);
			sigprocmask(SIG_UNBLOCK, &sigset2, NULL);//从阻塞信号集中移除信号集sigeset2中的信号
		}
		sleep(2);
		icount++;
	}

	return 0;
}
