/********************************************************************
	> File Name: main.cpp
	> Author: he_CentOS
	> Mail:1778195296@qq.com 
	> Created Time: 2015年03月17日 星期二 21时51分40秒
 *******************************************************************/

#include<iostream>
#include<list>
#include<deque>

int main(void)
{
	int arr[] = {11, 32, 36, 1, 2, 3, 4, 5, 6, 7};
	std::list<int> ili(arr, arr + 10);

	std::deque<int> deque1,deque2;
	for(std::list<int>::iterator iter = ili.begin(); iter != ili.end(); ++iter)
	{
		if(1 == *iter%2)
		{
			deque1.push_back(*iter);
		}
		else
		{
			deque2.push_back(*iter);
		}
	}

	std::deque<int>::iterator iter = deque1.begin();
	std::cout << "deque1 :" << std::endl;
	for(iter = deque1.begin(); iter != deque1.end(); ++iter)
	{
		std::cout << *iter << "\t";
	}

	std::cout << std::endl << "deque2 :" << std::endl;
	for (iter = deque2.begin(); iter != deque2.end(); ++iter)
	{
		std::cout << *iter << "\t";
	}

	std::cout << std::endl;
	return 0;
}
