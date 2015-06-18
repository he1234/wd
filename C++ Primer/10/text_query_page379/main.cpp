/********************************************************************
	> File Name: main.cpp
	> Author: he_CentOS
	> Mail:1778195296@qq.com 
	> Created Time: 2015年04月04日 星期六 23时19分22秒
 *******************************************************************/

#include "text_query.h"

std::string make_plural(std::set<text_query::line_no>::size_type size, const std::string &str, const std::string &ending)
{
	return (size == 1) ? str : str + ending;
}

void print_set(std::set<text_query::line_no> ret_set, std::string word, text_query tq)
{
	std::set<text_query::line_no>::size_type size = ret_set.size();
	std::cout << "\n" << word << " occurs " << size << " " << make_plural(size, "time", "s") << std::endl;

	std::set<text_query::line_no>::const_iterator it = ret_set.begin();
	for(; it != ret_set.end(); ++it)
	{
		std::cout << "\t(line " << (*it) + 1 << ")" << " " << tq.text_line(*it) << std::endl;
	}
}

int main(void)
{
	std::ifstream infile;
	infile.open(input_text.c_str());
	if(!infile)
	{
		std::cerr << "No input file!" << std::endl;
		return -1;
	}

	text_query tq;
	tq.read_file(infile);

	std::string word;
	while(std::cin >> word)
	{
		std::set<text_query::line_no> ret_set = tq.run_query(word);
		print_set(ret_set, word, tq);
	}
	return 0;
}
