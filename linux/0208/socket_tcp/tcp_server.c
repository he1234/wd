/********************************************************************
	> File Name: ./tcp_server.c
	> Author: he_CentOS
	> Mail:1778195296@qq.com 
	> Created Time: 2015年02月08日 星期日 21时12分54秒
 *******************************************************************/

#include "tcp.h"

int main(int argc,char* argv[])
{
	signal_handle();
	int sfd=ftp_init();
	int sfd_new=ftp_accept(sfd);
	char buf[128];
	int ret;
	while(1)
	{
		memset(buf,0,sizeof(buf));
		ret=recv(sfd_new,buf,sizeof(buf),0);
		if(-1==ret)
		{
			perror("recv");
			close(sfd);
			close(sfd_new);
			exit(1);
		}
		if(0==ret)
		{//如果客户端ctrl+c,ctrl+d,或者enter,即recv()没接收到字符
			break;
		}
		printf("from client:%s\n",buf);

		memset(buf,0,sizeof(buf));
		if(-1==read(0,buf,sizeof(buf)))
		{
			perror("read");
			close(sfd);
			close(sfd_new);
			exit(1);
		}
		if(-1==send(sfd_new,buf,sizeof(buf),0))
		{
			perror("send");
			close(sfd);
			close(sfd_new);
			exit(1);
		}
	}
	close(sfd);
	close(sfd_new);
	return 0;
}
