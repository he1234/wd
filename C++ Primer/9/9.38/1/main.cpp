/********************************************************************
	> File Name: main.cpp
	> Author: he_CentOS
	> Mail:1778195296@qq.com 
	> Created Time: 2015年03月20日 星期五 21时58分04秒
 *******************************************************************/

#include<iostream>
#include<string>

int main(void)
{
	std::string numbers("0123456789");
	std::string str("ab2c3d7R4E6");
	std::string::size_type pos = 0;
	while((pos = str.find_first_of(numbers, pos)) != std::string::npos)
	{
		std::cout << str.at(pos++) << '\t';
	}
	std::cout << std::endl;

	pos = 0;
	std::string alphas("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ");
	while((pos = str.find_first_of(alphas, pos)) != std::string::npos)
	{
		std::cout << str.at(pos++) << '\t';
	}
	std::cout << std::endl;
	return 0;
}
