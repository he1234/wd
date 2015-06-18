/********************************************************************
	> File Name: main.cpp
	> Author: he_CentOS
	> Mail:1778195296@qq.com 
	> Created Time: 2015年03月17日 星期二 14时38分11秒
 *******************************************************************/

#include<iostream>
#include<list>

int main(void)
{
	std::list<int> ili;
	int val;
	while(std::cin >> val)
	{
		ili.push_back(val);
	}
	std::list<int>::iterator iter = ili.end();

	do
	{
		--iter;
		std::cout << *iter << '\t';
	}while(iter != ili.begin());
	std::cout << std::endl;
	return 0;
}
