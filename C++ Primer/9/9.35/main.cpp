/********************************************************************
	> File Name: main.cpp
	> Author: he_CentOS
	> Mail:1778195296@qq.com 
	> Created Time: 2015年03月20日 星期五 17时24分05秒
 *******************************************************************/

#include<iostream>
#include<string>

int main(void)
{
	std::string str("Hello World !");
	std::cout << "str : " << str << std::endl;
	std::string::iterator iter = str.begin();
	for(; iter != str.end(); ++iter)
	{
		if(*iter < 91 && *iter > 64)
		{
			str.erase(iter);
		}
	}

	std::cout << "str : " << str << std::endl;
	return 0;
}
