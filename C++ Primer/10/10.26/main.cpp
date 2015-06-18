/********************************************************************
	> File Name: main.cpp
	> Author: he_CentOS
	> Mail:1778195296@qq.com 
	> Created Time: 2015年03月23日 星期一 10时32分21秒
 *******************************************************************/

#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include<map>

const std::string input_file("input.txt");
const std::string output_file("output.txt");

int main(void)
{
	//从文件读数据到multimap
	std::ifstream ifs_input(input_file.c_str());
	if(!ifs_input)
	{
		std::cerr << "error: unable open input file : " << input_file << std::endl;
		return -1;
	}

	std::multimap< std::string, std::string > author_book;
	std::string str_author, str_book, line;
	std::istringstream iss;
	while(getline(ifs_input, line))
	{
		iss.str(line);
		if(iss >> str_author)
		{
			while(iss >> str_book)
			{
				author_book.insert(make_pair(str_author, str_book));
			}
		}
		iss.clear();//用于重置流的状态
	}

	//删除key相关的元素
	std::cin >> str_author;
	typedef std::multimap< std::string, std::string >::size_type sz_type;
	sz_type num = author_book.count(str_author);
	typedef std::multimap< std::string, std::string >::iterator iter_type;
	iter_type iter_find = author_book.find(str_author);	
	for(sz_type ix = 0; iter_find != author_book.end() && ix != num; ++ix, ++iter_find)
	{
		author_book.erase(iter_find);
	}

	//输出multimap到文件
	std::ofstream ofs_output(output_file.c_str());
	iter_type iter_ix = author_book.begin();
	while(iter_ix != author_book.end())
	{
		ofs_output << iter_ix -> first << ' ' << iter_ix -> second << std::endl;
		++iter_ix;
	}

	return 0;
}
