/*************************************************************************
    > File Name: main.c
    > Author: 时中贺
    > Mail: shi_zhonghe@163.com 
    > Created Time: 2015年06月22日 星期一 09时51分49秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<sys/time.h>
#include<time.h>
#include<signal.h>

void sighandler(int signo)
{
	time_t tt;
	time(&tt);
	struct tm *current_time = gmtime(&tt);
	printf("\033[1A");	// "\033["或"\e["表示操作屏幕，1A表示光标上移一行
	printf("\e[K");		// 'K'表示清除该行
	printf("%04d-%02d-%02d %02d:%02d:%02d\n",\
			current_time -> tm_year + 1900, current_time -> tm_mon + 1, current_time -> tm_mday,\
			current_time -> tm_hour + 8, current_time -> tm_min, current_time -> tm_sec);
}

void init_timer(int a, int b)
{
	signal(SIGALRM, sighandler);
	struct itimerval tt;
	tt.it_interval.tv_sec = a;	//每隔it_interval时间刷新一次时间
	tt.it_interval.tv_usec = b;
	tt.it_value.tv_sec = a;		//it_value时间后,发出第一个SIGALRM信号
	tt.it_value.tv_usec = b;
	putchar(10);
	if(setitimer(ITIMER_REAL, &tt, NULL))	//设置真实计时器
	{
		perror("set timer error");
		exit(-1);
	}
}

int main(void)
{
	init_timer(1, 0);
	while(1);
	return 0;
}
