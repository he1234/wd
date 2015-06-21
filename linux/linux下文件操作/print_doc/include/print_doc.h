/********************************************************************
	> File Name: ./include/print_doc.h
	> Author: he_CentOS
	> Mail:1778195296@qq.com 
	> Created Time: 2015年01月28日 星期三 03时24分00秒
 *******************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<pwd.h>
#include<errno.h>
#include<fcntl.h>
#include<time.h>
void mode_to_str(mode_t md,char* buf);
