/********************************************************************
	> File Name: ./main.c
	> Author: he_CentOS
	> Mail:1778195296@qq.com 
	> Created Time: 2015年02月05日 星期四 15时29分51秒
 *******************************************************************/

#include<stdio.h>
#include<pthread.h>

void *thd_handle(void* arg)
{
	printf("%u:hello world\n",pthread_self());
	while(1)
	{
		printf("thd_handle!\n");
		sleep(1);
	}
	pthread_exit(NULL);
}
int main(int argc,char* argv[])
{
	printf("main:thd:%u\n",pthread_self());

	pthread_t thd;
	pthread_create(&thd,NULL,thd_handle,NULL);
	printf("main:creat thd:%u\n",thd);
//	pthread_join(thd,NULL);

	while(1)
	{
		printf("main:\n");
		sleep(1);
	}
	return 0;
}
