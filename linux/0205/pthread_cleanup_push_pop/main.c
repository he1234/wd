/********************************************************************
	> File Name: ./main.c
	> Author: he_CentOS
	> Mail:1778195296@qq.com 
	> Created Time: 2015年02月05日 星期四 21时37分19秒
 *******************************************************************/

#include<stdio.h>
#include<pthread.h>
void clean_func(void* parg)
{
	printf("%d clean!\n",(int)parg);
}
void pthread_func(void *parg)
{
	pthread_cleanup_push(clean_func,(void*)1);
	pthread_cleanup_push(clean_func,(void*)2);
	pthread_cleanup_push(clean_func,(void*)3);
	sleep(2);
	pthread_exit(NULL);
	pthread_cleanup_pop(2);//参数为>1，表示立即执行
	pthread_cleanup_pop(1);//该参数并非控制栈的出栈个数
	pthread_cleanup_pop(0);//参数为零，表示暂不执行clean_func()，
		//仅仅在pthread_exit()之后或其它线程调用pthread_cancel()后执行
		//pthread_cleanup_push()必须和pthread_cleanup_pop()个数一致
}
int main(int argc,char* argv[])
{
	pthread_t pth_id;
	int retval;
	pthread_create(&pth_id,NULL,pthread_func,NULL);
	pthread_join(pth_id,NULL);
	return 0;
}
