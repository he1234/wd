/********************************************************************
	> File Name: main.cpp
	> Author: he_CentOS
	> Mail:1778195296@qq.com 
	> Created Time: 2015年03月09日 星期一 14时45分20秒
 *******************************************************************/

#include<iostream>

class nullclass
{
};
int main(void)
{//由此可得类的大小至少为1B
	nullclass cla1;
	nullclass cla2;
	std::cout << "cla1 = " << &cla1 << std::endl;
	std::cout << "cla2 = " << &cla2 << std::endl;

	std::cout << "sizeof(cla1) :" << sizeof(cla1) << std::endl;

	return 0;
}
