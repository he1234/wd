#include "stat.h"
int main(int argc,char** argv)
{
	int fd=open("./data/a.txt",O_RDONLY);
	if(-1==fd)
	{
		perror("open failed!\n");
		exit(-1);
	}
	struct stat st_buf;
	if(-1==fstat(fd,&st_buf))
	{
		perror("stat fail");
		exit(-1);
	}
	putchar(10);
	switch(st_buf.st_mode&S_IFMT)
	{
		case S_IFBLK:
			printf("block device!\n");
			break;
		case S_IFDIR:
			printf("directory!\n");
			break;
		case S_IFREG:
			printf("regular file!\n");
			break;
		case S_IFLNK:
			printf("symlink!\n");
			break;
		case S_IFIFO:
			printf("FIFO/pipe!\n");
			break;
		case S_IFSOCK:
			printf("socket!\n");
		case S_IFCHR:
			printf("character device!\n");
			break;
		default:
			printf("unknown!\n");
	}
	printf("Inode ID is:%ld\nlink count is:%ld\n",(long)st_buf.st_ino,(long)st_buf.st_nlink);
	printf("mode:%lo\n",(unsigned long)st_buf.st_mode);
	printf("UID:%ld		GID:%ld\n",(long)st_buf.st_uid,(long)st_buf.st_gid);
	printf("preferred I/O block size:%ld bytes\n",(long)st_buf.st_blksize);
	printf("file size:%lld bytes\n",(long long)st_buf.st_size);
	printf("blocks allocated:	%lld\n",(long long)st_buf.st_blocks);
	printf("last status change:		%s\n",ctime(&st_buf.st_ctime));
	printf("last file modification:	%s\n",ctime(&st_buf.st_mtime));
	printf("last file access:		%s\n",ctime(&st_buf.st_atime));
	putchar(10);


	time_t tt=st_buf.st_atime;
	struct tm *pt=gmtime(&tt);
	printf("%4d-%02d-%02d		%2d:%2d:%2d\n",1990+pt->tm_year,\
			1+pt->tm_mon,pt->tm_mday,8+pt->tm_hour,pt->tm_min,pt->tm_sec);
	close(fd);
	exit(1);
}
