/********************************************************************
	> File Name: main.cpp
	> Author: he_CentOS
	> Mail:1778195296@qq.com 
	> Created Time: 2015年03月21日 星期六 11时23分34秒
 *******************************************************************/

#include<iostream>
#include<stack>
#include<string>

int main(void)
{
	std::stack<std::string> stk;
	std::string word;
	while(std::cin >> word)
	{
		stk.push(word);
	}

	while(!stk.empty())
	{
		std::cout << stk.top() << '\t';
		stk.pop();
	}
	std::cout << std::endl;
	return 0;
}
