/*************************************************************************
    > File Name: main.c
    > Author: 时中贺
    > Mail: shi_zhonghe@163.com 
    > Created Time: 2015年06月21日 星期日 11时09分03秒
 ************************************************************************/

/*输入输出结果分析
1、	[CTRL+c] [CTRL+c]	（一个一个挨着执行，先执行第一个SIGINT,再执行第二个SIGINT）
2、	[CTRL+c] [CTRL+\]	（先执行c的进入，被\打断，转而执行\，最后执行c的退出）
3、	hello [CTRL+\] [Enter]	（先执行中断，没有任何输出）
4、	[CTRL+\] hello [Enter]	（先执行中断，输出内容）
5、	hel [CTRL+\] lo[Enter]	（先执行中断，只输出lo）
*/
#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<string.h>
#include<unistd.h>

int cnt = 0;
void sig_handler(int sig_no)
{
	int count = ++cnt;
	printf("count: %d enter, sig_no: %d\n", count, sig_no);
	sleep(3);
	printf("count: %d leave, sig_no: %d\n", count, sig_no);
}

int main(void)
{
	char buf[8];
	int iret;
	signal(SIGINT, sig_handler);
	signal(SIGQUIT, sig_handler);

	do
	{
		iret = read(STDIN_FILENO, buf, sizeof(buf) - 1);
		if(-1 == iret)
		{
			perror("read error");
			exit(-1);
		}

		buf[iret] = '\0';
		puts(buf);
	}while(strcmp(buf, "quit\n"));

	return 0;
}
