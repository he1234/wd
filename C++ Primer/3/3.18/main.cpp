/********************************************************************
	> File Name: ./main.cpp
	> Author: he_CentOS
	> Mail:1778195296@qq.com 
	> Created Time: 2015年03月08日 星期日 17时48分18秒
 *******************************************************************/

#include<iostream>
#include<vector>

int main(void)
{
	std::vector<int> vec_int;
	std::vector<int>::iterator iter = vec_int.end();
	for(int i = 0; i != 10; ++i)
	{
		vec_int.insert(iter, i * 10);
		iter = vec_int.end();
	}

	iter = vec_int.begin();
	for(;iter != vec_int.end();++iter)
	{
		*iter = *iter*2;
		std::cout << *iter << std::endl;
	}
	return 0;
}
