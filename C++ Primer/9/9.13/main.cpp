/********************************************************************
	> File Name: main.cpp
	> Author: he_CentOS
	> Mail:1778195296@qq.com 
	> Created Time: 2015年03月17日 星期二 15时45分45秒
 *******************************************************************/

#include<iostream>
#include<vector>
typedef std::vector<int>::iterator iter;

int main(void)
{
	iter search_val(iter first, iter last, int val);
	int a[] = {1, 2, 3, 4, 5, 6};
	std::vector<int> vec(a, a + 6);
	iter it = search_val(vec.begin(), vec.end(), 3);
	if(it == vec.end())
	{
		std::cout << "search failure !" << std::endl;
	}
	else
	{
		std::cout << "search success !" << std::endl;
		std::cout << (*it) << std::endl;
	}
	return 0;
}

iter search_val(iter first, iter last, int val)
{
	iter it = first;
	for(; it != last; ++it)
	{
		if(*it == val)
			return it;
	}
	return it;
}
