/********************************************************************
  > File Name: ./main.c
  > Author: he_CentOS
  > Mail:1778195296@qq.com 
  > Created Time: 2015年02月06日 星期五 20时39分20秒
 *******************************************************************/

#include<stdio.h>
#include<pthread.h>
#include<string.h>
#include<stdlib.h>
int* func1(int val)
{
	int* s_val = (int*)calloc(1, sizeof(int)) ; 
	*s_val = val ;
	sleep(3) ;

	return s_val ;
}
int* func2(int val)
{
	static int s_val  ; 
	s_val = val ;
	sleep(3) ;

	return &s_val ;
}
void* thd2_func(void* arg)
{
	func2(0);
}
int main(int argc, char* argv[])
{
	int val = 1024 ;
	int cnt = 10 ;
	int* p   ;
	pthread_t thd ;
	pthread_create(&thd, NULL, thd2_func, NULL);
	while(cnt)
	{
		p = func2(val);
		printf("val : %d\n", *p);
		cnt -- ;
	}
	pthread_join(thd, NULL);
	return 0 ;
}
