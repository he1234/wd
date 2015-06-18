/********************************************************************
	> File Name: ./src/main.c
	> Author: he_CentOS
	> Mail:1778195296@qq.com 
	> Created Time: 2015年01月28日 星期三 05时21分32秒
 *******************************************************************/

#include "dup.h"
int main(int argc,char** argv)
{
	int fb=open("./data/a.txt",O_RDWR);
	if(-1==fb)
	{
		perror("open failed!\n");
		exit(-1);
	}
	int fa=dup(fb);
	char buf[32];
	read(fb,buf,4);
	puts(buf);
	close(fb);
	lseek(fa,5,SEEK_SET);
	read(fa,buf,4);
	puts(buf);
	close(fa);
	return 0;
}
