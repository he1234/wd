/********************************************************************
	> File Name: main.cpp
	> Author: he_CentOS
	> Mail:1778195296@qq.com 
	> Created Time: 2015年03月17日 星期二 16时20分54秒
 *******************************************************************/

#include<iostream>
#include<string>
#include<vector>
int main(void)
{
	std::string str;
	std::vector<std::string> vec;
	while(std::cin >> str)
	{
		vec.push_back(str);
	}

	std::vector<std::string>::iterator iter = vec.begin();
	for(; iter != vec.end(); ++iter)
	{
		std::cout << *iter << "\t";
	}

	std::cout << std::endl;
	return 0;
}
