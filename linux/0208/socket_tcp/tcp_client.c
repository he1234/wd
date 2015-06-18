/********************************************************************
	> File Name: ./tcp_client.c
	> Author: he_CentOS
	> Mail:1778195296@qq.com 
	> Created Time: 2015年02月08日 星期日 21时13分08秒
 *******************************************************************/

#include "tcp.h"

int main(int argc,char* argv[])
{
	int sfd=tcp_connect();
	char buf[128];
	while(1)
	{
		memset(buf,0,sizeof(buf));
		if(-1==read(0,buf,sizeof(buf)))
		{
			perror("read");
			close(sfd);
			exit(1);
		}
		if(-1==send(sfd,buf,sizeof(buf),0))
		{
			perror("send");
			close(sfd);
			exit(1);
		}
		memset(buf,0,sizeof(buf));
		if(-1==recv(sfd,buf,sizeof(buf),0))
		{
			perror("recv");
			close(sfd);
			exit(1);
		}
		printf("from server:%s\n",buf);
	}
	close(sfd);
	return 0;
}
