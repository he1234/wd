/********************************************************************
	> File Name: main.cpp
	> Author: he_CentOS
	> Mail:1778195296@qq.com 
	> Created Time: 2015年03月20日 星期五 22时21分06秒
 *******************************************************************/

#include<iostream>
#include<string>

int main(void)
{
	std::string str("ab2c3d7R4E6");
	std::string alphas("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ");
	std::string numbers("0123456789");
	std::string::size_type pos = 0;

	while((pos = str.find_first_not_of(alphas, pos)) != std::string::npos)
	{
		std::cout << str.at(pos++) << "\t";
	}
	std::cout << std::endl;

	pos = 0;
	while((pos = str.find_first_not_of(numbers, pos)) != std::string::npos)
	{
		std::cout << str.at(pos++) << '\t';
	}
	std::cout << std::endl;
	return 0;
}
