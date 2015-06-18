/********************************************************************
	> File Name: ./src/server.c
	> Author: he_CentOS
	> Mail:1778195296@qq.com 
	> Created Time: 2015年02月01日 星期日 06时00分10秒
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
	
	//打开服务器管道
	sprintf(path_name,"%s/%s",PIPE_PATH,PIPE_NAME);
	mkfifo(path_name,0666);
	printf("mkfifo over!\n");

	fd_listen=open(path_name,O_RDWR);//防止客户端全部退出时，服务器无限循环，阻塞
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
		if(FD_ISSET(fd_listen,&bak_sets))//若发生读变化
		{
			//接收信息，处理信息
			memset(msg,0,1024);
			if(0==read(fd_listen,msg,1024))
			{
				printf("no client!\n");
				continue;
			}
			memset(client_stat,0,5);
			sscanf(msg,"%d%s",&client_pid,&client_stat);
			
			//若客户端启动
			if(strncmp("on",client_stat,2)==0)
			{
				printf("client:%d on\n",client_pid);
				//生成fifo路径(写)
				memset(fifo_name,0,128);
				sprintf(fifo_name,"%d_r.fifo",client_pid);
				memset(path_name,0,128);
				sprintf(path_name,"%s/%s",PIPE_PATH,fifo_name);
				//生成服务器链表结点
				pnew=(pCLIENT)calloc(1,sizeof(CLIENT));
				pnew->m_id=client_pid;
				printf("pid_r.fifo:%s\n",path_name);
				pnew->m_send=open(path_name,O_WRONLY);
				printf("send_fd:%d\n",pnew->m_send);
				//生成fifo路径(读)
				memset(fifo_name,0,128);
				sprintf(fifo_name,"%d_w.fifo",client_pid);
				memset(path_name,0,128);
				sprintf(path_name,"%s/%s",PIPE_PATH,fifo_name);
				
				printf("pid_w.fifo:%s\n",path_name);
				pnew->m_recv=open(path_name,O_RDONLY);
				printf("recv_fd:%d\n",pnew->m_recv);
				printf("open client fifo:%d,%d\n",pnew->m_send,pnew->m_recv);
				//把新结点(新启动的客户端）放入读监听集合
				FD_SET(pnew->m_recv,&rd_sets);
				//以头插法把新结点放入链表
				pnew->m_next=plist;
				plist=pnew;
			}
			else//client off "pid off\n"
			{
				printf("client:%d off\n",client_pid);
				//在链表中找到要退出的客户端
				ppre=NULL;
				pcur=plist;
				while(pcur&&pcur->m_id!=client_pid)
				{
					ppre=pcur;
					pcur=pcur->m_next;
				}
				//若不存在此客户端，报告错误并继续运行
				if(pcur==NULL)
				{
					printf("error:not exist!\n");
					continue;
				}
				//客户端存在
				else
				{
					//若此客户端是第一个结点，就修改头结点
					if(ppre==NULL)
					{
						plist=pcur->m_next;
					}
					//若是中间结点，修改前驱结点，删除pcur结点
					else
					{
						ppre->m_next=pcur->m_next;
					}
					//关闭当前结点文件描述符
					close(pcur->m_send);
					close(pcur->m_recv);
					//把文件描述符从读监听删除
					FD_CLR(pcur->m_recv,&rd_sets);
					//释放结点
					free(pcur);
					printf("clear ok!\n");
				}
			}
		}
		//对服务器链表进行遍历，找出有读变化的结点
		pcur=plist;
		while(pcur)
		{
			if(FD_ISSET(pcur->m_recv,&bak_sets))
			{//若当前结点有读变化，读取信息，并发送信息
				memset(msg,0,1024);
				read(pcur->m_recv,msg,1024);
				//把该信息向每个客户端都发送一遍
				dispatch_msg(plist,msg);
			}
			pcur=pcur->m_next;
		}
	}
	return 0;
}

