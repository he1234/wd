/********************************************************************
	> File Name: ./main.cpp
	> Author: he_CentOS
	> Mail:1778195296@qq.com 
	> Created Time: 2015年03月08日 星期日 14时47分19秒
 *******************************************************************/

#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<sstream>
int main(void)
{
	std::ifstream ifs("in.txt");
	std::vector<std::string> vec_str;
	std::string line, word;
	std::string::size_type i;
	//输入容器
	
	std::stringstream ss;//tag1
	while(getline(ifs, line))
	{
		for(i = 0; i != line.size(); ++i)
		{
			if(!isalpha(line[i]))
				line[i] = ' ';
		}
		//可用下句代码替换tag1和tag2,因为ss为局部变量，无需恢复流的状态
//		std::stringstream ss(line);
		ss << line;
		while(ss >> word)
		{//每次往容器中添加一个单词
			vec_str.push_back(word);
			std::cout << word << "--";
		}
		ss.clear();//tag2：在while循环外声明流时，循环结束时，必须恢复流的状态，否则出错。参考C++ Primer page253
	}

	std::vector<std::string>::iterator iter = vec_str.begin();
	std::vector<int>::size_type index;

	//小写转换为大写
	for(;iter != vec_str.end(); ++iter)
	{
		for(index = 0; index != (*iter).size(); ++index)
		{
			if(islower((*iter)[index]))
			{
				(*iter)[index] = toupper((*iter)[index]);
			}
		}
	}
	
	//每行8个单词输出
	i = 0;
	std::ofstream ofs("out.txt");
	for(iter = vec_str.begin(); iter != vec_str.end(); ++iter)
	{
		ofs << *iter << "    ";
		if((++i)%8 == 0)
		{
			ofs << std::endl;
		}
	}
	std::cout << std::endl;

	return 0;
}
