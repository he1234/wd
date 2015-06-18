/********************************************************************
	> File Name: main.cpp
	> Author: he_CentOS
	> Mail:1778195296@qq.com 
	> Created Time: 2015年03月20日 星期五 22时57分05秒
 *******************************************************************/

#include<iostream>
#include<vector>
#include<string>
const int MIN_LEN_INIT = 99999;
const int MAX_LEN_INIT = 0;

int main(void)
{//统计sentence中的单词数量，并输出全部最长的单词和最短的单词
	std::string line1 = "We were her pride of 10 she named us:";
	std::string line2 = "Benjamin, Phoenix, the Prodigal";
	std::string line3 = "and perspicacious pacific Suzanne";
	std::string sentence = line1 + ' ' + line2 + ' ' + line3;
	std::string elements ("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789");

	std::vector<std::string> longest_word, shortest_word;
	std::string word;
	std::string::size_type min_len = MIN_LEN_INIT, max_len = MAX_LEN_INIT, word_len;
	std::string::size_type start_pos = 0, end_pos = 0;
	size_t cnt = 0;

	while((start_pos = sentence.find_first_of(elements, end_pos)) != std::string::npos)
	{
		++cnt;
		end_pos = sentence.find_first_not_of(elements, start_pos);
		if(end_pos == std::string::npos)
		{
			word_len = sentence.size() - start_pos;
		}
		else
		{
			word_len = end_pos - start_pos;
		}
		word = sentence.substr(start_pos, word_len);
		if(word_len >= max_len)
		{
			if(word_len != max_len)
			{
				max_len = word_len;
				longest_word.clear();
			}
			longest_word.push_back(word);
		}
		if(word_len <= min_len)
		{
			if(word_len != min_len)
			{
				min_len = word_len;
				shortest_word.clear();
			}
			shortest_word.push_back(word);
		}
	}
	//输出结果
	std::cout << "cnt : " << cnt << std::endl;
	std::cout << "longest word is : ";
	std::vector<std::string>::iterator iter = longest_word.begin();
	while(iter != longest_word.end())
	{
		std::cout << *iter++ << "\t";
	}
	std::cout << std::endl;

	std::cout << "shortest word is : ";
	iter = shortest_word.begin();
	while(iter != shortest_word.end())
	{
		std::cout << *iter++ << "\t";
	}
	std::cout << std::endl;

	return 0;
}
