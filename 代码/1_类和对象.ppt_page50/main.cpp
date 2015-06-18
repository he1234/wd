/********************************************************************
  > File Name: main.cpp
  > Author: he_CentOS
  > Mail:1778195296@qq.com 
  > Created Time: 2015年03月13日 星期五 10时05分26秒
 *******************************************************************/

//8-22 使用new/delete为类指针分配/释放内存
#include <iostream>
using namespace std;

class point
{
	private:
		int x;
		int y;

	public:
		point(int xp = 0,int yp = 0)
		{
			x=xp;
			y=yp;
			cout<<"构造函数被调用"<<endl;
		}

		~point()
		{
			cout<<"析构函数被调用"<<endl;
		}

		void print()
		{
			cout<<"x:  "<<x<<", y:  "<<y<<endl;
		}
};

int main()
{
	//动态申请一块内存，存储point类对象，并将地址赋值给point型指针p
	point* p = new point(4,5);
	p->print();
	//结果随机，因为p并没有动态申请数组，p之前的8字节存放的并不是数组大小
	cout << *(unsigned int*)((char*)p - 8) << endl;
	delete p;
	p=NULL;

	point *pp = new point[3];	//此时你会发现分配了28个字节的内存空间，多出的最开始的8个字节的内存空间，存放3
	//！！计算pp指针所指向地址的前8个字节（64位系统），这8个字节存放数组大小
	cout << *(unsigned int*)((char*)pp - 8) << endl;	//	结果为3
	delete[] pp;
	return 0;
}
