/********************************************************************
	> File Name: ./src/main.c
	> Author: he_CentOS
	> Mail:1778195296@qq.com 
	> Created Time: 2015年01月28日 星期三 06时35分25秒
 *******************************************************************/

#include "dup2.h"
int main(int argc,char** argv)
{	//比较fdb两次的输出情况，dup2重定位
	char buf[32]={0};
	int fda=open("./data/a.txt",O_RDONLY);
	int fdb=open("./data/b.txt",O_RDONLY);
	if(-1==fda||-1==fdb)
	{
		perror("open error!\n");
		exit(-1);
	}
	printf("fda:%d	fdb:%d\n",fda,fdb);
	read(fdb,buf,sizeof(buf)-1);
	puts(buf);
	memset(buf,0,sizeof(buf));
	int fdc=dup(fdb);
	if(-1==fdc)
	{
		perror("open error!\n");
		exit(-1);
	}
	dup2(fda,fdb);//内核先把fdb关闭，然后再对fdb重定位
	printf("fda:%d	fdb:%d	fdc:%d\n",fda,fdb,fdc);
	read(fdb,buf,sizeof(buf)-1);
	puts(buf);
	close(fda);
	close(fdb);
	close(fdc);
	return 0;
}
