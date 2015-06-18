/********************************************************************
  > File Name: main.cpp
  > Author: he_CentOS
  > Mail:1778195296@qq.com 
  > Created Time: 2015年03月14日 星期六 09时54分32秒
 *******************************************************************/

// 普通函数形式 的 运算符重载
#include <iostream>
using namespace std;

class complex					//定义复数类 complex
{
	public:
		double real, imag;				//private 成员，分别代表实部和虚部

	public:
		complex(double r = 0.0, double i = 0.0)			//构造函数，带缺省参数值
		{
			cout << "复数类构造函数" << endl;
			real = r;
			imag = i;
		}

		void disp()					//成员函数，输出复数
		{
			cout << real << " + " << "i*" << imag << endl;
		}
};

complex operator+(const complex& obj1, const complex& obj2)		//加+的实现
{
	//下句代码调用complex类构造函数
	return complex(obj1.real + obj2.real, obj1.imag + obj2.imag);
}

int main()
{
	complex cx1(1.0, 2.0), cx2(3.0, 4.0), cxRes;

	cxRes = cx1 + cx2;	//相当于cx1.operator+(cx2)
	cxRes.disp();

	return 0;
}
