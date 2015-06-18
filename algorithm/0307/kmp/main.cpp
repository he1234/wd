/********************************************************************
	> File Name: main.cpp
	> Author: he_CentOS
	> Mail:1778195296@qq.com 
	> Created Time: 2015年03月07日 星期六 10时53分36秒
 *******************************************************************/

#include<iostream>
#include<string>

int main(void)
{//kmp
	void previous(std::string pattern, int pre[]);
	int kmp(std::string str, std::string pattern, int pre[], int pos);

	std::string str;
	std::string pattern;
	int pos;
	std::cout << "Input a string : " << std::endl;
	std::cin >> str;
	std::cout << "Input a pattern: " << std::endl;
	std::cin >> pattern;
	std::cout << "Input a matching position : "<< std::endl;
	std::cin >> pos;

	int pre[pattern.size()];
	
	previous(pattern, pre);
	int ret = kmp(str, pattern, pre, pos);
	if(-1 == ret)
	{
		std::cout << "Matching failure !" << std::endl;
	}
	else
	{
		std::cout << "Matching success !" << std::endl
				  << "And the index is  " << ret << std::endl;
	}

	return 0;
}

void previous(std::string pattern, int pre[])
{
	int i = 0;
	int k = -1;
	pre[0] = -1;
	int len = pattern.size();
	while(i < len)
	{
		if(-1 == k || pattern[i] == pattern[k])
		{
			i++;
			k++;
			pre[i] = k;
		}
		else
			k = pre[k];
	}
}

int kmp(std::string str, std::string pattern, int pre[], int pos)
{
	int i = pos;
	int k = 0;
	int len_str = str.size();
	int len_pattern = pattern.size();

	while(i < len_str && k < len_pattern)
	{
		if(-1 == k || str[i] == pattern[k])
		{
			i++;
			k++;
		}
		else
		{
			k = pre[k];
		}
	}
	if(k != len_pattern)
		return -1;
	return (i-k);
}
