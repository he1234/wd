/********************************************************************
	> File Name: ./show_args/show_args.c
	> Author: he_CentOS
	> Mail:1778195296@qq.com 
	> Created Time: 2015年02月02日 星期一 03时16分02秒
 *******************************************************************/

#include<stdio.h>
int main(int argc,char* argv[])
{
	int index;
	printf("show_args:%d\n",getpid());
	for(index=0;index<argc;index++)
	{
		printf("argv[%d]:%s\n",index,argv[index]);

	}
	return 0;
}
