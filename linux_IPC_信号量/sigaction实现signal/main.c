/*************************************************************************
    > File Name: main.c
    > Author: 时中贺
    > Mail: shi_zhonghe@163.com 
    > Created Time: 2015年06月21日 星期日 13时43分41秒
 ************************************************************************/

#include<stdio.h>
#include<signal.h>

void sig_handler(int sig_no)
{
	printf("sig_no : %d\n", sig_no);
}

int main(void)
{
	struct sigaction act;
	act.sa_flags = 0;
	act.sa_handler = sig_handler;
	sigaction(SIGINT, &act, NULL);//same as signal(SIGINT, sig_handler);
	while(1)
		sleep(1);

	return 0;
}
