/*************************************************************************
    > File Name: main.c
    > Author: 时中贺
    > Mail: shi_zhonghe@163.com 
    > Created Time: 2015年06月21日 星期日 17时19分22秒
 ************************************************************************/

#include<stdio.h>
#include<signal.h>

int cnt = 0;
void sighandler_new(int signo, siginfo_t *psiginfo, void *pReserved)
{
	int count = ++cnt;
	printf("%d enter, signo: %d\n", count, signo);
	sleep(3);
	printf("%d enter, signo: %d\n", count, signo);
}

int main(void)
{
	//将SIGINT和SIGQUIT加入阻塞集
	sigset_t sigset;
	sigemptyset(&sigset);
	sigaddset(&sigset, SIGINT);
	sigaddset(&sigset, SIGQUIT);
	//设置全程阻塞,即阻塞集中的信号不但在某个信号处理函数中被屏蔽，在所有函数中都被屏蔽。即阻塞集中的信号不起作用
	sigprocmask(SIG_BLOCK, &sigset, NULL);

	struct sigaction act;
	act.sa_flags = SA_SIGINFO;
	act.sa_sigaction = sighandler_new;
	sigemptyset(&act.sa_mask);//已经设置全程阻塞了，不用再设置单个的了，清空即可
	sigaction(SIGINT, &act, NULL);

	while(1)
		sleep(1);

	return 0;
}
