/*************************************************************************
    > File Name: main.c
    > Author: 时中贺
    > Mail: shi_zhonghe@163.com 
    > Created Time: 2015年06月21日 星期日 14时09分50秒
 ************************************************************************/

#include<stdio.h>
#include<signal.h>

int cnt = 0;
void sighandler_new(int signo, siginfo_t *psig_info, void *pReserved)
{
	int count = ++cnt;
	printf("%d enter sighandler_new, signo: %d\n", count, signo);
	sleep(3);
	printf("%d leave sighandler_new, signo: %d\n", count, signo);
}

int main(void)
{
	struct sigaction act;
	act.sa_flags = SA_SIGINFO | SA_NODEFER;
	act.sa_sigaction = sighandler_new;
	sigaction(SIGINT, &act, NULL);
	sigaction(SIGQUIT, &act, NULL);
	while(1)
		sleep(1);

	return 0;
}
