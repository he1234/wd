/********************************************************************
  > File Name: main.cpp
  > Author: he_CentOS
  > Mail:1778195296@qq.com 
  > Created Time: 2015年03月17日 星期二 23时34分03秒
 *******************************************************************/

#include<iostream>
#include<vector>

int main(void)
{
	int val;
	std::vector<int> vec;
	while(std::cin >> val)
	{
		vec.push_back(val);
	}
	if(!vec.empty())
	{
		//如果下句代码越界，返回0
		std::cout << "vec[0] :" << vec[7] << std::endl;
		//如果越界，下句代码会抛出out_of_range异常
		std::cout << "vec.at(0) :" << vec.at(10) << std::endl;

		std::cout << "*vec.begin() :" << *vec.begin() << std::endl;
		std::cout << "vec.front() :" << vec.front() << std::endl;
		return 0;
	}
}
