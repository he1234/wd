/********************************************************************
	> File Name: ./my_reverse.c
	> Author: he_CentOS
	> Mail:1778195296@qq.com 
	> Created Time: 2015年02月03日 星期二 21时13分44秒
 *******************************************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

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
	strcpy(src,argv[1]);
	handle(src);
	printf("%s\n",src);
	return 0;
}
