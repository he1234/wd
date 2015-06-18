/********************************************************************
	> File Name: ./scan_dir.c
	> Author: he_CentOS
	> Mail:1778195296@qq.com 
	> Created Time: 2015年02月26日 星期四 17时37分48秒
 *******************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<dirent.h>
#include<sys/stat.h>
#include<unistd.h>
#include<string.h>


void scan_dir(char* dir,int num);

int main(int argc,char* argv[])
{//argv[1]为要扫描的文件路径
	scan_dir(argv[1],1);
	return 0;
}

void scan_dir(char* dir,int num)
{//递归扫描文件
	//num控制打印的文件名的缩进大小
	DIR* pdir=opendir(dir);
	char name[128]="";
	if(pdir==NULL)
	{
		perror("opendir");
		exit(1);
	}
	struct dirent* pent;
	struct stat mystat;
	while( ( pent = readdir(pdir))!=NULL )
	{
		if(strcmp(".",pent->d_name)==0 || strcmp("..",pent->d_name)==0)
			continue;
		memset(name,0,128);
		sprintf(name,"%s/%s",dir,pent->d_name);
		memset(&mystat,0,sizeof(mystat));
		if(lstat(name,&mystat)== -1)//注意lstat和stat的区别：lstat会得到符号链接本身的信息，stat会得到符号链接指向的内容
		{
			perror("lstat");
			exit(1);
		}
		printf("%*s%s\n",num," ",pent->d_name);//打印文件信息
		if(S_ISDIR(mystat.st_mode))
		{//如果是目录，递归扫描目录
			scan_dir(name,num+5);
		}
	}
	closedir(pdir);
}
