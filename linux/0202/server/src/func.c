/********************************************************************
	> File Name: ./src/func.c
	> Author: he_CentOS
	> Mail:1778195296@qq.com 
	> Created Time: 2015年02月02日 星期一 04时56分45秒
 *******************************************************************/

#include "my_server.h"

void dispatch_msg(pCLIENT phead,char* msg)
{
	while(phead)
	{
		write(phead->m_send,msg,strlen(msg));
		phead=phead->m_next;
	}
}

