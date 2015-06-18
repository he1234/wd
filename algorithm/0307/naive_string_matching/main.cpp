/********************************************************************
	> File Name: main.cpp
	> Author: he_CentOS
	> Mail:1778195296@qq.com 
	> Created Time: 2015年03月07日 星期六 10时15分12秒
 *******************************************************************/

#include<iostream>
#include<string>

int main(void)
{//字符串朴素匹配算法
	std::string str1 = "aababcabcdabcde";
	std::string str2 = "abc";
	int i, j;
	for(i = 0; i < str1.size(); i++)
	{
		for(j = 0;j < str2.size(); j++)
		{
			if(str1[i+j] == str2[j])
				continue;
			break;
		}
		if(j == str2.size())
			break;
	}
	std::cout << "i = " << i << std::endl;
}
