/********************************************************************
	> File Name: main.cpp
	> Author: he_CentOS
	> Mail:1778195296@qq.com 
	> Created Time: 2015年03月16日 星期一 15时29分37秒
 *******************************************************************/

#include<iostream>
#include<vector>
int main(void)
{
	std::pair<std::string, int> temp;
	std::vector<std::pair<std::string, int> > vec;
	std::vector<std::pair<std::string, int> >::iterator iter = vec.end();
	while(std::cin >> temp.first >> temp.second)
	{
		vec.insert(iter,temp);
		iter = vec.end();
	}

	for(iter = vec.begin(); iter != vec.end(); ++iter)
	{
		std::cout << "( " << (*iter).first << ", " << (*iter).second << ")" << std::endl;
	}

	return 0;
}
