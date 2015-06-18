/*************************************************************************
    > File Name: function_lambda.cpp
    > Author: 时中贺
    > Mail: shi_zhonghe@163.com 
    > Created Time: 2015年06月05日 星期五 02时07分53秒
 ************************************************************************/

#include<iostream>
#include<map>
#include<functional>

int add(int i, int j)
{
	return (i+j);
}

auto mod = [](int i, int j)
{
	return (i%j);
};

struct divide
{
	int operator()(int denominator, int divisor)
	{
		return (denominator / divisor);
	}
};

int main(void)
{
	std::map<char, int(*)(int, int)> binops_limit;

	//传统形式
	binops_limit.insert({'+', add});
	binops_limit.insert({'%', mod});
	//binops_limit.insert({'/', divide()});//无法通过编译

	//function可将普通函数，lambda表达式和函数对象类统一起来。
	//它们并非相同类型，但可通过function模板类，把它转为相同类型的对象（function对象），从而放入一个map里
	std::map<char, std::function<int(int, int)>> binops =
	{
		{'+', add},								//普通函数
		{'-', std::minus<int>()},				//头文件<functional>中执行operator-的模板类
		{'*', [](int i, int j){return (i*j);}},	//lambda表达式
		{'/', divide()},						//类成员函数operator()
		{'%', mod}								//lambda表达式对象
	};

	std::cout << "+: " << binops['+'](10, 5) << std::endl;
	std::cout << "-: " << binops['-'](10, 5) << std::endl;
	std::cout << "*: " << binops['*'](10, 5) << std::endl;
	std::cout << "/: " << binops['/'](10, 5) << std::endl;
	std::cout << "%: " << binops['%'](10, 5) << std::endl;

	return 0;
}
