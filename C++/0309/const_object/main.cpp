/********************************************************************
  > File Name: main.cpp
  > Author: he_CentOS
  > Mail:1778195296@qq.com 
  > Created Time: 2015年03月13日 星期五 16时17分10秒
 *******************************************************************/

#include <iostream>

class Point
{
	public:
		Point(int ix = 0, int iy = 0) : ix_(ix), iy_(iy)
		{
		}

		void print() const
		{
			std::cout << "(" << ix_ << ", " << iy_ << ")" << std::endl;
		}

		void print2()
		{

			ix_ = 10;
			iy_ = 11;
		}
	private:
		int ix_;
		int iy_;

};

int main(void)
{
	Point pt(3, 4);
	pt.print();//非const对象调用了一个const的成员函数

	const Point pt2(5,6);
	pt2.print2();//const对象调用了一个非const的成员函数,编译会出错
	return 0;
}
