/********************************************************************
	> File Name: main.cpp
	> Author: he_CentOS
	> Mail:1778195296@qq.com 
	> Created Time: 2015年03月20日 星期五 17时09分09秒
 *******************************************************************/

#include<iostream>
#include<string>
#include<cctype>
int main(void)
{
	std::string str("Hello world !ahfkh,.a/afjo");
	std::string::iterator iter = str.begin();
	for(; iter != str.end(); ++iter)
	{
		*iter = toupper(*iter);
	}

	std::cout << str << std::endl;
	return 0;
}
