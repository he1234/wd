/********************************************************************
	> File Name: ./main.c
	> Author: he_CentOS
	> Mail:1778195296@qq.com 
	> Created Time: 2015年02月05日 星期四 22时57分33秒
 *******************************************************************/

#include<stdio.h>
#include<pthread.h>
#include<malloc.h>

void free_buf(void* pargs)
{
	free(pargs);
	printf("clean up the memory!\n");
}
void* pthread_func(void* pargs)
{
	int i;
	char* buf=(char*)malloc(10);

	//pthread_exit()或pthread_cancel()之后，自动从栈中弹出，立即执行free_buf()
	pthread_cleanup_push(free_buf,buf);
	for(i=0;i<10;i++)
	{
		printf("hello,my name is shizhonghe!\n");
		sleep(1);
	}
	pthread_cleanup_pop(0);
	pthread_exit((void*)3);//线程异常退出返回-1，正常退出返回3
}
int main(int argc,char* argv)
{
	pthread_t pth_id;
	pthread_create(&pth_id,NULL,pthread_func,NULL);
	int j;
	for(j=1;j<5;j++)
	{
		printf("hello world!\n");
		sleep(1);
		if(j==3)
			pthread_cancel(pth_id);
	}
	int retvalue=0;
	pthread_join(pth_id,(void**)&retvalue);
	printf("return value is %d\n",(int)retvalue);//
	return 0;
}
