/********************************************************************
	> File Name: main.cpp
	> Author: he_CentOS
	> Mail:1778195296@qq.com 
	> Created Time: 2015年03月06日 星期五 09时29分38秒
 *******************************************************************/

#include<iostream>
#include<vector>
#include<algorithm>

void print(int i)
{
	std::cout << i << std::endl;
}

/*
int main(void)
{
	std::vector<int> vec;
	vec.push_back(11);
	vec.push_back(22);
	vec.push_back(33);
	vec.push_back(44);

	//遍历vec
	for_each(vec.begin(),vec.end(),print);
	return 0;
}
*/
///*
//c++ 11标准,编译时最后加上-std=c++11才能通过编译
int main(void)
{
	std::vector<int> vec;
	vec.push_back(11);
	vec.push_back(22);
	vec.push_back(33);
	vec.push_back(44);
	vec.push_back(55);

	for(int idx : vec)
	{
		std::cout << idx << std::endl;
	}
	return 0;
}
//*/
