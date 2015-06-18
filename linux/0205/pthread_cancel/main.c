/********************************************************************
	> File Name: ./main.c
	> Author: he_CentOS
	> Mail:1778195296@qq.com 
	> Created Time: 2015年02月05日 星期四 20时59分58秒
 *******************************************************************/

#include<stdio.h>
#include<pthread.h>
#include<malloc.h>

void* thread_func(void *args)
{
	char *p=(char*)malloc(10);
	int i=0;
	for(;i<10;i++)
	{
		printf("hello,my name is shizhonghe!\n");
		sleep(1);
	}
	free(p);
	printf("p is freed!\n");
	pthread_exit((void*)3);
}

int main(int argc,char* argv[])
{
	pthread_t pthid;
	pthread_create(&pthid,NULL,thread_func,NULL);
	int i=1;
	for(;i<5;i++)
	{
		printf("hello, nice to meet you!\n");
		sleep(1);
//	if(i%3==0)					//取消注释会导致子进程free函数无法执行
//		pthread_cancel(pthid);//需要用到pthread_cleanup_push和pthread_cleanup_pop函数释放空间
	}
	int retvalue=0;
	pthread_join(pthid,(void**)&retvalue);
	printf("return value is :%d\n",retvalue);
	return 0;
}
