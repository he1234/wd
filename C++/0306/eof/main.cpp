/********************************************************************
	> File Name: main.cpp
	> Author: he_CentOS
	> Mail:1778195296@qq.com 
	> Created Time: 2015年03月06日 星期五 10时03分10秒
 *******************************************************************/

#include<iostream>

int main(void)
{
	int ival;
	while(std::cin >> ival, !std::cin.eof())
	{
		if(std::cin.bad())
		{
			std::cout << "IO stream corrupted! " << std::endl;
			return -1;
		}
		if(std::cin.fail())
		{
			std::cout << "data illegal, try again! " << std::endl;
			std::cin.clear();
			//cin.ignore(1024,'\n')用来清除以回车结束的输入缓冲区的内容
			std::cin.ignore(1024,'\n');
			continue;
		}
		std::cout << "ival = " << ival << std::endl;
	}
	return 0;
}
