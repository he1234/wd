/********************************************************************
	> File Name: main1.cpp
	> Author: he_CentOS
	> Mail:1778195296@qq.com 
	> Created Time: 2015年04月12日 星期日 20时57分19秒
 *******************************************************************/

#include<iostream>

int main(void)
{
	//将创建的匿名函数赋值给sum,sum为int型
	auto sum = [](int x, int y) -> int {return x + y;};

	int x = 10, y = 20;
	auto result = sum(x, y);
	std::cout << "result : " << result << std::endl;

	[]//[]中的内容捕获上下文的数据
	{//只是声明了一个lambda函数，但未调用
		std::cout << "Done1" << std::endl;
	};
	[]
	{//声明并调用一个lambda函数
		std::cout << "Done2" << std::endl;
	}();

	int a = 1, b = 10;
//	[]//[]中没有内容，所以没有捕获上下文的数据
//	{//无法通过编译
//		return a + b;
//	};
	[=]//[=]表示捕获上下文的数据，所以能使用变量a, b,但无法修改a, b
	{
		return a + b;
	};

	std::cout << "b = " << b << std::endl;

	[&] (int c)//[&]表示捕获上下文数据，并引用
	{
		b = a + c;
	}(50);
	std::cout << "b = " << b << std::endl;

//	[&a, b] (int c)//a在函数体中可以被修改，b不能，不能通过编译
//	{
//		b = a + c;
//	}(1000);

	auto b2 = [a, &b] (int c) -> int	//a只读，b读写
	{
		b = a + c;
		return a + c;
	}(1000);
	std::cout << "b = " << b << "\tb2 = " << b2 << std::endl;

	return 0;
}
