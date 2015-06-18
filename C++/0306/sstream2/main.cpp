/********************************************************************
	> File Name: main.cpp
	> Author: he_CentOS
	> Mail:1778195296@qq.com 
	> Created Time: 2015年03月06日 星期五 23时56分32秒
 *******************************************************************/

#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include<vector>

int main(void)
{
	std::ifstream ifs("iol.cc");
	if(!ifs.good())
	{
		return -1;
	}

	std::vector<std::string> vec_str;
	std::string line;
	while(ifs >> line)
	{
		vec_str.push_back(line);
	}

	std::stringstream ss;

	std::vector<std::string>::iterator sit = vec_str.begin();
	for(;sit != vec_str.end(); ++sit)
	{
		ss << *sit << std::endl;
	}

	std::string str;
	while(ss >> str)
	{
		std::cout << str << std::endl;
	}
	return 0;
}
