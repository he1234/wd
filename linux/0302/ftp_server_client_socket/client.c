/********************************************************************
	> File Name: ./client.c
	> Author: he_CentOS
	> Mail:1778195296@qq.com 
	> Created Time: 2015年03月02日 星期一 21时11分30秒
 *******************************************************************/

#include "client.h"

int main(int argc,char* argv[])
{
	int sfd_client=socket_init();
	printf("connect success!\n");
	char cmd[256];
	int send_len;
	while(memset(cmd,0,256),fgets(cmd,256,stdin)!=NULL)
	{
		send_len=strlen(cmd);
		send(sfd_client,(char*)&send_len,4,0);
		send_buf(sfd_client,cmd,send_len);
		if(0==strncmp("cd",cmd,2))
		{
			int dir_len;
			char dir[256]="";
			recv(sfd_client,(char*)&dir_len,sizeof(int),0);
			recv_buf(sfd_client,dir,dir_len);
			printf("%s\n",dir);
		}
		else if(0==strncmp("pwd",cmd,3))
		{
			char dir[256]="";
			int dir_len;
			recv(sfd_client,(char*)&dir_len,sizeof(int),0);
			recv_buf(sfd_client,dir,dir_len);
			printf("%s\n",dir);
		}
		else if(0==strncmp("ls",cmd,2))
		{
			int recv_len;
			char buf[256];
			while(1)
			{
				printf("-------------\n");
				recv(sfd_client,(char*)&recv_len,sizeof(int),0);
				printf("recv_len:%d\n",recv_len);
				if(0==recv_len)
				{
					break;
				}
				else if(-1==recv_len)
				{
					printf("opendir failure!\n");
					break;
				}
				bzero(buf,256);
				recv_buf(sfd_client,buf,recv_len);
				printf("%s\n",buf);
			}
		}
		else if(0==strncmp("gets",cmd,4))
		{
			char file_name[256];
			char name[256];
			int file_pos=5;
			int file_name_len;
			while(bzero(file_name,256),1==sscanf(cmd+file_pos,"%s",file_name))
			{
				file_name_len=strlen(file_name);
				file_pos+=file_name_len+1;
				//生成客户端下载文件存储路径
				memset(name,0,256);
				get_name(file_name,file_name_len,name);
				memset(file_name,0,256);
				sprintf(file_name,"%s/%s",DOWNLOAD_PATH,name);

				if(0==receive_from_server(sfd_client,file_name))
				{
					printf("receive from server :%s success!\n",file_name);
				}
				else
					printf("receive from server :%s failure!\n",file_name);
			}
		}
		else if(0==strncmp("puts",cmd,4))
		{
		}
		else if(0==strncmp("remove",cmd,6))
		{
		}
	}
	send_len=0;
	send(sfd_client,(char*)&send_len,4,0);
	close(sfd_client);
	return 0;
}
