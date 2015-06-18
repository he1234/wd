/********************************************************************
	> File Name: ./main.cpp
	> Author: he_CentOS
	> Mail:1778195296@qq.com 
	> Created Time: 2015年03月05日 星期四 21时44分43秒
 *******************************************************************/

#include <iostream>
int ival = 100;
namespace mynm
{
	int ival2 = 20;
	int ival3;//会自动初始化为0
	double dval;//同上

	int max(int a,int b)
	{
		return a > b ? a : b;
	}
}
int main(void)
{
	int ival=10;
	std::cout<<"hello,world	!"<<std::endl;
	std::cout<<"main->ival = " <<ival << std::endl;
	std::cout << "::ival = " << ::ival << std::endl;//::ival表示全局变量ival

	std::cout << "ival2 = " << mynm::ival2 << std::endl;
	std::cout << "max(3,4) = " << mynm::max(3,4) << std::endl;
	std::cout << "ival3 = "<< mynm::ival3 << std::endl;

	std::cout << "dval = " << mynm::dval << std::endl;

	return 0;
}
