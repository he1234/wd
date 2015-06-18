/********************************************************************
	> File Name: ./main.cpp
	> Author: he_CentOS
	> Mail:1778195296@qq.com 
	> Created Time: 2015年03月06日 星期五 10时27分05秒
 *******************************************************************/

#include<iostream>
#include<fstream>
#include<vector>

int main(void)
{//打印iol.cc
	std::ifstream ifs("iol.cc");
	if(!ifs.good())
	{
		std::cout << "open file error!" << std::endl;
		return -1;
	}
/*
	std::string s;
	while(ifs >> s)
	{//字符串输入时，遇到空格会停下
		std::cout << s << std::endl;
	}
*/
	std::cout << "---------------------" << std::endl;
	std::vector<std::string> vec_str;
	std::string line;
	while(getline(ifs,line))
	{
		std::cout << line << std::endl;
		vec_str.push_back(line);
	}

	std::vector<std::string>::iterator sit = vec_str.begin();
	int i = 0;
	for(;sit!=vec_str.end();++sit,++i)
	{//++sit表示指向容器的下一个元素，这里是一行
		std::cout << *sit << std::endl;
	}
	std::cout << "i = " << i << std::endl;

	return 0;
}

/*
int main(void)
{//把iol.cc的内容copy到text.txt
	std::ifstream ifs("iol.cc");
	if(!ifs.good())
	{
		std::cout << "open file error!" << std::endl;
		return -1;
	}

	std::ofstream ofs("test.txt");
	std::string line;
	while(getline(ifs,line))
	{
		ofs << line << std::endl;
	}

	return 0;
}
*/
