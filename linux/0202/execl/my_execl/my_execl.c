/*************************************************************************
    > File Name: my_execl.c
    > Author: 时中贺
    > Mail: shi_zhonghe@163.com 
    > Created Time: 2015年06月20日 星期六 13时29分10秒
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>

int main(void)
{
	printf("pid: %d\n", getpid());
	execl("./show_args/show_args", "./show_args/show_args", "hello", "world", NULL);	//最后以NULL结尾，表示参数没了
	printf("Over !");	//这句不执行，因为该进程被execvp函数替换为show_args进程了

	return 0;
}
