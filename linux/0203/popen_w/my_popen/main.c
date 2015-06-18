/********************************************************************
	> File Name: ./main.c
	> Author: he_CentOS
	> Mail:1778195296@qq.com 
	> Created Time: 2015年02月03日 星期二 22时25分16秒
 *******************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc,char* argv[])
{//见今天代码popen1
	//通过argv[1],cmd传输my_reverse可执行文件的路径
	//popen创建子进程，并以写的方式与子进程建立管道
	printf("pid:%d\n",getpid());
	FILE* fp_out;
	char cmd[1024];
	char str[1024];
	fp_out=popen(argv[1],"w");
	if(fp_out==NULL)
	{
		perror("popen");
		exit(1);
	}
	while(memset(str,0,1024),fgets(str,1024,stdin)!=NULL)
	{
		fputs(str,fp_out);
		fflush(fp_out);//清空文件，立即刷新结果
	}
	pclose(fp_out);
	return 0;
}
