/********************************************************************
  > File Name: main.cpp
  > Author: he_CentOS
  > Mail:1778195296@qq.com 
  > Created Time: 2015年03月09日 星期一 23时17分01秒
 *******************************************************************/

#include<iostream>
using namespace std;
class point
{
	public:
		//	在下句代码前加explicit可防止point a = 1这种隐性转换
		point(int x = 0, int y = 0)     //  #1
		{
			cout << "默认构造函数 " << x << " " << y << endl;
			x_ = x;
			y_ = y;
		}

		//	在下句代码前加explicit可防止point a = b这种隐性转换，其中b为point类型
		point(const point &cp)	//	#2
		{
			cout << "拷贝构造函数 " << endl;
			x_ = cp.x_;
			y_ = cp.y_;
		}

		~point()
		{
			cout << "析构函数 " << this -> x_ << " " << this -> y_ << endl;
		}

		point &operator=(const point &cp)	//	#3
		{
			cout << "赋值重载函数" << endl;
			if(this != &cp)
			{
				this -> x_ = cp.x_;
				this -> y_ = cp.y_;
			}
			return (*this);
		}

		void print()
		{
			cout << "x_ = " << x_ << endl;
			cout << "y_ = " << y_ << endl;
		}

	private:
		int x_;
		int y_;
};

point fun()				//	#4
{
	point a(3,4);
	return a;
}

//	全局变量调用构造函数先于局部变量	调用析构函数晚于局部变量
point b(1,2);			//	#5
point fun2()
{
	return b;
}

point fun3(point c)		//	#6
{
	return c;
}

int main(void)
{
	cout << "--------外部函数--------" << endl << "fun().print();" << endl;	//	#7
	//	默认构造函数	析构函数	这是程序输出结果，亦是#7模块代码调用顺序，下同
	fun().print();	//	在本句代码结束之后，在下句代码结束之前，才调用析构函数析构fun()中局部变量a
	cout << endl;

	cout << "point d = fun();" << endl;										//	#8
	//	默认构造函数
	point d = fun();	//	本句并不调用#2拷贝构造函数	也不调用#3赋值重载函数
	cout << endl;

	cout << "fun2();" << endl;												//	#9
	//	拷贝构造函数	析构函数
	fun2();
	cout << endl;

	cout << "point e = fun2();" << endl;									//	#10
	//	拷贝构造函数
	point e = fun2();
	cout << endl;

	cout << "fun3(d);" << endl;												//	#11
	//	拷贝构造函数	拷贝构造函数	析构函数	析构函数
	fun3(d);
	cout << endl;

	cout << "point f = fun3(d);" << endl;									//	#12
	//	拷贝构造函数	拷贝构造函数	析构函数
	point f = fun3(d);
	cout << endl;
	
	cout << "--------内部函数--------" << endl << endl;

	cout << "point g = point();" << endl;									//	#13
	//	默认构造函数
	point g = point();
	cout << endl;

	cout << "point h = 1;" << endl;											//	#14
	//	默认构造函数
	point h = 1;	//	隐性转换，普通类型转换为类类型，相当于调用point(1,0)构造对象h
	cout << endl;

	return 0;
}
