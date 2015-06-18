/********************************************************************
	> File Name: main.cpp
	> Author: he_CentOS
	> Mail:1778195296@qq.com 
	> Created Time: 2015年03月07日 星期六 01时08分05秒
 *******************************************************************/

#include "stu.h"

student::student(int id, std::string &name, int age)
	:id_(id), name_(name), age_(age)
{
}

void student::print()
{
	std::cout << "name: " << name_ << std::endl
		<< "id : " << id_ << std::endl
		<< "age: " << age_<< std::endl;
}

void student::print() const
{
	std::cout << "name: " << name_ << std::endl
		<< "id : " << id_ << std::endl
		<< "age: " << age_<< std::endl;
}

student &student::set_id(int id)
{
	id_=id;
	return *this;
}

student &student::set_name(std::string &name)
{
	name_ = name;
	return *this;
}

student &student::set_age(int age)
{
	age_ = age;
	return *this;
}

int main(void)
{
	std::string name = "lisi";

	{
		student s;
		s.set_id(1).set_name(name).set_age(29);
		s.print();
	}

	return 0;
}
