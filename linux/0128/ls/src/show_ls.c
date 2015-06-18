/********************************************************************
	> File Name: ./src/show_ls.c
	> Author: he_CentOS
	> Mail:1778195296@qq.com 
	> Created Time: 2015年01月28日 星期三 07时51分30秒
 *******************************************************************/
#include "ls.h"
static char* time_handle(char* pt);
static void mode_to_str(mode_t md,char *buf);
void show_ls(char* path)
{
	char buf[16];
	int fb=open(path,O_RDONLY);
	if(-1==fb)
	{
		perror("open failed!\n");
		exit(EXIT_FAILURE);
	}
	struct stat sb;
	if(-1==fstat(fb,&sb))
	{
		perror("fstat failed!\n");
		exit(EXIT_FAILURE);
	}
	mode_to_str(sb.st_mode,buf);
	printf("%s. %u %s %s %u %s %s",buf,sb.st_nlink,
			getpwuid(sb.st_uid)->pw_name,getgrgid(sb.st_gid)->gr_name,\
			sb.st_size,time_handle(ctime(&sb.st_mtime)),path);
	putchar(10);
	close(fb);
}
static void mode_to_str(mode_t md,char* buf)
{
	switch(S_IFMT&md)
		{
			case S_IFREG:
				buf[0]='-';
				break;
			case S_IFDIR:
				buf[0]='d';
				break;
			case S_IFCHR:
				buf[0]='c';
				break;
			case S_IFIFO:
				buf[0]='p';
				break;
			case S_IFBLK:
				buf[0]='b';
				break;
			case S_IFLNK:
				buf[0]='l';
				break;
			case S_IFSOCK:
				buf[0]='s';
				break;
			default:;
		}
	if(S_IRUSR&md)
		buf[1]='r';
	else
		buf[1]='_';

	if(S_IWUSR&md)
		buf[2]='w';
	else
		buf[2]='_';

	if(S_IXUSR&md)
		buf[3]='x';
	else
		buf[3]='_';
//////////////////////
	if(S_IRGRP&md)
		buf[4]='r';
	else
		buf[4]='_';

	if(S_IWGRP&md)
		buf[5]='w';
	else
		buf[5]='_';

	if(S_IXGRP&md)
		buf[6]='x';
	else
		buf[6]='_';
/////////////////////
	if(S_IROTH&md)
		buf[7]='r';
	else
		buf[7]='_';
	
	if(S_IWOTH&md)
		buf[8]='w';
	else
		buf[8]='_';

	if(S_IXOTH&md)
		buf[9]='x';
	else
		buf[9]='_';
	buf[10]=0;
}
static char* time_handle(char* pt)
{
	pt[strlen(pt)-1]=0;
	return (pt+4);
}
