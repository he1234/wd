/********************************************************************
  > File Name: main.cpp
  > Author: he_CentOS
  > Mail:1778195296@qq.com 
  > Created Time: 2015年03月09日 星期一 16时57分03秒
 *******************************************************************/

//为了防止CPoint pt = 2;和CPoint pt2 = pt1;这种隐性转换，可以在相应的构造函数前增加explicit标识符
#include <iostream>
using namespace std;

class CPoint
{
	protected:
		int x;
		int y;

	public:
		//缺省构造函数,如果定义类时未指定任何构造函数，
		//系统将自动生成不带参数的缺省构造函数
		CPoint()
		{
			cout << "默认构造函数 " << this << " ";
			x = 0;
			y = 0;
		}

		//带一个参数的可用于类型转换的构造函数
		//	explicit	//加上 explicit 可防止 CPoint pt1 = 1; 这种隐性转换
		CPoint(int ix)
		{
			cout << "1参数构造函数 " << this << " ";
			x = ix;
			y = 0;
		}

		//带参数的构造函数
		CPoint(int ix, int iy)
		{
			cout << "2参数构造函数 " << this << " ";
			x = ix;
			y = iy;
		}

		//拷贝构造函数,如果此函数不定义，系统将生成缺省拷贝构造函数功能,
		//缺省拷贝构造函数的行为是：用传入的对象参数的成员初始化正要建立的对象的相应成员
		//	explicit	//加上 explicit 可防止 CPoint pt2 = pt1; 这种隐性转换
		CPoint(const CPoint &cp)
		{
			cout << "拷贝构造函数 " << this << " ";
			x = cp.x;
			y = cp.y;
		}

		CPoint &operator=(const CPoint &cp)
		{
			cout << "赋值重载函数 " << this << " ";
			if (this != &cp)
			{
				x = cp.x;
				y = cp.y;
			}
			return (*this);
		}

		//析构函数，一个类中只能有一个析构函数,如果用户没有定义析构函数，
		//系统会自动未类生成一个缺省的析构函数
		~CPoint()
		{
			cout << "析构函数 " << this << endl;
		}
};

int main(int argc, char* argv[])
{//	1_类和对象.ppt	page33备注代码
	CPoint p0();		//这是函数的声明，不是实例化类

	cout << endl << "CPoint pt1;\t\t";
	CPoint pt1;			//缺省构造函数

	cout << endl << "CPoint pt2(1);\t\t";
	CPoint pt2(1);		//一个参数的构造函数

	cout << endl << "CPoint pt3(1, 2);\t";
	CPoint pt3(1, 2);	//两个参数的构造函数

	cout << endl << "CPoint pt4 = 1;\t\t";
	CPoint pt4 = 1;		//	!!	等价于CPoint t4(1);	//explicit

	cout << endl << "CPoint pt5 = t1;\t";
	CPoint pt5 = pt1;	//CPoint(t1);



//以下较难-----------------------------------------------------------
	cout << endl << "---------------------------------------------------------" << endl;


	cout << endl << "CPoint pt6 = CPoint();\t";
	CPoint pt6 = CPoint();	//	!!	默认构造函数

	cout << endl << "pt6 = CPoint(1);\t";
	pt6 = CPoint(1);	//	!!	1参数构造函数，赋值重载函数，析构函数

	cout << endl << "pt6 = 1;\t\t";
	pt6 = 1;			//首先调用单个参数的构造函数，生成临时对象CPoint(1), 然后调用赋值运算符函数，析构函数析构CPoint(1)

	cout << endl << "pt6 = t1;\t\t";
	pt6 = pt1;			//调用赋值运算符函数

	cout << endl << endl;
	return 0;
}
