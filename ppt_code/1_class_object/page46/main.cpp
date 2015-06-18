/********************************************************************
  > File Name: main.cpp
  > Author: he_CentOS
  > Mail:1778195296@qq.com 
  > Created Time: 2015年03月12日 星期四 23时44分02秒
 *******************************************************************/

//代码8-21
#include <iostream>
using namespace std;

class cex
{
	private:
		int a;			//int型，在一般系统上占据4个内存字节	4
		char b;			//char型，占1个内存字节					1 + 3 (3浪费)
		float c;		//单精度浮点型，占4个内存字节			4 + 4 (4浪费)
		double d;		//double型，占8个内存字节				8
		short e[5];		//short型数组，每个元素占2个内存字节	8 + 2 + 6 (6浪费)
		char & f;		//引用，当成指针维护					8
		double & g;		//引用，当成指针维护					8
		static int h;	//static成员，公共内存，不影响单个对象的大小 0

	public:
		cex():f(b),g(d) //和构造函数，引用成员必须在初始化表中初始化
		{
		}
		void print()	//成员函数的定义，普通成员函数不影响对象大小
		{
			cout << "Hello" << endl;
		}
};

class cla
{
	private:
		int *val;
		char *buf;
	public:
		cla()
		{
			val = NULL;
			buf = NULL;
		}
		~cla()
		{
		}

		void print()
		{
			cout << "cla class" << endl;
		}
};

int cex::h = 0;		//static成员的初始化

int main()
{
	cex c;
	cout << "sizeof(cex):	" << sizeof(cex) << endl; //输出类对象的大小sizeof(cex) = 56

	cla a;
	cout << "sizeof(cla):	" << sizeof(cla) << endl;
	return 0;
}
