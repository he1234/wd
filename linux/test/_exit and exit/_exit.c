/*************************************************************************
    > File Name: _exit.c
    > Author: 时中贺
    > Mail: shi_zhonghe@163.com 
    > Created Time: 2015年06月20日 星期六 22时56分20秒
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>

int main(void)
{
	printf("hello world !\n");
	printf("How are you !");	//_exit不会清理I/O缓冲，所以这句话不会输出
	_exit(0);
}
