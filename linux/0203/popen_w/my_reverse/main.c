/********************************************************************
	> File Name: ./main.c
	> Author: he_CentOS
	> Mail:1778195296@qq.com 
	> Created Time: 2015年02月03日 星期二 22时16分21秒
 *******************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void handle(char *str)
{
	int bg,end;
	int tmp;
	bg=0;
	end=strlen(str)-1;
	while(bg<end)
	{
		tmp=str[bg];
		str[bg]=str[end];
		str[end]=tmp;
		bg++;
		end--;
	}
}
int main(int argc,char* argv[])
{
	char src[1024];
	while(memset(src,0,1024),gets(src)!=NULL)
	{
		handle(src);
		printf("pid:%d %s\n",getpid(),src);
	}
	return 0;
}
