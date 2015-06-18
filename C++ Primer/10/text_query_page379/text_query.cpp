/********************************************************************
	> File Name: text_query.cpp
	> Author: he_CentOS
	> Mail:1778195296@qq.com 
	> Created Time: 2015年04月04日 星期六 16时54分43秒
 *******************************************************************/

#include "text_query.h"

void text_query::store_file(std::ifstream& is)
{
	std::string line;
	while(getline(is, line))
	{
		lines_of_text.push_back(line);
	}

}

std::string trim_punct(const std::string &word)
{
	std::string ret;
	for(std::string::const_iterator it = word.begin(); it != word.end(); ++it)
	{
		if(!ispunct(*it))
		{
			ret += tolower(*it);
		}
	}

	return ret;
}
void text_query::build_map()
{
	line_no ix_line;
	std::string word;
	for(ix_line = 0; ix_line != lines_of_text.size(); ++ix_line)
	{
		std::istringstream iss_line(lines_of_text.at(ix_line));
		while(iss_line >> word)
		{
			word = trim_punct(word);
			if(word_map.count(word) == 0)
			{
				word_map[word].insert(ix_line);
			}
			else if(word_map[word].count(ix_line) == 0)
			{
				word_map[word].insert(ix_line);
			}
		}
	}
}

std::set<text_query::line_no> text_query::run_query(const std::string &word) const
{
	std::map<std::string, std::set<text_query::line_no> >::const_iterator it = word_map.find(word);
	if(it == word_map.end())
	{
		return std::set<line_no>();
	}
	else
	{
		return it -> second;
	}
}

std::string text_query::text_line(line_no line) const
{
	if(line < lines_of_text.size())
		return lines_of_text[line];
	else
		throw std::out_of_range("line number out of range");
}
