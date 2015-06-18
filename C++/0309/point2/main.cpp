/********************************************************************
  > File Name: main.cpp
  > Author: he_CentOS
  > Mail:1778195296@qq.com 
  > Created Time: 2015年03月09日 星期一 15时15分01秒
 *******************************************************************/

#include <iostream>

class Point
{
	public:
		//加上explicit会拒绝#1隐式转换，具体表现为编译出错
		explicit Point(int x = 0, int y = 0)
		{
			std::cout << "调用构造函数 " << std::endl;

			ix_ = x;
			iy_ = y;
		}

		//加上explicit会拒绝#2隐式转换
		explicit Point(const Point &rhs)
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
{//隐式转换，详见:  1_类和对象.ppt  page33
#if 0
	Point pt1 = 1;//#1隐式转换
	pt1.print();
#endif
	Point pt2(3,4);
	pt2.print();

	Point pt3 = pt2;//#2隐式转换

	return 0;
}
