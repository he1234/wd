/********************************************************************
  > File Name: main.cpp
  > Author: he_CentOS
  > Mail:1778195296@qq.com 
  > Created Time: 2015年03月22日 星期日 13时12分10秒
 *******************************************************************/

#include<iostream>
#include<string>
#include<map>
#include<sstream>
#include<fstream>
const std::string config_file_path("map_config.txt");
const std::string input_file_path("trans.txt");
const std::string output_file_path("out_file");
int main(void)
{
	std::ifstream open_map_config(config_file_path.c_str());
	if(!open_map_config)
	{
		std::cerr << "error: unable to open input file : " << config_file_path << std::endl;
		return -1;
	}

	std::string str_first, str_second;
	std::pair< std::map<std::string, std::string>::iterator, bool> ret;
	std::map<std::string, std::string> map_match;
	while(open_map_config >> str_first && open_map_config >> str_second)
	{
		ret = map_match.insert(make_pair(str_first, str_second));
	}
	open_map_config.close();

	std::ifstream in_trans(input_file_path.c_str());
	if(!in_trans)
	{
		std::cerr << "error: unable to open input file" << input_file_path << std::endl;
		return -1;
	}
	std::ofstream out_file(output_file_path.c_str());
	if(!out_file)
	{
		std::cerr << "error: unable to open input file" << output_file_path << std::endl;
		return -1;
	}

	std::string line;
	std::string word;
	std::map<std::string, std::string>::const_iterator iter;
	while(getline(in_trans, line))
	{
		bool firstword = true;
		std::istringstream ss;
		ss.str(line);
		while(ss >> word)
		{
			iter = map_match.find(word);
			if(iter != map_match.end())
			{
				word = iter -> second;
			}
			if(firstword)
			{
				out_file << word;
				firstword = false;
			}
			else
			{
				out_file << ' ' << word;
			}

		}
		out_file << std::endl;
	}
	in_trans.close();
	out_file.close();

	return 0;
}
