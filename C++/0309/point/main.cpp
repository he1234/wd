/********************************************************************
  > File Name: main.cpp
  > Author: he_CentOS
  > Mail:1778195296@qq.com 
  > Created Time: 2015年03月09日 星期一 14时58分59秒
 *******************************************************************/
#include <iostream>

class Point
{
	public:
		Point(int x = 0, int y = 0)
		{
			std::cout << "调用构造函数 " << std::endl;

			ix_ = x;
			iy_ = y;
		}

		Point(const Point &rhs)
		{
			std::cout << "调用复制构造函数" << std::endl;
			ix_ = rhs.ix_;
			iy_ = rhs.iy_;
		}

		void print()
		{
			std::cout << "(" << ix_ << ", " << iy_ << ")" << std::endl;
		}
	private:
		int ix_;
		int iy_;
};


int main()
{//下述#1，#2均调用拷贝构造函数
	Point pt1(3, 4);
	pt1.print();

	std::cout << "------------------------" << std::endl;
	Point pt2 = pt1;//	#1
	pt2.print();

	std::cout << "------------------------" << std::endl;
	Point pt3;
	pt3.print();

	std::cout << "------------------------" << std::endl;
	Point pt4(pt1);	//	#2
	pt4.print();

	std::cout << "------------------------" << std::endl;
	Point pt5;
	std::cout << "########################" << std::endl;
	pt5 = pt1;	//此并非拷贝构造函数，而是调用赋值函数
	pt5.print();

	return 0;
}
