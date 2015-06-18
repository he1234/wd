/********************************************************************
	> File Name: ./src/main.c
	> Author: he_CentOS
	> Mail:1778195296@qq.com 
	> Created Time: 2015年01月28日 星期三 05时53分24秒
 *******************************************************************/

#include "dup_stdout.h"
int main(int argc,char** argv)
{//利用dup重定位
	int fb=open("./data/a.txt",O_WRONLY|O_CREAT);
	if(-1==fb)
	{
		perror("open error!\n");
		exit(-1);
	}
	putchar(10);//	一定不能少，否则出错!!!
	close(1);	//关闭stdout
	int fa=dup(fb);	//fa赋值为1,即是标准输出
	close(fb);
	printf("hello world!\n");
	close(fa);
	return 0;
}
