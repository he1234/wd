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
	char buf[16] = {"---------------"};
	struct stat sb;
	char path2[1024];
	sprintf(path2, "%s/%s", get_current_dir_name(), path);
	if(-1==stat(path2,&sb))
	{
		perror("fstat failed");
		exit(EXIT_FAILURE);
	}
	mode_to_str(sb.st_mode,buf);
	printf("%s. %u %s %s %u %s %s",buf,sb.st_nlink,
			getpwuid(sb.st_uid)->pw_name,getgrgid(sb.st_gid)->gr_name,\
			sb.st_size,time_handle(ctime(&sb.st_mtime)),path);
	putchar(10);
}
static void mode_to_str(mode_t md,char* buf)
{
	switch(S_IFMT&md)
		{
			case S_IFREG:buf[0]='-'; break;
			case S_IFDIR:buf[0]='d'; break;
			case S_IFCHR:buf[0]='c'; break;
			case S_IFIFO:buf[0]='p'; break;
			case S_IFBLK:buf[0]='b'; break;
			case S_IFLNK:buf[0]='l'; break;
			case S_IFSOCK:buf[0]='s'; break;
			default:;
		}
	if(S_IRUSR&md) buf[1]='r';
	if(S_IWUSR&md) buf[2]='w';
	if(S_IXUSR&md) buf[3]='x';

	if(S_IRGRP&md) buf[4]='r';
	if(S_IWGRP&md) buf[5]='w';
	if(S_IXGRP&md) buf[6]='x';

	if(S_IROTH&md) buf[7]='r';
	if(S_IWOTH&md) buf[8]='w';
	if(S_IXOTH&md) buf[9]='x';
	buf[10]=0;
}
static char* time_handle(char* pt)
{
	pt[strlen(pt)-1]=0;
	return (pt+4);
}
