/********************************************************************
  > File Name: main.cpp
  > Author: he_CentOS
  > Mail:1778195296@qq.com 
  > Created Time: 2015年03月12日 星期四 16时52分51秒
 *******************************************************************/


//代码8-19
#include <iostream>
using namespace std;

class point
{
	int x; 
	int y;

	public:
		point(int xp = 0, int yp = 0) //构造函数
		{
			x = xp;
			y = yp;
		}

		void print() const //const成员函数内无法修改数据成员，否则编译器报错
		{
//			x = 5; //1. 试图修改x将引发编译器报错
//			set(); //2. 试图调用非const函数将引发编译器报错
			cout << "x: " << x << " ,y: " << y << endl;
		}

		void set() //将set()定义成const函数就能解决问题
		{
		}
};

int main()
{
	point pt;		//声明类对象，以缺省参数形式调用构造函数
	pt.print();		//调用const成员函数

	return 0;
}

