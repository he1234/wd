/********************************************************************
	> File Name: main.cpp
	> Author: he_CentOS
	> Mail:1778195296@qq.com 
	> Created Time: 2015年03月06日 星期五 00时05分49秒
 *******************************************************************/

#include<iostream>

void swap(int &a,int &b)
{
	int temp = a;
	a = b;
	b = temp;
}
int main(void)
{
	int ival1 = 3;
	int ival2 = 4;
	swap(ival1,ival2);
	std::cout << "ival1 = " << ival1 << std::endl;
	std::cout << "ival2 = " << ival2 << std::endl;
	return 0;
}
