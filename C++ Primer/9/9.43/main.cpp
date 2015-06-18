/********************************************************************
	> File Name: main.cpp
	> Author: he_CentOS
	> Mail:1778195296@qq.com 
	> Created Time: 2015年03月21日 星期六 11时32分15秒
 *******************************************************************/

#include<iostream>
#include<stack>

int main(void)
{
	std::stack<char> stk;
	char ch;
	while(std::cin >> ch)
	{
		if(ch != ')')
		{
			stk.push(ch);
		}
		else
		{
			while(!stk.empty() && stk.top() != '(')//while中的两个表达式不能写反，否则可能出现段错误
			{
				stk.pop();
			}
			if(stk.empty())
			{
				std::cout << "It's not matched !" << std::endl;
			}
			else
			{
				stk.pop();
				stk.push('$');
			}
		}
	}

	while(!stk.empty())
	{
		std::cout << stk.top();
		stk.pop();
	}
	std::cout << std::endl;

	return 0;
}
