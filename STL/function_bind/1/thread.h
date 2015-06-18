/********************************************************************
	> File Name: thread.h
	> Author: he_CentOS
	> Mail:1778195296@qq.com 
	> Created Time: 2015年04月11日 星期六 19时55分51秒
 *******************************************************************/

#ifndef __THREAD_H__
#define __THREAD_H__

#include<pthread.h>
#include<functional>
#include "Noncopyable"

class Thread : Noncopyable
{
	public:
		typedef std::function<void ()> funcp;
		T
