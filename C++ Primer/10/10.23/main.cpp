/********************************************************************
	> File Name: main.cpp
	> Author: he_CentOS
	> Mail:1778195296@qq.com 
	> Created Time: 2015年03月22日 星期日 20时22分24秒
 *******************************************************************/

#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<fstream>
const std::string in_file_name("input.txt");

int main(void)
{
	std::map< std::string, int > word_count;
	std::ifstream remove_file(in_file_name.c_str());
	void restricted_wc(std::ifstream &remove_file, std::map< std::string, int > &word_count);
	void print_map(std::map< std::string, int> &word_count);

	restricted_wc(remove_file, word_count);
	print_map(word_count);

	return 0;
}

void restricted_wc(std::ifstream &remove_file, std::map< std::string, int > &word_count)
{
	std::string remove_word;
	std::vector< std::string > vec;
	while(remove_file >> remove_word)
	{
		vec.push_back(remove_word);
	}

	std::string word;
	while(std::cin >> word)
	{
		std::vector< std::string > ::iterator it_vec = vec.begin();
		while(it_vec != vec.end() && *it_vec != word)
		{
			++it_vec;
		}
		if( it_vec == vec.end())
		{
			++word_count[word];
		}
	}
}
void print_map(std::map< std::string, int> &word_count)
{
	std::map< std::string, int>::const_iterator it_map;
	for(it_map = word_count.begin(); it_map != word_count.end(); ++it_map)
	{
		std::cout << it_map -> first << '\t' << it_map -> second << std::endl;
	}
}
