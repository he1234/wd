/********************************************************************
  > File Name: main.cpp
  > Author: he_CentOS
  > Mail:1778195296@qq.com 
  > Created Time: 2015年03月12日 星期四 16时33分10秒
 *******************************************************************/

#include <iostream>
#include<string.h>
using namespace std;
class computer
{
	private:
		char *name;
		float price;
		static float total_price; //静态数据成员
	public:
		computer(const char *chr, const float p) //构造函数，模拟买电脑操作
		{
			name = new char[strlen(chr) + 1];
			strcpy(name, chr);
			price = p;
			total_price += p;
		}
		~computer() //析构函数，模拟退掉电脑的操作
		{
			if (name)
			{
				delete[] name;
				name = NULL;
			}
			total_price -= price;
		}

		//静态数据成员可以定义在类内部，或定义在类外部；静态数据成员则不然，必须在类外定义全局变量的地方初始化
		static void print_total() //静态成员函数，原则上只能访问静态数据成员
		{
			cout << "总价：" << total_price << endl;
		}
		static void print(computer &com); //静态成员函数如果要访问某具体对象，必须传递参数
};

void computer::print(computer &com) //该函数因为使静态成员，所以放在类外声明
{
	cout << "名称" << com.name << endl;
	cout << "价格" << com.price << endl;
}

float computer::total_price = 0; //初始化
int main()
{
	computer comp1("IBM", 7000); 
	computer::print(comp1); //访问statci成员函数直接在其前面加类名和::即可。静态成员函数如果要访问具体对象，必须传递参数
	computer::print_total(); //类名加作用域限定符访问statci成员函数

	computer comp2("ASUS", 4999); 
	computer::print(comp2); //类名加作用域限定符访问statci成员函数，传递参数comp2
	computer::print_total();

	comp2.~computer(); //析构函数调用，退还电脑
	computer::print_total();

	return 0;
}

