/********************************************************************
	> File Name: ./client/client.c
	> Author: he_CentOS
	> Mail:1778195296@qq.com 
	> Created Time: 2015年02月02日 星期一 05时07分36秒
 *******************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<sys/select.h>
#include<sys/time.h>
#include<unistd.h>
#define PIPE_PATH "/home/he/Desktop/CODE/20150202/server/pipe"
#define PIPE_NAME "server.fifo"
int main(int argc,char* argv[])
{
	char pipe_name[128];
	char path_name[128];
	char msg[1024];
	int fd_read,fd_write;
	int fd_server;

	memset(path_name,0,128);
	sprintf(path_name,"%s/%s",PIPE_PATH,PIPE_NAME);

	fd_server=open(path_name,O_WRONLY);
	if(fd_server== -1)
	{
		printf("open fail!\n");
		exit(1);
	}

	memset(pipe_name,0,128);
	sprintf(pipe_name,"%u_w.fifo",getpid());
	memset(path_name,0,128);
	sprintf(path_name,"%s/%s",PIPE_PATH,pipe_name);

	if(-1==mkfifo(path_name,0666))
	{
		printf("mkfifo fail:%s\n",path_name);
		exit(1);
	}

	printf("%s open\n",path_name);

	memset(pipe_name,0,128);
	sprintf(pipe_name,"%u_r.fifo",getpid());
	memset(path_name,0,128);
	sprintf(path_name,"%s/%s",PIPE_PATH,pipe_name);
	if(-1==mkfifo(path_name,0666))
	{
		printf("mkfifo fail:%s\n",path_name);
		exit(1);
	}
	
	printf("%s open\n",path_name);
	printf("mkfifo over!\n");
	
	memset(msg,0,1024);
	sprintf(msg,"%u on\n",getpid());
	printf("msg:%s\n",msg);

	write(fd_server,msg,strlen(msg));
	
	memset(pipe_name,0,128);
	sprintf(pipe_name,"%u_w.fifo",getpid());
	memset(path_name,0,128);
	sprintf(path_name,"%s/%s",PIPE_PATH,pipe_name);

	fd_write==open(path_name,O_WRONLY);
	memset(pipe_name,0,128);
	sprintf(pipe_name,"%u_r.fifo",getpid());
	memset(path_name,0,128);
	sprintf(path_name,"%s/%s",PIPE_PATH,pipe_name);
	fd_read=open(path_name,O_RDONLY);

	printf("fifo open %d %d\n",fd_read,fd_write);
	
	fd_set read_sets,bak_sets;
	FD_ZERO(&read_sets);
	FD_SET(fd_read,&read_sets);
	FD_SET(0,&read_sets);
	
	while(1)
	{
		bak_sets=read_sets;
		printf("select...\n");
		select(1024,&read_sets,NULL,NULL,NULL);

			if(FD_ISSET(0,&bak_sets))
			{
				memset(msg,0,1024);
				sprintf(msg,"from %u:",getpid());
				if(0==read(0,msg+strlen(msg),1024-strlen(msg)))
				{
					printf("off!\n");
					memset(msg,0,1024);
					sprintf(msg,"%u off",getpid());
					write(fd_write,msg,strlen(msg));

					close(fd_read);
					close(fd_write);

					memset(pipe_name,0,128);
					sprintf(pipe_name,"%u_r.fifo",getpid());
					memset(path_name,0,128);
					sprintf(path_name,"%s/%s",PIPE_PATH,pipe_name);

					unlink(path_name);//delete fifo

					memset(pipe_name,0,128);
					sprintf(pipe_name,"%u_w.fifo",getpid());
					memset(path_name,0,128);
					sprintf(path_name,"%s/%s",PIPE_PATH,pipe_name);

					unlink(path_name);
					printf("clear OK!\n");
					break;
				}
				write(fd_write,msg,strlen(msg));
			}
			if(FD_ISSET(fd_read,&bak_sets))
			{
				memset(msg,0,1024);
				read(fd_read,msg,1024);
				write(1,msg,strlen(msg));
			}
	}
//	return 0;
}
