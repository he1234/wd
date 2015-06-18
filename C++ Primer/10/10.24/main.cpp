/********************************************************************
  > File Name: main.cpp
  > Author: he_CentOS
  > Mail:1778195296@qq.com 
  > Created Time: 2015年03月22日 星期日 21时24分39秒
 *******************************************************************/

#include<iostream>
#include<string>
#include<set>
#include<map>
#include<fstream>
#include<sstream>

const std::string remove_file("remove_word.txt");
const std::string input_file("input_file.txt");
const std::string output_file("output_file.txt");

int main(void)
{
	std::ifstream ifs_remove(remove_file.c_str());
	if(!ifs_remove)
	{
		std::cerr << "error: unable open input file: " << remove_file.c_str() << std::endl;
		return -1;
	}
	std::set< std::string > set_remove;
	std::string word_remove;
	while(ifs_remove >> word_remove)
	{
		set_remove.insert(word_remove);
	}
	ifs_remove.close();

	std::string line, word;
	std::ifstream ifs_input(input_file.c_str());
	if(!ifs_input)
	{
		std::cerr << "error: unable open input file: " << input_file.c_str() << std::endl;
		return -1;
	}
	std::ofstream ofs_output(output_file.c_str());
	if(!ofs_output)
	{
		std::cerr << "error: unable open output file: " << output_file.c_str() << std::endl;
		return -1;
	}
	bool is_first_word;
	while(getline(ifs_input, line))
	{
		is_first_word = true;
		std::istringstream iss(line);
		while(iss >> word)
		{
			if(word[word.size() - 1] == 's' && !set_remove.count(word))
			{
				word = word.substr(0, word.size() - 1);
			}

			if(is_first_word)
			{
				is_first_word = false;
				ofs_output << word;
			}
			else
			{
				ofs_output << ' ' << word;
			}
		}
		ofs_output << std::endl;
	}
	ifs_input.close();
	ofs_output.close();

	return 0;
}
