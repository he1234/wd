/********************************************************************
	> File Name: ./main.c
	> Author: he_CentOS
	> Mail:1778195296@qq.com 
	> Created Time: 2015年02月04日 星期三 08时28分49秒
 *******************************************************************/

#include<stdio.h>
#include<stdlib.h>

int main(int argc,char* argv[])
{
	int iret=system(argv[1]);
	printf("ret:%04x\n",iret);
	return 0;
}
