/********************************************************************
	> File Name: ./client/client.c
	> Author: he_CentOS
	> Mail:1778195296@qq.com 
	> Created Time: 2015年02月01日 星期日 07时29分00秒
 *******************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>
#include<sys/select.h>
#include<sys/time.h>
#define PIPE_PATH "/home/he/Desktop/CODE/20150201/server/pipe"
#define PIPE_NAME "server.fifo"

int main(int argc,char* argv[])
{
	int fd_server;
	char path_name[128]="";
	char fifo_name[128];
	char msg[1024]="";
	int fd_recv,fd_send;
	//生成服务器管道路径，并以写的方式打开
	sprintf(path_name,"%s/%s",PIPE_PATH,PIPE_NAME);
	fd_server=open(path_name,O_WRONLY);
	if(fd_server== -1)
	{
		printf("open fail!\n");
		exit(1);
	}
	//pid_r.fifo pid_w.fifo
	//生成读管道
	memset(fifo_name,0,128);
	sprintf(fifo_name,"%u_r.fifo",getpid());
	memset(path_name,0,128);
	sprintf(path_name,"%s/%s",PIPE_PATH,fifo_name);
	if(-1==mkfifo(path_name,0666))
	{
		printf("mkfifo fail:%s\n",path_name);
		exit(1);
	}

	printf("%s open\n",path_name);
	//生成写管道
	memset(fifo_name,0,128);
	sprintf(fifo_name,"%u_w.fifo",getpid());
	memset(path_name,0,128);
	sprintf(path_name,"%s/%s",PIPE_PATH,fifo_name);
	if(-1==mkfifo(path_name,0666))
	{
		printf("mkfifo fail:%s\n",path_name);
		exit(1);
	}

	printf("%s open\n",path_name);
	printf("mkfifo over!\n");
	//打印客户端启动
	sprintf(msg,"%u on\n",getpid());
	printf("msg:%s\n",msg);
	//向服务器发送客户端启动信息
	write(fd_server,msg,strlen(msg));
	//以读方式打开读管道
	memset(fifo_name,0,128);
	sprintf(fifo_name,"%u_r.fifo",getpid());
	memset(path_name,0,sizeof(path_name));
	sprintf(path_name,"%s/%s",PIPE_PATH,fifo_name);

	fd_recv=open(path_name,O_RDONLY);
	//以写方式打开写管道
	memset(fifo_name,0,128);
	sprintf(fifo_name,"%u_w.fifo",getpid());
	memset(path_name,0,sizeof(path_name));
	sprintf(path_name,"%s/%s",PIPE_PATH,fifo_name);
	//打印管道打开成功
	fd_send=open(path_name,O_WRONLY);
	printf("fifo open %d %d\n",fd_send,fd_recv);

	fd_set rd_sets;
	FD_ZERO(&rd_sets);
	while(1)
	{
		//把标准输入、读管道描述符加入读监听集合
		FD_SET(0,&rd_sets);
		FD_SET(fd_recv,&rd_sets);
		//监听
		printf("selecting...\n");
		select(1024,&rd_sets,NULL,NULL,NULL);

		if(FD_ISSET(0,&rd_sets))
		{//若标准输入缓存区有数据，可读
			//读取输入缓存区信息
			memset(msg,0,sizeof(msg));
			sprintf(msg,"from %u:",getpid());
			
			if(0==read(0,msg+strlen(msg),1024-strlen(msg)))
			{//若从键盘输入了正常退出命令：ctrl d
				printf("off!\n");
				//向服务器发出退出信号
				memset(msg,0,sizeof(msg));
				sprintf(msg,"%d off\n",getpid());
				write(fd_server,msg,strlen(msg));
				//关闭文件描述符
				close(fd_send);
				close(fd_recv);
				//删除读管道
				memset(fifo_name,0,128);
				sprintf(fifo_name,"%u_r.fifo",getpid());
				memset(path_name,0,128);
				sprintf(path_name,"%s/%s",PIPE_PATH,fifo_name);
				unlink(path_name);
				//删除写管道
				memset(fifo_name,0,128);
				sprintf(fifo_name,"%u_w.fifo",getpid());
				memset(path_name,0,128);
				sprintf(path_name,"%s/%s",PIPE_PATH,fifo_name);
				unlink(path_name);
				printf("delete fifo over!\n");
				break;
			}
			else//把标准输入缓存区中的信息发往服务器
				write(fd_send,msg,strlen(msg));
		}

		if(FD_ISSET(fd_recv,&rd_sets))
		{//若服务器发来信息
			//读取信息，并输出
			memset(msg,0,sizeof(msg));
			read(fd_recv,msg,1024);
			write(1,msg,strlen(msg));
		}
	}
	return 0;
}
