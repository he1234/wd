/********************************************************************
	> File Name: main.cpp
	> Author: he_CentOS
	> Mail:1778195296@qq.com 
	> Created Time: 2015年03月17日 星期二 22时34分14秒
 *******************************************************************/

#include<iostream>
#include<vector>
#include<list>

int main()
{
	int arr[] = {1, 2, 3, 4, 5, 6};
	int arr2[] = {2, 3, 4, 5, 6, 7};
	std::vector<int> vec(arr, arr+6);
	std::list<int> list(arr2, arr2 + 6);

	std::vector<int>::iterator it_vec = vec.begin();
	std::list<int>::iterator it_list = list.begin();

	for(; it_vec != vec.end() || it_list != list.end(); ++it_vec, ++it_list)
	{
		if(*it_vec != *it_list)
		{
			break;
		}
	}
	if(it_vec == vec.end() && it_list == list.end())
	{
		std::cout << "==" << std::endl;
	}
	else
	{
		std::cout << "!=" << std::endl;
	}
	return 0;
}
