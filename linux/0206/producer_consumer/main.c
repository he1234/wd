/********************************************************************
	> File Name: ./main.c
	> Author: he_CentOS
	> Mail:1778195296@qq.com 
	> Created Time: 2015年02月06日 星期五 17时25分01秒
 *******************************************************************/

#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
static pthread_mutex_t lock=PTHREAD_MUTEX_INITIALIZER;
static pthread_cond_t cond=PTHREAD_COND_INITIALIZER;
struct node
{
	int m_number;
	struct node *m_next;
}*head=NULL;

void* cleanup_handler(void* str)
{
	printf("Cleanup handler of second thread!\n");
	free(str);
	pthread_mutex_unlock(&lock);
}
void* pthread_func(void* pargs)
{//消费者
	struct node *p=(struct node*)calloc(1,sizeof(struct node));
	pthread_cleanup_push(cleanup_handler,p);
	while(1)
	{
		pthread_mutex_lock(&lock);
		if(head==NULL)
		{
			pthread_cond_wait(&cond,&lock);
		}
		p=head;
		head=head->m_next;
		printf("Got %d form front of queue\n",p->m_number);
		free(p);
		pthread_mutex_unlock(&lock);
	}
	pthread_cleanup_pop(0);
	pthread_exit(NULL);
}
int main(int argc,char* argv[])
{
	int i=0;
	struct node *p;
	pthread_t pth_id;
	pthread_create(&pth_id,NULL,pthread_func,NULL);
	for(;i<10;i++)
	{//生产者
		p=(struct node*)calloc(1,sizeof(struct node));
		p->m_number=i;
		pthread_mutex_lock(&lock);
		p->m_next=head;
		head=p;
		pthread_mutex_unlock(&lock);
		pthread_cond_signal(&cond);
		sleep(1);
	}
	pthread_cancel(pth_id);
	pthread_join(pth_id,NULL);
	pthread_mutex_destroy(&lock);
	pthread_cond_destroy(&cond);
	return 0;
}
