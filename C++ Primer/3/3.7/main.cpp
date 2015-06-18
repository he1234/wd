/********************************************************************
	> File Name: main.cpp
	> Author: he_CentOS
	> Mail:1778195296@qq.com 
	> Created Time: 2015年03月07日 星期六 17时20分26秒
 *******************************************************************/

#include<iostream>
#include<string>

int main(void)
{
	std::string str1("I am string 1 !");
	std::string str2("I am string 2 !");
	
	if(str1 == str2)
	{
		std::cout << "str1 == str2" << std::endl;
		return 0;
	}

	std::cout << (str1 > str2 ? "str1 > str2" : "str2 > str1") << std::endl;
	
	//size_type
	std::string::size_type len1 = str1.size();
	std::string::size_type len2 = str2.size();
	std::cout << (len1 > len2 ? "length of str1 is longer than str2 !" : 
			len1 < len2 ? "length of str2 is longer than str1 !" : "They are equal !") << std::endl;

	return 0;
}
