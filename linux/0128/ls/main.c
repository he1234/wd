/********************************************************************
	> File Name: ./src/main.c
	> Author: he_CentOS
	> Mail:1778195296@qq.com 
	> Created Time: 2015年01月28日 星期三 07时23分33秒
 *******************************************************************/

#include "ls.h"
int main(int argc,char* argv[])
{
	DIR *fp_dir=opendir(argv[1]);
	struct dirent* pent;
	if(NULL==fp_dir)
	{
		perror("open error");
		exit(-1);
	}
	chdir(argv[1]);
	while((pent=readdir(fp_dir))!=NULL)
	{
		show_ls(pent->d_name);
	}
	closedir(fp_dir);
	return 0;
}
