/********************************************************************
	> File Name: main.cpp
	> Author: he_CentOS
	> Mail:1778195296@qq.com 
	> Created Time: 2015年03月21日 星期六 17时03分41秒
 *******************************************************************/

#include<iostream>
#include<bitset>

int main(void)
{
	std::string str("1000000010000100101110");
	std::bitset<32> bitvec(str);
	std::cout << bitvec << std::endl;
	std::cout << bitvec[2] << std::endl;

	std::cout << "-----------------------------" << std::endl;

	//数列符合fibonacci数列规律
	std::bitset<32> bitvec2;
	int a = 0, b = 1, sum = a + b;
	while(sum <= 21)
	{
		bitvec2.set(sum);
		a = b;
		b = sum;
		sum = a + b;
	}
	std::cout << bitvec2 << std::endl;

	return 0;
}
