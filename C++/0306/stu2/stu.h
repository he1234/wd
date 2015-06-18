/********************************************************************
	> File Name: ./stu.h
	> Author: he_CentOS
	> Mail:1778195296@qq.com 
	> Created Time: 2015年03月07日 星期六 00时20分00秒
 *******************************************************************/

#ifndef __STU_H__
#define __STU_H__

#include<iostream>
#include<string>

class student
{
	public:
		student(int id, std::string &name, int age);
		student(){}
		void print();
		void print() const;//函数后面加const表示不能修改类成员
		void set_id(int id);
		void set_name(std::string &name);
		void set_age(int age);
	private:
		int id_;
		std::string name_;
		int age_;
};

#endif
