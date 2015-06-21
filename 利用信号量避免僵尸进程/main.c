/*************************************************************************
    > File Name: main.c
    > Author: 时中贺
    > Mail: shi_zhonghe@163.com 
    > Created Time: 2015年06月20日 星期六 20时01分43秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>

void sigchld_handler(int sig_no)
{
	int exit_status;
//	pid_t pid = wait(&exit_status);					//exit_status保存子进程的退出状态
//	pid_t pid = waitpid(-1, &exit_status, 0);		//-1表示等待任何进程，0表示阻塞
	pid_t pid = waitpid(-1, &exit_status, WNOHANG);	//WNOHANG表示非阻塞
	printf("sig_no: %d ,child %d exit !\n", sig_no, pid);
	if(WIFEXITED(exit_status))	//子进程正常结束，该宏返回非0值
	{
		printf("Child exited with code %d\n", WEXITSTATUS(exit_status));//如果WIFEXITED非零，宏WEXITSTATUS返回子进程的退出码,即返回123
	}
}

int main(void)
{
	signal(SIGCHLD, sigchld_handler);
	printf("parent process id %d\n", getpid());
	if(0 == fork())
	{
		exit(123);//退出码123,可在父进程中使用宏WEXITSTATUS和子进程退出状态得到
	}
	sleep(1);//确保子进程先退出
	return 0;
}
