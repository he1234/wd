/********************************************************************
	> File Name: main.cpp
	> Author: he_CentOS
	> Mail:1778195296@qq.com 
	> Created Time: 2015年03月06日 星期五 11时13分11秒
 *******************************************************************/

#include<iostream>
#include<string>

struct student
{
	int id_;
	std::string name_;
	int age_;

	void print()
	{
		std::cout << "id :" << id_ << "	name :" << name_ 
			<< "	age :" << age_ << std::endl;
	}

};

class person
{
	private:
		int id_;
		std::string name_;
		int age_;
	public:
		void print()
		{
			std::cout << "id :" << id_ <<"	name :" << name_ 
				<<"	age :" << age_ << std::endl;
		}
		void set_id(int id)
		{
			id_ = id;
		}
		void set_name(std::string name)
		{
			name_ = name;
		}
		void set_age(int age)
		{
			age_ = age;
		}
};
/*
int main(void)
{
	student s1;
	s1.id_ = 1;
	s1.name_ = "lwh";
	s1.age_ = 28;

	student *ps1 = &s1;
	std::cout << "id :" << ps1->id_ << "	name :" << ps1->name_ 
		<< "	age :" << ps1->age_ <<std::endl;

	s1.print();

	return 0;
}
*/

int main(void)
{
	person person1;
	person1.set_id(2);
	person1.set_name("zhangsan");
	person1.set_age(22);

	person1.print();
}
