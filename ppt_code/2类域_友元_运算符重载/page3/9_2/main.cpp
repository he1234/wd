/********************************************************************
  > File Name: main.cpp
  > Author: he_CentOS
  > Mail:1778195296@qq.com 
  > Created Time: 2015年03月13日 星期五 23时32分12秒
 *******************************************************************/

//9-2 嵌套类(类中类)
#include <iostream>
using namespace std;

class line
{
	public:
		class point 
		{
			private: 
				int x;
				int y;

			public:
				point(int xp = 0, int yp = 0)
				{
					x = xp;
					y = yp;
				}

				void printpoint();
		};

	private:
		point p1, p2;

	public:
		line(int x1, int y1, int x2, int y2):p1(x1, y1), p2(x2, y2)//构造函数，初始化表
		{
		}

		void printline() //输出提示信息
		{
			p1.printpoint(); //调用对象成员的公共接口
			cout << "  ------->  ";
			p2.printpoint(); //调用对象成员的公共接口
			cout << endl;
		}
};

void line::point::printpoint() //point类中函数printpoint()的实现，注意双重作用域限定符
{
	cout << "( " << x << " , " << y << " )";
}

int main()
{
	line line1(1, 2, 3, 4);	//调用line类构造函数，声明一个line类的对象line1
	line1.printline();		//输出提示信息

	line::point pt(1, 3);	//以line::point访问point类定义，声明一个point类的对象pt
	pt.printpoint();		//输出提示信息

	cout << endl;
	return 0;
}
