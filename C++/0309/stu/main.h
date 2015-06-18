/********************************************************************
  > File Name: main.h
  > Author: he_CentOS
  > Mail:1778195296@qq.com 
  > Created Time: 2015年03月09日 星期一 14时29分22秒
 *******************************************************************/

#ifndef __STU_H
#define __STU_H

#include <string>

class Student
{
	public:
		Student(int id, std::string &name, int age);
		Student(){}
		void print();
		void print() const;
		void setId(int id);
		void setName(std::string &name);
		void setAge(int age);
	private:
		int id_;
		int age_;
		std::string name_;
};

#endif
