/********************************************************************
	> File Name: main.cpp
	> Author: he_CentOS
	> Mail:1778195296@qq.com 
	> Created Time: 2015年03月05日 星期四 15时19分56秒
 *******************************************************************/

#include<iostream>
#include<sstream>

int main(void)
{
	std::string s1;
	/*
	while(std::cin>>s1)
	{
		std::cout<<s1<<std::endl;
	}
	*/
	std::string s2;

	while(getline(std::cin,s1))
	{
		std::istringstream iss(s1);
		while(iss>>s2)
		{
			std::cout<<s2<<std::endl;
		}
	}
	return 0;
}
