/********************************************************************
	> File Name: ./ex1/ex1.c
	> Author: he_CentOS
	> Mail:1778195296@qq.com 
	> Created Time: 2015年01月31日 星期六 16时48分59秒
 *******************************************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(int argc,char* argv[])
{
	char buf[]={"aaa bbb ccc ddd eee fff ggg hhh"};
	FILE* fd=popen("wc -w","w");//创建子进程，并向子进程传递参数
	if(fd==NULL)
	{
		perror("open error:");
		exit(1);
	}
	fwrite(buf,strlen(buf),1,fd);//通过管道向子进程"wc -w"传递参数
	pclose(fd);
	return 0;
}
