/********************************************************************
  > File Name: ./main.cpp
  > Author: he_CentOS
  > Mail:1778195296@qq.com 
  > Created Time: 2015年03月12日 星期四 15时10分22秒
 *******************************************************************/

#include <iostream>
using namespace std;
class point
{
	private:
		int yPos;
		int &ref1;		//	#2	用初始化表初始化,初始化的顺序和声明时的顺序一致
		int xPos;
		double &ref2;	//	#1	引用成员的初始化必须放在初始化表中

	public:
		point(int x, int y, double &z):ref2(z),ref1(x)
		{//		#3	初始化成员列表的赋值语句先执行，构造函数体中的赋值语句后执行
			xPos = ref1;
			yPos = y;
		}

		//		#4	复制构造函数与此一致：引用成员的初始化同样要放在初始化表中
		point(const point &pt):ref1(pt.ref1), ref2(pt.ref2)
		{
			xPos = pt.xPos;
			yPos = pt.yPos;
		}
		void print()
		{
			cout << "xPos: " << xPos << ", yPos: " << yPos;
			cout << ", ref1:  " << ref1 << ", ref2:  " << ref2 << endl;
		}
		void SetX(int x)
		{
			xPos = x;
		}
};

int main()
{
	double outInt = 5.0;
	point pt1(3, 4, outInt);
	pt1.print();

	point pt2(pt1);
	pt2.print();

	cout << endl << "改变pt1中的x后" << endl;
	pt1.SetX(7);
	pt1.print();
	pt2.print();

	outInt = 6;
	cout << endl << "outInt变化后：" << endl;
	pt1.print();
	pt2.print();

	return 0;
}
