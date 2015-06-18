/********************************************************************
	> File Name: ./client_in/main.c
	> Author: he_CentOS
	> Mail:1778195296@qq.com 
	> Created Time: 2015年02月04日 星期三 16时29分53秒
 *******************************************************************/

#include "client.h"

int main(int argc,char* argv[])
{
	key_t shm_key,sem_key;
	int my_shm,my_sem;//共享内存标识符，信号量标识符

	char line[1024];

	pMBUF p;
	shm_key=(key_t)atoi(argv[1]);
	sem_key=(key_t)atoi(argv[2]);

	my_shm=shmget(shm_key,sizeof(MBUF),0666|IPC_CREAT);
	my_sem=semget(sem_key,1,0666|IPC_CREAT);//1为信号量集数目

	semctl(my_sem,0,SETVAL,1);//0为第0个信号量，SETVAL表示用sumun中val成员设定信号量的值，并且在第一次使用前设置
	
	//共享内存标识符和内存地址建立映射关系
	p=(pMBUF)shmat(my_shm,NULL,0);//返回值为一个指针（指向共享内存首地址），
						//NULL表示让系统指定共享内存在当前进程中的地址
	memset(p,0,sizeof(MBUF));
	while(memset(line,0,1024),fgets(line,1024,stdin)!=NULL)
	{
		while(P(my_sem),p->m_flag==1)
		{//若client_out还没读，等待1秒钟
			V(my_sem);
			sleep(1);
		}
		strcpy(p->m_buf,line);
		p->m_flag=1;
		V(my_sem);
	}
	//当client_out读完后，client_in向它发送"over"表示结束
	while(P(my_sem),p->m_flag==1)
	{
		V(my_sem);
		sleep(1);
	}
	strcpy(p->m_buf,"over");
	p->m_flag=1;
	V(my_sem);
	sleep(3);

	shmdt(p);
	shmctl(my_shm,IPC_RMID,NULL);//表示删除共享内存段my_shm
	semctl(my_sem,0,IPC_RMID);//IPC_RMID表示删除信号量集，并唤醒所有进程
	return 0;
}
