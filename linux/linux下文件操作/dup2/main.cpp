/*************************************************************************
    > File Name: main.cpp
    > Author: 时中贺
    > Mail: shi_zhonghe@163.com 
    > Created Time: 2015年06月19日 星期五 17时28分02秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>
#include<unistd.h>
#include<errno.h>

int main(void)
{
	char buf[32] = {0};
	int fda = open("./a.txt", O_RDONLY);
	int fdb = open("./b.txt", O_RDONLY);
	if(-1 == fda || -1 == fdb)
	{
		perror("open error!\n");
		exit(-1);
	}

	printf("fda:%d	fdb:%d\n", fda, fdb);
	read(fdb, buf, sizeof(buf)-1);
	puts(buf);
	memset(buf, 0, sizeof(buf));
	int fdc = dup(fdb);
	if(-1 == fdc)
	{
		perror("open error!\n");
		exit(-1);
	}
	dup2(fda, fdb);
	printf("fda:%d	fdb:%d	fdc:%d\n", fda, fdb, fdc);
	read(fdb, buf, sizeof(buf)-1);
	puts(buf);
	close(fda);
	close(fdb);
	close(fdc);

	return 0;
}
