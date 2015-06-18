/********************************************************************
	> File Name: main.cpp
	> Author: he_CentOS
	> Mail:1778195296@qq.com 
	> Created Time: 2015年03月12日 星期四 21时11分45秒
 *******************************************************************/

#include<iostream>

int main(void)
{
//	int &val = 2;	//#1编译出错

	//#1编译出错，可改写如下:
	int a = 1;		//非const引用不能绑定到右值，故#1出错
	int &al = a;

	//const引用可以绑定到右值
	//参见C++ Primer page52
	const int &rval = 4.04;


	double dval = 3.14;
	const int &ri = dval;
	//上述两行代码，编译器会转换成如下形式的代码：
	//double dval = 3.14;
	//int temp = dval;
	//const int &ri = temp;
	//！！所以ri是temp的别名，而不是dval的别名

//	std::cout << "val = " << val << std::endl;
	std::cout << "al = " << al << std::endl; 
	std::cout << "rval = " << rval << std::endl;
	return 0;
}
