/********************************************************************
	> File Name: ./src/func.c
	> Author: he_CentOS
	> Mail:1778195296@qq.com 
	> Created Time: 2015年02月01日 星期日 07时22分27秒
 *******************************************************************/

#include "my_server.h"
void dispatch_msg(pCLIENT phead,char* msg)
{//把信息向每个客户端发送一次
	while(phead)
	{
		write(phead->m_send,msg,strlen(msg));
		phead=phead->m_next;
	}
}
