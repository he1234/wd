/********************************************************************
	> File Name: ./main.c
	> Author: he_CentOS
	> Mail:1778195296@qq.com 
	> Created Time: 2015年02月06日 星期五 00时33分20秒
 *******************************************************************/

#include<stdio.h>
#include<pthread.h>
pthread_mutex_t lock;

void* pth_func(void* pargs)
{
	pthread_mutex_lock(&lock);
//	pthread_mutex_lock(&lock);
	pthread_mutex_trylock(&lock);
	printf("hello!\n");
	sleep(1);
	pthread_mutex_unlock(&lock);
	pthread_exit(NULL);
}
int main(int argc,char* argv[])
{
	pthread_t pth_id;
	pthread_mutex_init(&lock,NULL);
	pthread_create(&pth_id,NULL,pth_func,NULL);
	pthread_join(pth_id,NULL);
	pthread_mutex_destroy(&lock);
	return 0;
}
