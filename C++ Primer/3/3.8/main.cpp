/********************************************************************
	> File Name: ./main.cpp
	> Author: he_CentOS
	> Mail:1778195296@qq.com 
	> Created Time: 2015年03月07日 星期六 17时45分46秒
 *******************************************************************/

#include<iostream>
#include<string>

int main(void)
{
	std::string line;
	std::string str;
	while(getline(std::cin, line))
	{//按ctrl+d结束输入
		str += ' '+line;
	}
	std::cout << str << std::endl;

	return 0;
}
