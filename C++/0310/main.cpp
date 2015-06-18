/********************************************************************
  > File Name: main.cpp
  > Author: he_CentOS
  > Mail:1778195296@qq.com 
  > Created Time: 2015年03月10日 星期二 10时55分09秒
 *******************************************************************/

#include<iostream>
#include<string.h>

using namespace std;
class String
{
	public:

		String(const char *str = NULL);// 通用构造函数
		String(const String &another); // 拷贝构造函数
		~String(); // 析构函数
		String &operater=(const String &rhs); // 赋值函数
		void print();
	private:
		char *m_data;// 用于保存字符串
};

String::String(const char *str = NULL)
{
	if(str != NULL)
	{
		m_data = new char[strlen(str) + 1];
		strcpy(m_data,str);
	}
}

String::String(const String &another)
{
	m_data = new char[strlen(another.m_data) + 1]; 
	strcpy(m_data, another.m_data);
}

String::~String()
{
	if(this -> m_data != NULL)
	{
		delete []m_data;
	}
	m_data = NULL;
}
String& String::operater=(const String &ths)
{
	if(this != &ths)
	{
		~String();
		m_data = new char[strlen(ths.m_data) + 1];
		strcpy(m_data,ths.m_data);
	}
	return (*this);
}
void String::print()
{
	cout << this -> m_data << endl;
}
int main(void)
{
	String a("I am a String !");
	a.print();
	return 0;
}
