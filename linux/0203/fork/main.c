/********************************************************************
	> File Name: ./main.c
	> Author: he_CentOS
	> Mail:1778195296@qq.com 
	> Created Time: 2015年02月03日 星期二 19时15分31秒
 *******************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>

int main(int argc,char* argv[])
{//fork一个子进程，父进程给子进程发数据，通过gets,fputs,文件流
	//见今天另外一个代码，通过read,write,文件描述符
	int fds[2];
	pipe(fds);
	pid_t pid;
	pid=fork();
	if(pid>0)
	{
		close(fds[0]);
		char buf[1024];
		FILE* fp_out=fdopen(fds[1],"w");
//		close(fds[1]);	//用fdopen打开fds[1]时，不能立马把fd[1]关掉，可能fdopen会调用fds[1];
		while(memset(buf,0,1024),fgets(buf,1024,stdin)!=NULL)
		{
			fputs(buf,fp_out);
			fflush(fp_out);
			printf("fputs over!\n");
			fputs(buf,fp_out);
			fflush(fp_out);
		}
		printf("waiting...!\n");
		wait(NULL);
		printf("wait return!\n");
		fclose(fp_out);
	}
	else if(pid==0)
	{
		close(fds[1]);
		char recv_buf[1024];
		FILE* fp_in=fdopen(fds[0],"r");
//		close(fds[0]);
		while(memset(recv_buf,0,1024),fgets(recv_buf,1024,fp_in)!=NULL)
		{
			printf("from parent:%s\n",recv_buf);
		}
		fclose(fp_in);
	}
	return 0;
}
