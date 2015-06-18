/********************************************************************
	> File Name: ./include/my_server.h
	> Author: he_CentOS
	> Mail:1778195296@qq.com 
	> Created Time: 2015年02月01日 星期日 06时01分03秒
 *******************************************************************/
#ifndef __SER_H__
#define __SER_H__
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
typedef struct tag
{
	int m_id;
	int m_send;
	int m_recv;
	struct tag* m_next;
}CLIENT,*pCLIENT;
void dispatch_msg(pCLIENT phead,char* msg);
#endif
