/********************************************************************
  > File Name: main.cpp
  > Author: he_CentOS
  > Mail:1778195296@qq.com 
  > Created Time: 2015年03月20日 星期五 10时10分56秒
 *******************************************************************/

#include<iostream>
#include<deque>
#include<string>
#include<algorithm>

int main(void)
{
	std::string arr_str[] = {"first", "second", "three", "four", "five"};
	std::deque<std::string> sde(arr_str, arr_str + 5);
	std::string str;
	std::cin >> str;

	std::deque<std::string>::iterator iter = find(sde.begin(), sde.end(), str);
	if(iter == sde.end())
	{
		std::cout << "search failure !" << std::endl;
	}
	else
	{
		sde.erase(iter);
		std::cout << "sde :" << std::endl;
		for(iter = sde.begin(); iter != sde.end(); ++iter)
		{
			std::cout << *iter << "\t";
		}
		std::cout << std::endl;
	}
	return 0;
}
