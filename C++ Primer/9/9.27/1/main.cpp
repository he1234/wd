/********************************************************************
	> File Name: main.cpp
	> Author: he_CentOS
	> Mail:1778195296@qq.com 
	> Created Time: 2015年03月18日 星期三 10时52分16秒
 *******************************************************************/

#include<iostream>
#include<string>
#include<list>
#include<algorithm>

int main(void)
{
	std::string arr_str[] = {"first", "second", "three", "four", "five"};
	std::list<std::string> li_str(arr_str, arr_str + 5);
	std::string str;
	std::cin >> str;

	std::list<std::string>::iterator iter = find(li_str.begin(), li_str.end(), str);
	li_str.erase(iter);

	std::cout << std::endl;
	for(iter = li_str.begin(); iter != li_str.end(); ++iter)
	{
		std::cout << *iter << "\t";
	}
	std::cout << std::endl;
	return 0;
}
