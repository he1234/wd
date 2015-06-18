/********************************************************************
	> File Name: ./main.c
	> Author: he_CentOS
	> Mail:1778195296@qq.com 
	> Created Time: 2015年02月06日 星期五 08时04分44秒
 *******************************************************************/

#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
int ticket_count=5;
sem_t lock;

void* sale_ticket_winds1(void* pargs)
{
	while(1)
	{
		sem_wait(&lock);
		if(ticket_count>0)
		{
			printf("windows1 start sale ticket!the ticket count is %d\n",ticket_count);
			sleep(3);
			ticket_count--;
			printf("the count of the ticket is %d now!\n",ticket_count);
		}
		else
		{
			sem_post(&lock);
			printf("sale out all! the count of the ticket is %d\n",ticket_count);
			pthread_exit(NULL);
		}
		sem_post(&lock);
		sleep(1);
	}
}

void* sale_ticket_winds2(void* pargs)
{
	while(1)
	{
		sem_wait(&lock);
		if(ticket_count>0)
		{
			printf("windows2 start sale ticket! the count of ticket is %d\n",ticket_count);
			sleep(3);
			ticket_count--;
			printf("the count of the ticket is %d\n",ticket_count);
		}
		else
		{
			sem_post(&lock);
			printf("sale out all! the count of the ticket is %d\n",ticket_count);
			pthread_exit(NULL);
		}
		sem_post(&lock);
		sleep(1);
	}
}
int main(int argc,char* argv[])
{
	pthread_t pth_id1=0,pth_id2=0;
	sem_init(&lock,0,1);
	pthread_create(&pth_id1,NULL,sale_ticket_winds1,NULL);
	pthread_create(&pth_id2,NULL,sale_ticket_winds2,NULL);
	pthread_join(pth_id1,NULL);
	pthread_join(pth_id2,NULL);
	sem_destroy(&lock);
	return 0;
}
