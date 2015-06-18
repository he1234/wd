/********************************************************************
	> File Name: ./src/main.c
	> Author: he_CentOS
	> Mail:1778195296@qq.com 
	> Created Time: 2015年01月28日 星期三 04时59分15秒
 *******************************************************************/

#include "getcwd_chdir.h"
int main(int argc,char** argv)
{
	printf("%s\n",getcwd(NULL,0));
	chdir("/home/he/Desktop");
	printf("%s\n",getcwd(NULL,0));
	return 0;
}

