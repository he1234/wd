/********************************************************************
  > File Name: main.cpp
  > Author: he_CentOS
  > Mail:1778195296@qq.com 
  > Created Time: 2015年03月12日 星期四 14时42分59秒
 *******************************************************************/

//8-12 const成员变量的初始化不能在构造函数体内进行
#include <iostream>
using namespace std;

class point
{
	private:
		const int xPos; //符号常量成员xPos和yPos
		const int yPos;

	public:
//		point(int x, int y)					#1
//		{
//			xPos = x; //错误，无法直接赋值
//			yPos = y;
//		}

		point(int x, int y):xPos(x),yPos(y)
		{//const数据成员只能在初始化表中进行初始化,#1代码块有误
		}

		point(const point &pt):xPos(pt.xPos),yPos(pt.yPos)
		{//const数据成员只能在初始化表中进行初始化，#2代码块有误

		}
		
//		point(const point & pt)				#2
//		{
//			xPos = pt.xPos;
//			yPos = pt.yPos;
//		}

		void print()
		{
			cout << "xPos: " << xPos << ",yPos: " << yPos << endl;
		}
};

int main()
{
	point pt1(3, 4);//调用有参构造函数
	pt1.print();

	point pt2(pt1);//调用复制构造函数
	pt2.print();

	return 0;
}
