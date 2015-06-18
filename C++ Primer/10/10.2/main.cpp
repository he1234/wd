/********************************************************************
	> File Name: main.cpp
	> Author: he_CentOS
	> Mail:1778195296@qq.com 
	> Created Time: 2015年03月16日 星期一 16时03分34秒
 *******************************************************************/

#include<iostream>
#include<vector>

int main(void)
{
	int val;
	std::string str;
	std::pair<std::string, int> pa;
	std::vector<std::pair<std::string, int> > vec;
	while(std::cin >> str >> val)
	{
		pa = make_pair(str, val);
		vec.push_back(pa);
	}

	std::vector<std::pair<std::string, int> >::iterator iter = vec.begin();
	for(; iter != vec.end(); ++iter)
	{
		std::cout << "( " << (*iter).first << ", " << (*iter).second << ")" << std::endl;
	}
	return 0;
}
