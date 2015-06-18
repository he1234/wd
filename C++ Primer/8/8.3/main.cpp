/********************************************************************
	> File Name: main.cpp
	> Author: he_CentOS
	> Mail:1778195296@qq.com 
	> Created Time: 2015年03月08日 星期日 20时38分36秒
 *******************************************************************/

#include<iostream>
#include<stdexcept>
int main(void)
{
	std::string str;
	std::istream &fun(std::istream &ist);
	fun(std::cin) >> str;
	std::cout << str << std::endl;

	return 0;
}

std::istream &fun(std::istream &ist)
{
	int ival;
	while(ist >> ival, !ist.eof())
	{
		if(ist.bad())
		{
			throw std::runtime_error("IO stream corrupted");
		}
		if(ist.fail())
		{
			std::cerr << "bad data, try again";
			ist.clear();
			//设置eofbit是为了跳出循环
			ist.setstate(std::istream::eofbit);
			continue;
		}
		std::cout << ival << '\t';
	}

	std::cout << std::endl;
	ist.clear();
	return ist;
}
