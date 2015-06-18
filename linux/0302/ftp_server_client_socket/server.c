/********************************************************************
	> File Name: server.c
	> Author: he_CentOS
	> Mail:1778195296@qq.com 
	> Created Time: 2015年03月02日 星期一 15时39分59秒
 *******************************************************************/

#include "server.h"

int main(int argc,char* argv[])
{
	signal(17,signal_handle);
	int sfd_listen=socket_init();
	int sfd_client;
	struct sockaddr_in client_addr;
	char buf_client_addr[16]="";
	int client_port;
	while(1)
	{

		memset(&client_addr,0,sizeof(struct sockaddr));
		sfd_client=socket_accept(sfd_listen,(struct sockaddr*)&client_addr);

		if(fork()==0)
		{
			close(sfd_listen);
			strcpy(buf_client_addr,inet_ntoa(client_addr.sin_addr));
			client_port=ntohs(client_addr.sin_port);
			printf("client %s:%d connect!\n",buf_client_addr,client_port);

			child_main(sfd_client);
			printf("client %s:%d disconnect!\n",buf_client_addr,client_port);
			close(sfd_client);
			exit(0);
		}
		close(sfd_client);
	}
	return 0;
}
