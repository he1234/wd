/********************************************************************
	> File Name: ./func/func.c
	> Author: he_CentOS
	> Mail:1778195296@qq.com 
	> Created Time: 2015年02月04日 星期三 20时29分38秒
 *******************************************************************/

#include "client.h"

void P(int semid)
{
	struct sembuf my_buf;
	memset(&my_buf,0,sizeof(my_buf));
	my_buf.sem_num=0;
	my_buf.sem_op= -1;
	my_buf.sem_flg=SEM_UNDO;
	semop(semid,&my_buf,1);
}

void V(int semid)
{
	struct sembuf my_buf;
	memset(&my_buf,0,sizeof(my_buf));
	my_buf.sem_num=0;
	my_buf.sem_op=1;
	my_buf.sem_flg=SEM_UNDO;
	semop(semid,&my_buf,1);
}
