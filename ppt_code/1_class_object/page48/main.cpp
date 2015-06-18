/********************************************************************
  > File Name: main.cpp
  > Author: he_CentOS
  > Mail:1778195296@qq.com 
  > Created Time: 2015年03月13日 星期五 00时40分24秒
 *******************************************************************/

//对象数组的声明
#include <iostream>
using namespace std;

class point
{
	private:
		int x;
		int y;

	public:
		//	point(int ix = 0, int iy = 0)
		point(int ix, int iy)
		{
			static int iCount = 0;
			iCount++;
			cout << iCount << " .构造函数被调用" << endl;
			x = ix;
			y = iy;
		}
};

int main()
{
	//错误: 没有合适的构造函数
	point pt1[2];
	cout << endl;

	//正确
	point pt2[2] = {point(1,2), point(3,4)};
	cout << endl;

	//正确, 自动确定数组的元素个数
	point pt3[] = {point(1,2), point(3,4)};
	cout << endl;
	
	//错误: 后3个元素会自动调用无参的构造函数，但这样的构造函数不存在
	point pt4[5] = {point(1,2), point(3,4)};
	cout << endl;

	//解决方法: 给上述构造函数的2个参数定义缺省值
	return 0;
}
