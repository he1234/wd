/********************************************************************
	> File Name: main.cpp
	> Author: he_CentOS
	> Mail:1778195296@qq.com 
	> Created Time: 2015年03月07日 星期六 00时19分27秒
 *******************************************************************/

#include "stu.h"

student::student(int id, std::string &name, int age)
	:id_(id), name_(name), age_(age)
{
}

void student::print() const
{
	std::cout << "print() const !" << std::endl;
	std::cout << "name: " << name_ << std::endl
		<< "id	: " << id_	<< std::endl
		<< "age	: " << age_	<< std::endl;
}

void student::print()
{
	std::cout << "print() !" << std::endl;
	std::cout << "name: " << name_ << std::endl
		<< "id	: " << id_	<< std::endl
		<< "age	: " << age_	<< std::endl;
}

void student::set_id(int id)
{
	id_ = id;
}

void student::set_name(std::string &name)
{
	name_ = name;
}

void student::set_age(int age)
{
	age_ = age;
}

int main(void)
{
	std::string name = "lisi";
	const student s1(1, name, 29);

	s1.print();
	return 0;
}
