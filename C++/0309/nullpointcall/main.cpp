/********************************************************************
  > File Name: main.cpp
  > Author: he_CentOS
  > Mail:1778195296@qq.com 
  > Created Time: 2015年03月13日 星期五 16时40分53秒
 *******************************************************************/

#include <iostream>

class CNullPointCall
{
	public:

		static void test1();
		void test2();
		void test3(int ival);
		void test4();
	private:
		static int iStatic_;
		int ival_;
};

int CNullPointCall::iStatic_ = 0;
void CNullPointCall::test1()
{
	std::cout << "test1() : iStatic_ = " << iStatic_ << std::endl;
}


void CNullPointCall::test2()
{
//	this = NULL;
	std::cout << " test2() " << std::endl;
}

void CNullPointCall::test3(int ival)
{
	//this = NULL;
	std::cout << "test3() : ival = " << ival << std::endl;
}


void CNullPointCall::test4()
{//出现段错误，因为this为NULL
	std::cout << "test4() : ival_ = " << this->ival_ << std::endl;
}

int main()
{
	CNullPointCall *q;
	CNullPointCall *p = NULL;
	p->test1();
	p->test2();
	p->test3(4);
	p->test4();
	return 0;
}
