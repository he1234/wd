/*************************************************************************
    > File Name: main.cpp
    > Author: 时中贺
    > Mail: shi_zhonghe@163.com 
    > Created Time: 2015年06月18日 星期四 15时19分34秒
 ************************************************************************/

#include<pthread.h>
#include<unistd.h>
#include<stdio.h>

void* alive_thread(void *arg)
{
	while(1)
	{
		usleep(1000*1000);
	}
}

void* dead_thread(void *arg)
{
	pthread_mutex_t mutex;
	pthread_mutex_init(&mutex, NULL);
	usleep(1000*1000);
	fprintf(stderr, "timeout we will start dead lock\n");
	pthread_mutex_lock(&mutex);
	pthread_mutex_lock(&mutex);
}
//调试步骤结果见我的马克飞象
int main(void)
{
	pthread_t alive_pid;
	pthread_create(&alive_pid, NULL, alive_thread, NULL);
	pthread_t dead_pid;
	pthread_create(&dead_pid, NULL, dead_thread, NULL);
	void *ret1 = NULL;
	pthread_join(alive_pid, &ret1);
	void *ret2 = NULL;
	pthread_join(dead_pid, &ret2);

	return 0;
}
