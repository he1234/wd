/********************************************************************
	> File Name: ./main.c
	> Author: he_CentOS
	> Mail:1778195296@qq.com 
	> Created Time: 2015年02月06日 星期五 19时53分38秒
 *******************************************************************/

#include<stdio.h>
#include<pthread.h>
int i=0;

void* pthread_func(void* plock)
{
	int cnt=10000000;
	while(cnt>0)
	{
		pthread_mutex_lock(plock);
		i++;
		pthread_mutex_unlock(plock);
		cnt--;
	}
	pthread_exit(NULL);
}
int main(int argc,char* argv[])
{
	pthread_t pth_id1,pth_id2;
	pthread_mutex_t lock;
	pthread_mutex_init(&lock,NULL);

	pthread_create(&pth_id1,NULL,pthread_func,&lock);
	pthread_create(&pth_id2,NULL,pthread_func,&lock);

	pthread_join(pth_id1,NULL);
	pthread_join(pth_id2,NULL);
	printf("i=%d\n",i);

	pthread_mutex_destroy(&lock);

	return 0;
}
