/*************************************************************************
    > File Name: main.c
    > Author: 时中贺
    > Mail: shi_zhonghe@163.com 
    > Created Time: 2015年06月21日 星期日 23时02分49秒
 ************************************************************************/

#include<stdio.h>
#include<signal.h>

void sighandler(int signo)
{
	printf("signo is %d\n", signo);
}

int main(void)
{
	signal(SIGALRM, sighandler);
	alarm(3);
	printf("before pause\n");
	pause();
	printf("after pause\n");
	return 0;
}
