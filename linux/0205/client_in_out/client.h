/********************************************************************
	> File Name: ./client.h
	> Author: he_CentOS
	> Mail:1778195296@qq.com 
	> Created Time: 2015年02月05日 星期四 08时29分37秒
 *******************************************************************/
#ifndef __CLIENT_H__
#define __CLIENT_H__

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<sys/sem.h>
typedef struct tag
{
	int m_flag;
	char m_buf[1024];
}MBUF,*pMBUF;
void P(int semid);
void V(int semid);

#endif
