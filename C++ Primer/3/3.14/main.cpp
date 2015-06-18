/********************************************************************
	> File Name: main.cpp
	> Author: he_CentOS
	> Mail:1778195296@qq.com 
	> Created Time: 2015年03月06日 星期五 22时06分12秒
 *******************************************************************/

#include<iostream>
#include<fstream>
#include<string>
#include<vector>

int main(void)
{
	std::ifstream ifs("read.txt");
	std::string str;
	std::vector<std::string> vec;
	int i,j;
	while(ifs >> str)
	{
		vec.push_back(str);
	}

	for(i = 0;i != vec.size();i++ )
	{
		for(j = 0;j != vec[i].size(); j++ )
		{
			if(islower(vec[i][j]))
			{
				vec[i][j] = toupper(vec[i][j]);
			}
		}
		std::cout << vec[i] << " ";
		if(0 == i%8 )
		{
			std::cout << std::endl;
		}
	}
	std::cout << std::endl;

	return 0;
}
