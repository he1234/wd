/********************************************************************
	> File Name: ./main.c
	> Author: he_CentOS
	> Mail:1778195296@qq.com 
	> Created Time: 2015年02月06日 星期五 08时04分44秒
 *******************************************************************/

#include<stdio.h>
#include<pthread.h>
int ticket_count=5;
pthread_mutex_t lock;
void* sale_ticket_winds1(void* pargs)
{
	while(1)
	{
		pthread_mutex_lock(&lock);
		if(ticket_count>0)
		{
			printf("windows1 start sale ticket!the ticket count is %d\n",ticket_count);
			sleep(3);
			ticket_count--;
			printf("the count of the ticket is %d now!\n",ticket_count);
		}
		else
		{
			pthread_mutex_unlock(&lock);
			printf("sale out all! the count of the ticket is %d\n",ticket_count);
			pthread_exit(NULL);
		}
		pthread_mutex_unlock(&lock);
		sleep(1);
	}
}

void* sale_ticket_winds2(void* pargs)
{
	while(1)
	{
		pthread_mutex_lock(&lock);
		if(ticket_count>0)
		{
			printf("windows2 start sale ticket! the count of ticket is %d\n",ticket_count);
			sleep(3);
			ticket_count--;
			printf("the count of the ticket is %d\n",ticket_count);
		}
		else
		{
			pthread_mutex_unlock(&lock);
			printf("sale out all! the count of the ticket is %d\n",ticket_count);
			pthread_exit(NULL);
		}
		pthread_mutex_unlock(&lock);
		sleep(1);
	}
}
int main(int argc,char* argv[])
{
	pthread_t pth_id1=0,pth_id2=0;
	pthread_mutex_init(&lock,NULL);
	pthread_create(&pth_id1,NULL,sale_ticket_winds1,NULL);
	pthread_create(&pth_id2,NULL,sale_ticket_winds2,NULL);
	pthread_join(pth_id1,NULL);
	pthread_join(pth_id2,NULL);
	pthread_mutex_destroy(&lock);
	return 0;
}
