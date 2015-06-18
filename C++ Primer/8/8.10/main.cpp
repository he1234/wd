/********************************************************************
	> File Name: main.cpp
	> Author: he_CentOS
	> Mail:1778195296@qq.com 
	> Created Time: 2015年03月09日 星期一 00时20分49秒
 *******************************************************************/

#include<iostream>
#include<string>
#include<fstream>
#include<vector>

int main(void)
{
	std::ifstream read_file("in.txt");
	if(!read_file)
	{
		std::cerr << "open in.txt failure" << std::endl;
		return -1;
	}

	std::string word;
	std::vector<std::string> vec_str;
	while(read_file >> word)
	{
		vec_str.push_back(word);
	}
	read_file.close();

	std::vector<std::string>::const_iterator iter = vec_str.begin();
	for(;iter != vec_str.end(); ++iter)
	{
		std::cout << *iter << " " << std::endl;
	}

	return 0;
}
