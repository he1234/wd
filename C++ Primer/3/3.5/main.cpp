/********************************************************************
	> File Name: ./main.cpp
	> Author: he_CentOS
	> Mail:1778195296@qq.com 
	> Created Time: 2015年03月07日 星期六 16时56分20秒
 *******************************************************************/

#include<iostream>
#include<string>

int main(void)
{
	/*
	std::string line;
	while(getline(std::cin,line))
	{
		std::cout << line << std::endl;
	}
	*/
	std::string word;
	while(std::cin >> word)
	{
		std::cout << word << std::endl;
	}
	return 0;
}
