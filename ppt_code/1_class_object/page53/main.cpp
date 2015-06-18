/********************************************************************
  > File Name: main.cpp
  > Author: he_CentOS
  > Mail:1778195296@qq.com 
  > Created Time: 2015年03月13日 星期五 10时40分01秒
 *******************************************************************/

#include<iostream>
using namespace std;
class CA
{
	private:
		static CA *pA;
		int x;
		int y;
		CA(int x = 0, int y = 0)
		{//单件模式，构造函数必须设为私有
			this->x = x;
			this->y = y;
			cout << "构造函数被调用\t" << this << endl;
		}	
	public:
		static CA* GetInstance(int x = 0, int y = 0)
		{//由此构造单个对象
			if(pA == NULL)
			{//pA为全局变量，如果为空，则分配空间
				pA = new CA(x, y);
			}
			return pA;
		}
		void disp() const
		{
			cout << "(" << this->x << "," << this->y << ")" << endl;
		}
};
CA* CA::pA = NULL;//静态成员要在外面初始化
int main(void)
{//	单件设计模式：即内存中只能有一份对象，步骤见该程序

	CA *p1 = CA::GetInstance(3, 4);
//	cout << "(" << p1 -> x << ", "<< p1 -> y << ")"<< endl;	//	x,y为类C的私有成员，只能在类内部访问，故编译出错
	CA *p2 = CA::GetInstance(2, 1);
	CA *p3 = CA::GetInstance(6, 2);

//	CA obj;	//	类CA的构造函数是私有的，所以只能在类内部访问，编译出错
	cout << p1 << endl;
	cout << p2 << endl;
	cout << p3 << endl;
	p1->disp();
	p2->disp();
	p3->disp();

	return 0;
}
//此时p1、p2、p3是同一个，输出来的值相等，所以调用disp都输出同样的内容
