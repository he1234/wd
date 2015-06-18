/********************************************************************
	> File Name: ./main.c
	> Author: he_CentOS
	> Mail:1778195296@qq.com 
	> Created Time: 2015年02月05日 星期四 16时20分54秒
 *******************************************************************/

#include<stdio.h>
#include<unistd.h>
#include<pthread.h>

void* thread_func(void* parg)
{
	int iarg=(int)parg;
	sleep(iarg);
	if(iarg<3)
		return (void*)(iarg*2);
	else
		pthread_exit((void*)(iarg*2));
}
int main(int argc,char* argv[])
{
	pthread_t thd_id;
	int iret=0;
	pthread_create(&thd_id,NULL,thread_func,(void*)2);
	pthread_join(thd_id,(void**)&iret);
	printf("the first child thread ret is:%d\n",iret);

	pthread_create(&thd_id,NULL,thread_func,(void*)4);
	pthread_join(thd_id,(void**)&iret);
	printf("the second child thread ret is :%d\n",iret);

	return 0;
}
