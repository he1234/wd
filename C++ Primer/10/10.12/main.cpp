/********************************************************************
	> File Name: main.cpp
	> Author: he_CentOS
	> Mail:1778195296@qq.com 
	> Created Time: 2015年03月21日 星期六 22时24分33秒
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
		std::pair< std::map<std::string, int>::iterator, bool > ret = word_count.insert(make_pair(word, 1));
		if(false == ret.second)
		{
			++ret.first->second;
		}
	}

	std::map<std::string, int>::iterator iter = word_count.begin();
	for(; iter != word_count.end(); ++iter)
	{
		std::cout << iter -> first << " : " << iter -> second << std::endl;
	}
	return 0;
}
