/********************************************************************
	> File Name: main.cpp
	> Author: he_CentOS
	> Mail:1778195296@qq.com 
	> Created Time: 2015年03月20日 星期五 11时09分48秒
 *******************************************************************/

#include<iostream>
#include<string>
#include<list>
#include<vector>

int main(void)
{
	char* arr_char[] = {"one", "two", "three", "four", "five"};
	std::list<char*> cli(arr_char, arr_char + 5);
	std::vector<std::string> svec;

	svec.assign(cli.begin(), cli.end());

	std::vector<std::string>::iterator iter = svec.begin();
	std::cout<< "svec : ";
	while(iter != svec.end())
	{
		std::cout << *iter << "\t";
		++iter;
	}
	std::cout << std::endl;
	return 0;
}
