/*************************************************************************
    > File Name: main.cpp
    > Author: 时中贺
    > Mail: shi_zhonghe@163.com 
    > Created Time: 2015年06月19日 星期五 17时57分41秒
 ************************************************************************/

#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>

int main(void)
{//利用dup重定位
	int fa = open("./a.txt", O_WRONLY|O_CREAT);
	if(-1 == fa)
	{
		perror("open fa");
		exit(-1);
	}
	putchar(10);	//putchar(10);这句话一定不能少！！！否则出错，见3_linux下编译与调试.doc

	close(1);		//关闭stdout
	int fb = dup(fa);	//fa赋值为1,即是标准输出
	close(fa);
	printf("hello world !\n");
	close(fb);

	return 0;
}
