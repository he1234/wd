/********************************************************************
	> File Name: ./my_exec/my_exec.c
	> Author: he_CentOS
	> Mail:1778195296@qq.com 
	> Created Time: 2015年02月02日 星期一 03时10分41秒
 *******************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
int main(int argc,char* argv[])
{
	printf("pid: %d\n",getpid());
	char *arglist[]={"./show_args/show_args","./show_args/show_args","hello","world",NULL};
	execvp(arglist[0],arglist);
	printf("-----------------\n");
}
