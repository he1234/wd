/*************************************************************************
    > File Name: main.cpp
    > Author: 时中贺
    > Mail: shi_zhonghe@163.com 
    > Created Time: 2015年06月05日 星期五 15时55分21秒
 ************************************************************************/

#include<iostream>
#include<vector>
#include "String.h"

//该代码实现了std::move
int main(void)
{
	String str1;
	str1 = String("hello");
	std::vector<String> vec;
	vec.push_back(String("world"));
	std::cout <<"---------------" << std::endl;

	return 0;
}
