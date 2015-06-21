/********************************************************************
	> File Name: ./ex2/ex2.c
	> Author: he_CentOS
	> Mail:1778195296@qq.com 
	> Created Time: 2015年01月31日 星期六 17时08分36秒
 *******************************************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(int argc,char* argv[])
{
	FILE* fd=popen("cat ./ex2.c","r");//创建子进程，并读"cat ./ex2.c"进程输出的结果
	char buf[1024];
	if(fd==NULL)
	{
		perror("open error");
		exit(1);
	}
	while(memset(buf,0,1024),fgets(buf,sizeof(buf),fd))
	{
		printf("%s", buf);
	}
	pclose(fd);//等待新进程结束
}
