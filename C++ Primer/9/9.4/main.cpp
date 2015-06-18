/********************************************************************
	> File Name: main.cpp
	> Author: he_CentOS
	> Mail:1778195296@qq.com 
	> Created Time: 2015年03月16日 星期一 18时30分32秒
 *******************************************************************/

#include<iostream>
#include<list>
#include<deque>

int main(void)
{
	std::deque<int> ide(3, 10);
	std::list< std::deque<int> > li(3,ide);
	std::list< std::deque<int> >::iterator itli = li.begin();
	std::deque<int>::iterator itde;

	for(; itli != li.end(); ++itli)
	{
		for(itde = (*itli).begin(); itde != (*itli).end(); ++itde)
		{
			std::cout << (*itde) << '\t';
		}
		std::cout << std::endl;
	}
	return 0;
}
