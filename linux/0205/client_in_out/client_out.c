/********************************************************************
	> File Name: ./client_out.c
	> Author: he_CentOS
	> Mail:1778195296@qq.com 
	> Created Time: 2015年02月05日 星期四 09时08分23秒
 *******************************************************************/

#include "client.h"

int main(int argc,char* argv[])
{
	key_t shm_key,sem_key;
	int my_shm,my_sem;
	pMBUF p;
	char line[1024];

	shm_key=(key_t)atoi(argv[1]);
	sem_key=(key_t)atoi(argv[2]);

	my_shm=shmget(shm_key,sizeof(MBUF),0666);
	my_sem=semget(sem_key,1,0666);

	semctl(my_sem,0,SETVAL,1);
	p=(pMBUF)shmat(my_shm,NULL,0);

	while(1)
	{
		while(P(my_sem),p->m_flag==0)
		{
			V(my_sem);
			sleep(1);
		}
		memset(line,0,1024);
		strcpy(line,p->m_buf);
		printf("from client_in:%s\n",line);
		if(strcmp(line,"over")==0)
		{
			V(my_sem);
			break;
		}
		p->m_flag=0;
		V(my_sem);
	}
	
	shmdt(p);
	return 0;
}
