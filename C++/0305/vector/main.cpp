/********************************************************************
	> File Name: main.cpp
	> Author: he_CentOS
	> Mail:1778195296@qq.com 
	> Created Time: 2015年03月05日 星期四 15时43分42秒
 *******************************************************************/

#include<iostream>
#include<vector>
int main(void)
{
	std::vector<int> vec;
	vec.push_back(10);
	vec.push_back(20);
	vec.push_back(30);
	vec.push_back(40);
	vec.push_back(50);

	std::cout<<vec.size()<<std::endl;

	//for(int idx=0;idx!=vec.size();++idx)
	//{
	//	std::cout<<vec[idx]<<std::endl;
	//}
	
	//迭代器
	//std::vector<int>::iterator it=vec.begin();
	//for(;it!=vec.end();++it)
	//{
	//	std::cout<<*it<<std::endl;
	//}

	std::cout<<std::endl;

	std::vector<int> vec2(vec);
	std::vector<int>::iterator it2=vec2.begin();
	for(;it2!=vec2.end();++it2)
	{
		std::cout<<*it2<<std::endl;
	}

	std::vector<int> vec3(vec.begin(), vec.end());
	std::vector<int>::iterator it3=vec3.begin();
	for(;it3!=vec3.end();++it3)
	{
		std::cout<<*it3<<std::endl;
	}

	return 0;

}
