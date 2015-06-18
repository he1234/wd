/********************************************************************
	> File Name: ./stu.h
	> Author: he_CentOS
	> Mail:1778195296@qq.com 
	> Created Time: 2015年03月07日 星期六 01时09分07秒
 *******************************************************************/

#ifndef __STU_H__
#define __STU_H__

#include<iostream>
#include<string>

class student
{
	public:
		student(int id, std::string &name, int age);
		student()
		{
			std::cout << "student construct" << std::endl;
		}
		~student()
		{
			std::cout << "student destroy" << std::endl;
		}
		void print();
		void print() const;
		student &set_id(int id);
		student &set_name(std::string &name);
		student &set_age(int age);

	private:
		int id_;
		std::string name_;
		int age_;
};

#endif
