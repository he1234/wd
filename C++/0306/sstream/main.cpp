/********************************************************************
	> File Name: main.cpp
	> Author: he_CentOS
	> Mail:1778195296@qq.com 
	> Created Time: 2015年03月06日 星期五 10时41分25秒
 *******************************************************************/

#include<iostream>
#include<sstream>
#include<string>
int main(void)
{
	int ival = 512;
	int ival2 = 1024;
	std::stringstream ss;
	ss << "ival = " << ival << " " << "ival2 = " << ival2 << std::endl;

	std::string str = ss.str();
	std::cout << str << std::endl;

	while(ss >> str)
	{//遇到空白符，便结束本次输入
		std::cout << str << std::endl;
	}

	return 0;
}
