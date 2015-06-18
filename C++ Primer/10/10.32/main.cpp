/********************************************************************
	> File Name: main.cpp
	> Author: he_CentOS
	> Mail:1778195296@qq.com 
	> Created Time: 2015年04月04日 星期六 23时19分22秒
 *******************************************************************/

#include "text_query.h"

std::string make_plural(std::vector<text_query::line_no>::size_type size, const std::string &str, const std::string &ending)
{
	return (size <= 1) ? str : str + ending;
}

void print_vector(std::vector<text_query::line_no> ret_vec, std::string word, text_query tq)
{
	std::vector<text_query::line_no>::size_type size = ret_vec.size();
	std::cout << "\n" << word << " occurs " << size << " " << make_plural(size, "time", "s") << std::endl;

	std::vector<text_query::line_no>::const_iterator it = ret_vec.begin();
	for(; it != ret_vec.end(); ++it)
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
		std::vector<text_query::line_no> ret_vec = tq.run_query(word);
		print_vector(ret_vec, word, tq);
	}
	return 0;
}
