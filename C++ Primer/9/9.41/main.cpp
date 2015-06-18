/********************************************************************
	> File Name: main.cpp
	> Author: he_CentOS
	> Mail:1778195296@qq.com 
	> Created Time: 2015年03月21日 星期六 10时36分00秒
 *******************************************************************/

#include<iostream>
#include<string>
#include<algorithm>
int main(void)
{
	std::string generic1("Dear Ms Daisy:");
	std::string generic2("MrsMsMissPeople");
	std::string greet(std::string form, std::string lastname, std::string title, std::string::size_type pos, int length);

	std::string lastname("AnnaP");
	std::string sentence = greet(generic1, lastname, generic2, 5, 4);
	std::cout << sentence << std::endl;
	return 0;
}

std::string greet(std::string form, std::string lastname, std::string title, std::string::size_type pos, int length)
{
	std::string sentence(form);
	sentence.replace(5, 2, title, pos, length);
	sentence.replace(sentence.find("Daisy"), sentence.find("Daisy") + 5, lastname);
	return sentence;
}
