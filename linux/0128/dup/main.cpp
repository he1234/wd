/*************************************************************************
    > File Name: main.cpp
    > Author: 时中贺
    > Mail: shi_zhonghe@163.com 
    > Created Time: 2015年06月19日 星期五 13时06分19秒
 ************************************************************************/

#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdio.h>
#include<errno.h>
#include<unistd.h>
#include<stdlib.h>

int main(void)
{
	int fb = open("./a.txt", O_RDWR);
	if(-1 == fb)
	{
		perror("open failed !\n");
		exit(-1);
	}

	int fa = dup(fb);
	char buf[32];
	read(fb, buf, 4);
	puts(buf);
	close(fb);
//	lseek(fa, 5, SEEK_SET);
	read(fa, buf, 4);
	puts(buf);
	close(fa);

	return 0;
}
