/********************************************************************
	> File Name: main.cpp
	> Author: he_CentOS
	> Mail:1778195296@qq.com 
	> Created Time: 2015年03月07日 星期六 09时14分42秒
 *******************************************************************/

#include<iostream>
class tag
{
	public:
		//按照成员变量的声明顺序构造成员变量
		tag(int ival):ival2_(ival), ival1_(ival2_), ival_(ival){}

		void print()
		{
			std::cout << "ival1_ = " << ival1_ << std::endl
				<< "ival2_ = " << ival2_ << std::endl
				<< "ival_ = " << ival_ << std::endl;
		}
	private:
		int ival_;
		int ival1_;
		int ival2_;
};
int main(void)
{
	tag a(3);
	a.print();

	return 0;
}
