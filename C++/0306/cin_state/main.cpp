/********************************************************************
	> File Name: main.cpp
	> Author: he_CentOS
	> Mail:1778195296@qq.com 
	> Created Time: 2015年03月06日 星期五 09时50分12秒
 *******************************************************************/

#include<iostream>
#include<string>
void print_cin()
{
	std::cout << "bad = " << std::cin.bad() << std::endl;
	std::cout << "fail = " << std::cin.fail() << std::endl;
	std::cout << "eof = " << std::cin.eof() << std::endl;
	std::cout << "good = " << std::cin.good() << std::endl;
}

int main(void)
{
	int inum;
	print_cin();

	while(std::cin >>inum)
	{
		std::cout << inum << std::endl;
	}

	print_cin();

	std::cin.clear();
	print_cin();
	//清空缓冲区
	std::cin.ignore(1024,'\n');

	std::string s = "hello";
	std::cin >> s;
	std::cout << s << std::endl;

	return 0;
}
