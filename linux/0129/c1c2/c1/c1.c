#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
int main(int argc,char* argv[])
{
	int fd_send=open(argv[2],O_WRONLY);
	int fd_recv=open(argv[1],O_RDONLY);
	if(fd_send==-1||fd_recv==-1)
	{
		perror("open");
		exit(1);
	}
	printf("OK!\n");
	char buf[1024];
	while(memset(buf,0,1024),read(fd_recv,buf,1024)!=0)
	{
		printf("from c1:%s\n",buf);
		memset(buf,0,1024);
		read(0,buf,1024);
		write(fd_send,buf,strlen(buf));
	}
	printf("c1 exit!\n");
	close(fd_send);
	close(fd_recv);
	return 0;
}
