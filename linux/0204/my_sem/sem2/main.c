/********************************************************************
	> File Name: ./sem2/main.c
	> Author: he_CentOS
	> Mail:1778195296@qq.com 
	> Created Time: 2015年02月04日 星期三 16时15分42秒
 *******************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/sem.h>

void P(int semid)
{
	struct sembuf my_buf;
	memset(&my_buf,0,sizeof(my_buf));
	my_buf.sem_num=0;
	my_buf.sem_op=-1;
	my_buf.sem_flg=SEM_UNDO;
	semop(semid,&my_buf,1);
}

void V(int semid)
{

	struct sembuf my_buf;
	memset(&my_buf,0,sizeof(my_buf));
	my_buf.sem_num=0;
	my_buf.sem_op=1;
	my_buf.sem_flg=SEM_UNDO;//SEM_UNDO表示当进程终结时，自动撤销
	semop(semid,&my_buf,1);//1为my_buf结构体数组的大小
}

int main(int argc,char* argv[])
{
	key_t my_key=1234;
	int my_sem;
	my_sem=semget(my_key,1,0666);
	if(my_sem== -1)
	{
		perror("semget");
		exit(1);
	}
	printf("getval:%d\n",semctl(my_sem,0,GETVAL));
	
	printf("P...!\n");
	P(my_sem);
	printf("hello world!\n");
	V(my_sem);

	return 0;
}
