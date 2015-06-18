/********************************************************************
	> File Name: src/server.c
	> Author: he_CentOS
	> Mail:1778195296@qq.com 
	> Created Time: 2015年02月01日 星期日 22时22分29秒
 *******************************************************************/

#include "my_server.h"

int main(int argc,char* argv[])
{
	char pipe_name[128];
	char path_name[128];
	char msg[1024];

	int client_pid;
	char client_stat[8];

	pCLIENT plist=NULL,pnew,ppre,pcur;

	memset(path_name,0,128);
	sprintf(path_name,"%s/%s",PIPE_PATH,PIPE_NAME);
	mkfifo(path_name,0666);
	printf("server.fifo is OK!\n");

	int fd_listen=open(path_name,O_RDWR);
	if(fd_listen== -1)
	{
		printf("open server.fifo error!\n");
		exit(1);
	}
	printf("server.fifo OK!\n");

	fd_set fd_read,fd_bak;
	FD_ZERO(&fd_read);
	FD_SET(fd_listen,&fd_read);
	while(1)
	{
		fd_bak=fd_read;
		
		printf("selecting...\n");
		select(1024,&fd_bak,NULL,NULL,NULL);

		if(FD_ISSET(fd_listen,&fd_bak))
		{
			memset(msg,0,1024);
			if(0==read(fd_listen,msg,1024))
			{
				printf("no client");
				continue;
			}
			
			memset(client_stat,0,8);
			sscanf(msg,"%d %s",&client_pid,&client_stat);

			if(strncmp("on",client_stat,2)==0)//on
			{
				printf("client:%d on\n",client_pid);
				pnew=(pCLIENT)calloc(1,sizeof(CLIENT));
				pnew->m_id=client_pid;
				
				memset(pipe_name,0,128);
				sprintf(pipe_name,"%d_r.fifo",client_pid);
				memset(path_name,0,128);
				sprintf(path_name,"%s/%s",PIPE_PATH,pipe_name);
				pnew->m_send=open(path_name,O_WRONLY);

				memset(pipe_name,0,128);
				sprintf(pipe_name,"%d_w.fifo",client_pid);
				memset(path_name,0,128);
				sprintf(path_name,"%s/%s",PIPE_PATH,pipe_name);
				pnew->m_recv=open(path_name,O_RDONLY);
				
				pnew->m_next=plist;
				plist=pnew;
				FD_SET(pnew->m_recv,&fd_read);
				printf("add node OK!\n");
			}
			else//off
			{
				printf("client:%d off\n",client_pid);
				ppre=NULL;
				pcur=plist;
				while(pcur&&pcur->m_id!=client_pid)
				{
					ppre=pcur;
					pcur=pcur->m_next;
				}
				if(pcur==NULL)
				{
					printf("error:not exist!\n");
					continue;
				}
				else
				{
					if(ppre==NULL)
					{
						plist=pcur->m_next;
					}
					else
					{
						ppre->m_next=pcur->m_next;
					}
					close(pcur->m_recv);
					close(pcur->m_send);

					FD_CLR(pcur->m_recv,&fd_read);
					free(pcur);
					printf("clear OK!\n");
				}
			}
		}
		pcur=plist;
		while(pcur)
		{
			if(FD_ISSET(pcur->m_recv,&fd_bak))
			{
				memset(msg,0,1024);
				read(pcur->m_recv,msg,1024);
				dispatch_msg(plist,msg);
			}
			pcur=pcur->m_next;
		}
	}
	return 0;
}
