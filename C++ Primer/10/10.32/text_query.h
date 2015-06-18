/********************************************************************
  > File Name: text_query.h
  > Author: he_CentOS
  > Mail:1778195296@qq.com 
  > Created Time: 2015年04月04日 星期六 16时56分20秒
 *******************************************************************/

#include<iostream>
#include<vector>
#include<map>
#include<fstream>
#include<string>
#include<sstream>
#include<stdexcept>

const std::string input_text("infile.txt");

class text_query
{
	public:
		typedef std::vector<std::string>::size_type line_no;
		void read_file(std::ifstream &is)
		{
			store_file(is);
			build_map();
		}
		std::vector<line_no> run_query(const std::string &) const;
		std::string text_line(line_no) const;
	private:
		void store_file(std::ifstream&);
		void build_map();
		std::vector<std::string> lines_of_text;
		std::map<std::string, std::vector<line_no> > word_map;
};
