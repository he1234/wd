/********************************************************************
	> File Name: ./main.cpp
	> Author: he_CentOS
	> Mail:1778195296@qq.com 
	> Created Time: 2015年03月07日 星期六 18时02分44秒
 *******************************************************************/

#include<iostream>
#include<string>
#include<fstream>

int main(void)
{//从文件中输入文本，去除标点，输出到文本
	std::string line;
	std::string str;
	std::ifstream ifs("in.cpp");
	std::ofstream ofs("out.cpp");
	while(getline(ifs, line))
	{
		str = "";
		for(std::string::size_type idx = 0; idx != line.size(); idx++)
		{
			if(!ispunct(line[idx]))
			{
				str = str + line[idx];
			}
		}
		ofs << str << std::endl;
	}

	return 0;
}
