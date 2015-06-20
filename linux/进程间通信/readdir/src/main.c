/********************************************************************
	> File Name: ./src/main.c
	> Author: he_CentOS
	> Mail:1778195296@qq.com 
	> Created Time: 2015年01月28日 星期三 17时28分57秒
 *******************************************************************/
#include "readdir.h"
int main(int argc,char* argv[])
{
	DIR *dir=opendir(argv[1]);
	struct dirent* pent;
	if(NULL==dir)
	{
		perror("open error!\n");
		exit(-1);
	}
	printf("OK!\n");
	while((pent=readdir(dir))!=NULL)
	{
		printf("%u %u %u %x %s\n",pent->d_ino,pent->d_off,pent->d_reclen,pent->d_type,pent->d_name);
		printf("----------------------------\n");
	}
	closedir(dir);
	return 0;
}
