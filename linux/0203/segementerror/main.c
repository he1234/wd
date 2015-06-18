/********************************************************************
	> File Name: ./main.c
	> Author: he_CentOS
	> Mail:1778195296@qq.com 
	> Created Time: 2015年02月03日 星期二 10时05分38秒
 *******************************************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct tag
{
	int id;
	struct tag *next;
}node,*pnode;

void init(pnode *head)
{
	printf("%x\n",head);//结果为0
	printf("---------------------\n");
	printf("%x\n",*head);//没有结果，*head不存在
	*head=(pnode)calloc(1,sizeof(node));
	(*head)->id=getpid();
}
int main(int argc,char *argv[])
{//注释部分为正确代码，然后把27，28行注释掉
	pnode *p=NULL;
	init(p);
//	pnode p=NULL;
//	init(&p);
//	printf("%d\n",p->id);
	return 0;
}
