/********************************************************************
	> File Name: main.cpp
	> Author: he_CentOS
	> Mail:1778195296@qq.com 
	> Created Time: 2015年03月17日 星期二 15时15分26秒
 *******************************************************************/

#include<iostream>
#include<vector>
typedef std::vector<int>::iterator iter;

int main(void)
{
	bool search_val(iter begin, iter end, int val);
	int a[] = {0, 1, 2, 3, 4, 5};
	std::vector<int> vec(a, a + 6);
	iter begin = vec.begin();
	iter end = vec.end();

	if(false == search_val(begin, end, 5))
	{
		std::cout << "search failure !" << std::endl;
	}
	else
	{
		std::cout << "search success !" << std::endl;
	}
	return 0;
}

bool search_val(iter begin, iter end, int val)
{
	if(begin > end)
	{
		std::cout << "error" << std::endl;
		return false;
	}
	for(iter it= begin; it != end; ++it)
	{
		if(*it == val)
		{
			return true;
		}
	}
	return false;
}
