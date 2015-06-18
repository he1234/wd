/********************************************************************
	> File Name: main.cpp
	> Author: he_CentOS
	> Mail:1778195296@qq.com 
	> Created Time: 2015年03月21日 星期六 10时09分36秒
 *******************************************************************/

#include<iostream>
#include<string>

int main(void)
{
	std::string q1("When lilacs last in the dooryard bloom'd");
	std::string q2("The child is father of the man");
	std::string sentence;
	sentence.assign(q2.begin(), q2.begin() + 13);
	sentence.append(q1, 17, 15);
	std::cout << sentence << std::endl;
	return 0;
}
