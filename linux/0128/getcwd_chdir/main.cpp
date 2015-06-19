/*************************************************************************
    > File Name: main.cpp
    > Author: 时中贺
    > Mail: shi_zhonghe@163.com 
    > Created Time: 2015年06月19日 星期五 18时27分29秒
 ************************************************************************/

#include<unistd.h>
#include<stdio.h>
int main(void)
{
	printf("%s\n", getcwd(NULL, 0));
	chdir("/home/he/Desktop");
	printf("%s\n", getcwd(NULL, 0));
	printf("%s\n", get_current_dir_name());

	return 0;
}
