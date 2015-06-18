/********************************************************************
	> File Name: ./main.c
	> Author: he_CentOS
	> Mail:1778195296@qq.com 
	> Created Time: 2015年02月06日 星期五 10时23分23秒
 *******************************************************************/

#include<stdio.h>
#include<pthread.h>
pthread_mutex_t lock;
pthread_cond_t cond;

void* thread_clean(void* pargs)
{
	printf("thread_clean is running!\n");
	pthread_mutex_unlock(&lock);
}
void* pth_1(void* pargs)
{
	pthread_cleanup_push(thread_clean,NULL);
	while(1)
	{
		printf("pth_1 get running!\n");
		printf("pth_1 pthread_mutex_lock returns %d\n",pthread_mutex_lock(&lock));
		pthread_cond_wait(&cond,&lock);
		printf("pth_1 condition applied!\n");
		pthread_mutex_unlock(&lock);
		sleep(5);
	}
	pthread_cleanup_pop(0);
	return 0;
}

void* pth_2(void* pargs)
{
	while(1)
	{
		sleep(3);
		printf("pth_2 get running!\n");
		printf("pth_2 pthread_mutex_lock return %d\n",pthread_mutex_lock(&lock));

		pthread_cond_wait(&cond,&lock);
		printf("pth_2 condition applied!\n");
		pthread_mutex_unlock(&lock);
		sleep(1);
	}
	return 0;
}
int main(int argc,char* argv[])
{
	printf("hello,pthread_cond_wait() test!\n");
	pthread_t pth_id1,pth_id2;

	pthread_mutex_init(&lock,NULL);
	pthread_cond_init(&cond,NULL);

	pthread_create(&pth_id1,NULL,pth_1,NULL);
	pthread_create(&pth_id2,NULL,pth_2,NULL);

	while(1)
	{
		sleep(2);
		pthread_cancel(pth_id1);
		sleep(2);
		pthread_cond_signal(&cond);
	}
	sleep(5);
	return 0;
}
