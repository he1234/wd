/********************************************************************
	> File Name: server.h
	> Author: he_CentOS
	> Mail:1778195296@qq.com 
	> Created Time: 2015年03月02日 星期一 15时42分49秒
 *******************************************************************/

#ifndef __SER_H__
#define __SER_H__
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<signal.h>
#include<unistd.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<dirent.h>

#define SER_IP "192.168.1.90"
#define SER_PORT 1234

void signal_handle(int signum);
int socket_init();
int socket_accept(int sfd,struct sockaddr* client_addr);
void child_main(int sfd);
#endif
