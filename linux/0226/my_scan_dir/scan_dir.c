/********************************************************************
	> File Name: ./scan_dir.c
	> Author: he_CentOS
	> Mail:1778195296@qq.com 
	> Created Time: 2015年02月26日 星期四 20时22分59秒
 *******************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<dirent.h>
void scan_dir(char* path_name,int num);

int main(int argc,char* argv[])
{//见scan_dir.c文件注释
	scan_dir(argv[1],1);
	return 0;
}

void scan_dir(char* path_name,int num)
{
	struct dirent* pent;
	struct stat cur_stat;
	DIR* pdir=opendir(path_name);
	if(pdir==NULL)
	{
		perror("opendir");
		exit(1);
	}
	char cur_path[256]="";
	while((pent=readdir(pdir))!=NULL)
	{
		if(strcmp(".",pent->d_name)==0||strcmp("..",pent->d_name)==0)
			continue;
		memset(cur_path,0,sizeof(cur_path));
		sprintf(cur_path,"%s/%s",path_name,pent->d_name);
		memset(&cur_stat,0,sizeof(cur_stat));
		if(lstat(cur_path,&cur_stat)== -1)
		{
			perror("lstat");
			exit(1);
		}
		printf("%*s%s\n",num," ",pent->d_name);
		if(S_ISDIR(cur_stat.st_mode))
		{
			scan_dir(cur_path,num+5);
		}
	}
	closedir(pdir);
}
