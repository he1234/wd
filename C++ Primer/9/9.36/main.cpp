/********************************************************************
	> File Name: main.cpp
	> Author: he_CentOS
	> Mail:1778195296@qq.com 
	> Created Time: 2015年03月20日 星期五 17时43分34秒
 *******************************************************************/

#include<iostream>
#include<string>
#include<vector>

int main(void)
{
	char cval;
	std::vector<char> vec;
	while(std::cin >> cval)
	{
		vec.push_back(cval);
	}
	std::string str(vec.begin(), vec.end());
	std::cout << "str : " << str << std::endl;
	return 0;
}
