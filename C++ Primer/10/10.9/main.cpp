/********************************************************************
	> File Name: main.cpp
	> Author: he_CentOS
	> Mail:1778195296@qq.com 
	> Created Time: 2015年03月21日 星期六 20时53分39秒
 *******************************************************************/

#include<iostream>
#include<map>
#include<string>

int main(void)
{
	std::string word;
	std::map<std::string, int> word_count;
	while(std::cin >> word)
	{
		++word_count[word];
		std::cout << word << " : " << word_count[word] << std::endl;
	}

	return 0;
}
