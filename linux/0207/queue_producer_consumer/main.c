/********************************************************************
	> File Name: ./main.c
	> Author: he_CentOS
	> Mail:1778195296@qq.com 
	> Created Time: 2015年02月07日 星期六 08时48分54秒
 *******************************************************************/

#include<stdio.h>
#include<pthread.h>
#include<string.h>
#include<stdlib.h>
#define LEN 128

typedef struct task_que
{
	char** m_que;
	int m_flag;//为1表示结束
	int m_capacity;
	int m_size;
	int m_front,m_tail;
	pthread_mutex_t m_lock;
	pthread_cond_t m_pro,m_con;
}QUE,*pQUE;

void* thd_func(void* arg);
void put(pQUE pq,char* src);
void get(pQUE pq,char* dest);

int main(int argc,char* argv[])
{
	QUE aque;
	int nthds=atoi(argv[1]);//线程总数
	aque.m_capacity=atoi(argv[2]);//队列容量
	//队列分配空间
	aque.m_que=(char**)calloc(aque.m_capacity,sizeof(char*));
	int i=0;
	for(;i<aque.m_capacity;i++)
	{
		aque.m_que[i]=(char*)calloc(LEN,sizeof(char));
	}
	//当前队列初始化
	aque.m_flag=0;
	aque.m_size=0;
	aque.m_front=0;
	aque.m_tail= -1;
	//互斥量初始化
	pthread_mutex_init(&aque.m_lock,NULL);
	pthread_cond_init(&aque.m_pro,NULL);
	pthread_cond_init(&aque.m_con,NULL);
	//线程ID数组
	pthread_t pthread_arr[nthds];
	for(i=0;i<nthds;i++)
	{
		pthread_create(&pthread_arr[i],NULL,thd_func,(void*)&aque);
	}
	
	char buf[LEN];
	while(memset(buf,0,LEN),gets(buf)!=NULL)
	{
		if(strlen(buf)==0)//防止输入enter键
			continue;
		put(&aque,buf);
	}
	strcpy(buf,"over");
	put(&aque,buf);
	//回收线程
	int nret[nthds];
	for(i=0;i<nthds;i++)
	{
		pthread_join(pthread_arr[i],(void**)&nret[i]);
	}
	//打印每个线程抢到的任务数量
	for(i=0;i<nthds;i++)
	{
		printf("%d	",nret[i]);
	}
	putchar(10);
	//后续工作
	pthread_mutex_destroy(&aque.m_lock);
	pthread_cond_destroy(&aque.m_pro);
	pthread_cond_destroy(&aque.m_con);
	return 0;
}

void* thd_func(void* arg)
{
	pQUE pq=(pQUE)arg;
	char buf[LEN];
	int ncnt=0;//该线程抢到的任务数量

	while(1)
	{
		memset(buf,0,LEN);
		get(pq,buf);
		if(buf[0]==0)
		{//如果任务结束，向所有线程发出信号
			pthread_cond_broadcast(&pq->m_con);
			printf("%u exit!\n",pthread_self());
			pthread_exit((void*)ncnt);
		}
		//如果收到字符串
		ncnt++;
		printf("%u: %s\n", pthread_self(), buf);
		//如果收到最后一个字符串，向所有线程发出信号
		if(strcmp(buf,"over")==0)
		{
			pq->m_flag=1;//任务结束标记
			pthread_cond_broadcast(&pq->m_con);
			pthread_exit((void*)ncnt);
		}
	}
}
void put(pQUE pq,char* src)
{//从队尾入队
	pthread_mutex_lock(&pq->m_lock);
	//必须用while，不能用if，防止其它线程修改pq->m_size，使之重新等于pq->m_capacity
	while(pq->m_size==pq->m_capacity)
	{
		pthread_cond_wait(&pq->m_pro,&pq->m_lock);
	}
	//尾部标记加1
	pq->m_tail=(pq->m_tail+1)%pq->m_capacity;
	strcpy(pq->m_que[pq->m_tail],src);
	pq->m_size++;
	pthread_mutex_unlock(&pq->m_lock);
	pthread_cond_broadcast(&pq->m_con);
}
void get(pQUE pq,char* dest)
{//从队首出队
	pthread_mutex_lock(&pq->m_lock);
	//亦必须用while，不能用if
	while(pq->m_size==0&&pq->m_flag==0)
		pthread_cond_wait(&pq->m_con,&pq->m_lock);
	//上一句可能接收到任务结束信号，此时任务结束标记等于1，所以加个判断语句
	if(pq->m_flag==1)
	{
		dest[0]=0;
		pthread_mutex_unlock(&pq->m_lock);
		return;
	}
	//出队操作
	strcpy(dest,pq->m_que[pq->m_front]);
	pq->m_size--;
	pq->m_front=(pq->m_front+1)%pq->m_capacity;
	pthread_mutex_unlock(&pq->m_lock);
	//发出可以继续入队信号
	pthread_cond_signal(&pq->m_pro);
}
