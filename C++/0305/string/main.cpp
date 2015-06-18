/********************************************************************
	> File Name: main.cpp
	> Author: he_CentOS
	> Mail:1778195296@qq.com 
	> Created Time: 2015年03月06日 星期五 00时20分15秒
 *******************************************************************/

#include<iostream>
#include<string>

int main(void)
{//substr(),size(),sizeof(),iterator
	std::string s1 = "abcefg";
	std::string s2("hello world");
	//注意！以下sizeof(s1)与sizeof(s2)与sizeof(string)结果相同
	//string类型本质是指针，64位操作系统的话，结果为8
	std::cout << "sizeof(s1) :" << sizeof(s1) << std::endl;
	std::cout << "sizeof(s2) :" << sizeof(s2) << std::endl;
	std::cout << "sizeof(string) :" << sizeof(std::string) << std::endl;

	std::string s3 = s1 + s2;

	char ch = 'E';
	std::string s4 = s2 + ch;
	std::cout << s1 << std::endl;
	std::cout << s2 << std::endl;
	std::cout << s3 << std::endl;
	std::cout << s4 << std::endl;
	//s2.substr(7，10),表示返回字符串s2[7]后的10个字符组成的字符串
	std::string s5 = s2.substr(0,5);
	std::string s6 = s2.substr(6,5);
	std::cout << s5 << std::endl;
	std::cout << s6 << std::endl;
	//s2.size(),表示字符串s2的长度,等效于s2.length()
	for(int idx = 0;idx != s2.size(); ++idx)
	{
		std::cout << s2[idx] << std::endl;
	}
	
	//iterator
	std::string::iterator it = s2.begin();
	for(; it != s2.end(); ++it)
	{
		std::cout << *it<< std::endl;
	}

	return 0;
}
