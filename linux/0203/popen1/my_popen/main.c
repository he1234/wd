/********************************************************************
	> File Name: ./main.c
	> Author: he_CentOS
	> Mail:1778195296@qq.com 
	> Created Time: 2015年02月03日 星期二 21时23分26秒
 *******************************************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(int argc,char* argv[])
{//argv[1]存放my_reverse的路径
	//popen若以读的方式打开管道，创建子进程，执行cmd所示的程序或命令，
	//读取子进程printf出的数据，子进程stdout重定位为父进程的读管道
	printf("pid:%d\n",getpid());
	FILE* fp_in;
	char cmd[1024];
	char str[1024];
	while(memset(str,0,1024),fgets(str,1024,stdin)!=NULL)
	{
		memset(cmd,0,1024);
		sprintf(cmd,"%s %s",argv[1],str);
		fp_in=popen(cmd,"r");//popen()以读方式打开管道，创建子进程
		if(fp_in==NULL)
		{
			perror("popen");
			exit(1);
		}
		memset(str,0,1024);
		fscanf(fp_in,"%s",str);
		printf("res:%s\n",str);
	}
	return 0;
}
