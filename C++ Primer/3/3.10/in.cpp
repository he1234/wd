/********************************************************************
	> File Name: ./main.cpp
	> Author: he_CentOS
	> Mail:1778195296@qq.com 
	> Created Time: 2015年03月06日 星期五 19时27分04秒
 *******************************************************************/

#include<iostream>
#include<vector>
#include<fstream>

int main(void)
{
	std::ifstream ifs("int.txt");
	if(!ifs.good())
	{
		std::cout << "open int.txt failure!" << std::endl;
		return -1;
	}
	int num;
	int index = 0;
	std::vector<int> vec;
	while(ifs >> num)
	{
		vec.push_back(num);
		++ index;
		if(0 == index%2)
		{
			std::cout << vec[index - 1] + vec[index - 2] << std::endl;
		}
	}
	std::cout << vec[index -1] << std::endl;
	if(1 == index%2)
	{	
		std::cout << "The last one is not been added!" << std::endl;
	}

	std::cout << "-------------------" << std::endl;
	int si = vec.size();
	std::cout << "si = " << si << std::endl;
	for(index = 0;index != si/2 ;index++)
	{
		std::cout << index << " and " << si - index << " is " << vec[index] + vec[si - 1- index] << std::endl;
	}
	if(1 == si%2)
	{
		std::cout << "The middle element is :" << vec[index] << std::endl;
	}
	return 0;
}
