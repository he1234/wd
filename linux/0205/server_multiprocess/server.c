/********************************************************************
	> File Name: ./server.c
	> Author: he_CentOS
	> Mail:1778195296@qq.com 
	> Created Time: 2015年02月05日 星期四 10时16分37秒
 *******************************************************************/

#ifndef __SERVER_H__
#define __SERVER_H__
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<signal.h>
#define SERVER_FIFO_PATH "/home/he/Desktop/CODE/20150205/server_multiprocess/pipe"
#define SERVER_FIFO_NAME "server.fifo"
#endif

void child_handle(int sig_num)
{
	printf("one child exit!\n");
	wait(NULL);
}
void reverse_str(char* str)
{
	char tmp;
	int bg=0;
	int end=strlen(str)-1;
	while(bg<end)
	{
		tmp=str[bg];
		str[bg]=str[end];
		str[end]=tmp;
		bg++;
		end--;
	}
}
void child_main(int fd_r,int fd_w)
{
	char msg[1024];
	while(memset(msg,0,1024),read(fd_r,msg,1024)!=0)
	{
		reverse_str(msg);
		write(fd_w,msg,strlen(msg));
	}
}

int main(int argc,char* argv[])
{
	signal(17,child_handle);
	char path_fifo[128];
	char fifo_name[128];
	char client_read_path[128];
	char client_write_path[128];
	char line[32];
	pid_t client_pid;
	char client_stat[5];
	int fd_r,fd_w;
	
	sprintf(path_fifo,"%s/%s",SERVER_FIFO_PATH,SERVER_FIFO_NAME);
	mkfifo(path_fifo,0666);

	int fd_server=open(path_fifo,O_RDONLY);
	open(path_fifo,O_WRONLY);

	FILE* fp_server=fdopen(fd_server,"r");

	while(memset(line,0,32),fgets(line,32,fp_server)!=NULL)
	{
		write(1,line,strlen(line));
		sscanf(line,"%d %s",&client_pid,&client_stat);

		if(strcmp(client_stat,"on")==0)
		{
			memset(fifo_name,0,128);
			memset(client_write_path,0,128);

			sprintf(fifo_name,"%d_r.fifo",client_pid);
			sprintf(client_read_path,"%s/%s",SERVER_FIFO_PATH,fifo_name);

			memset(fifo_name,0,128);
			sprintf(fifo_name,"%d_w.fifo",client_pid);
			sprintf(client_write_path,"%s/%s",SERVER_FIFO_PATH,fifo_name);

			//
			fd_w=open(client_read_path,O_WRONLY);
			fd_r=open(client_write_path,O_RDONLY);

			if(fork()==0)
			{
				child_main(fd_r,fd_w);
				close(fd_r);
				close(fd_w);
				unlink(client_read_path);
				unlink(client_write_path);
				exit(1);
			}
			close(fd_r);
			close(fd_w);
		}
	}
	unlink(path_fifo);
	return 0;
}
