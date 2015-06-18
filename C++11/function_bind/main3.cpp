/********************************************************************
	> File Name: main3.cpp
	> Author: he_CentOS
	> Mail:1778195296@qq.com 
	> Created Time: 2015年04月13日 星期一 12时20分31秒
 *******************************************************************/

#include<iostream>

void print()
{
	std::cout << std::endl;
}

template<typename T>
void print(const T& t)
{
	std::cout << t << std::endl;
}

template<typename First, typename... Rest>
void print(const First& first, const Rest&... rest)
{
	std::cout << first << ",";
	print(rest...);//recursive call using pack expansion syntax
}

int main(void)
{
	print();//calls first overload, outputting only a newline
	print(1);//calls second overload

	//these call the third overload, the variadic template
	//which uses recursion as needed
	print(1, 2);
	print(1, 2, 3);
	print("first", 2, "third", 3.14159);

	return 0;
}
