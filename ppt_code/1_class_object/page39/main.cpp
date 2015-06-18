/********************************************************************
	> File Name: main.cpp
	> Author: he_CentOS
	> Mail:1778195296@qq.com 
	> Created Time: 2015年03月12日 星期四 16时12分45秒
 *******************************************************************/

#include<iostream>
using namespace std;
class computer
{
	private:
		float price;
		static float total_price;
	public:
		computer(const float pri)
		{
			price = pri;
			total_price += pri;
		}
		~computer()
		{
			total_price -= price;
		}

		void print()
		{
			cout << "总价 ：" << total_price << endl;
		}
};

float computer::total_price = 0;	//静态数据成员的初始化必须在类申明之外进行，且不再包含static关键字
//	float computer::total_price(0);
int main(void)
{
	computer first(5000);
	first.print();

	computer second(3000);
	second.print();

	first.~computer();
	second.print();

	cout << "sizeof(second) :" << sizeof(second) << endl;

	return 0;
}
