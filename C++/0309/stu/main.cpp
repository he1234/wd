/********************************************************************
  > File Name: main.cpp
  > Author: he_CentOS
  > Mail:1778195296@qq.com 
  > Created Time: 2015年03月09日 星期一 10时54分36秒
 *******************************************************************/

#include "main.h"
#include <string>
#include <iostream>

	Student::Student(int id, std::string &name, int age)
: id_(id), name_(name), age_(age)
{
	//id_ = id;
	//name_ = name;
	//age_ = age;
}


void Student::print()
{
	std::cout << "name: " << name_ << std::endl
		<< "id  : " << id_ <<std::endl
		<< "age : " << age_ << std::endl;
}
void Student::print() const
{
	std::cout << "name: " << name_ << std::endl
		<< "id  : " << id_ <<std::endl
		<< "age : " << age_ << std::endl;
}

void Student::setId(int id)
{
	id_ = id;
}

void Student::setName(std::string &name)
{
	name_ = name;
}

void Student::setAge(int age)
{
	age_ = age;
}
#if 0
int test0(void)
{
	std::string name = "lisi";
	Student s;
	s.setId(1);
	s.setName(name);
	s.setAge(29);

	s.print();

	const Student *ps = &s;
	ps->print();

	return 0;
}
#endif 

int main(void)
{
	std::string name = "lisiafhaksfhaf";
	Student s1(1, name, 29);
	Student s;

	s1.print();

	std::cout << "sizeof(Student) " << sizeof(s1) << std::endl;
	std::cout << "sizeof(int) " << sizeof(int) << std::endl;
	std::cout << "sizeof(name) " << sizeof(name) << std::endl;

	return 0;
}

