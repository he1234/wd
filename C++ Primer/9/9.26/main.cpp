/********************************************************************
	> File Name: main.cpp
	> Author: he_CentOS
	> Mail:1778195296@qq.com 
	> Created Time: 2015年03月18日 星期三 09时59分58秒
 *******************************************************************/

#include<iostream>
#include<vector>
#include<list>

int main(void)
{
	int ia[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89};
	std::vector<int> ivec(ia, ia + 11);
	std::list<int> ili(ia, ia + 11);

	std::vector<int>::iterator it_vec = ivec.begin();
	std::list<int>::iterator it_list = ili.begin();

	while(it_vec != ivec.end())
	{
		if(0 == *it_vec % 2)
		{
			it_vec = ivec.erase(it_vec);
		}
		else
		{
			++it_vec;
		}
	}
	while(it_list != ili.end())
	{
		if(1 == *it_list % 2)
		{
			it_list = ili.erase(it_list);
		}
		else
		{
			++it_list;
		}
	}
	
	std::cout << "vec :" << "\t";
	for(it_vec = ivec.begin(); it_vec != ivec.end(); ++it_vec)
	{
		std::cout << *it_vec << "\t";
	}
	std::cout << std::endl;

	std::cout << "ili :" << "\t";
	for(it_list = ili.begin(); it_list != ili.end(); ++it_list)
	{
		std::cout << *it_list << "\t";
	}
	std::cout << std::endl;

	return 0;
}
