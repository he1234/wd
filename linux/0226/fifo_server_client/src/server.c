/********************************************************************
	> File Name: ./src/server.c
	> Author: he_CentOS
	> Mail:1778195296@qq.com 
	> Created Time: 2015年02月26日 星期四 22时10分24秒
 *******************************************************************/

#include "my_server.h"
int main(int argc,char* argv[])
{
	int fd_listen;
	char path_name[128]="";
	char fifo_name[128];
	char msg[1024];
	
	char client_stat[5]="";
	int client_pid;

	sprintf(path_name,"%s/%s",PIPE_PATH,PATH_NAME);
	mkfifo(path_name,0666);
	printf("mkfifo over!\n");

	fd_listen=open(path_name,O_RDWR);
	if(fd_listen== -1)
	{
		printf("open server_fifo fail!\n");
		exit(1);
	}

	pCLIENT plist=NULL,ppre,pcur,pnew;
	fd_set rd_sets,bak_sets;
	FD_ZERO(&rd_sets);
	FD_ZERO(&bak_sets);
	FD_SET(fd_listen,&rd_sets);

	while(1)
	{
		bak_sets=rd_sets;
		printf("selecting...\n");
		select(1024,&bak_sets,NULL,NULL,NULL);
	}
}
