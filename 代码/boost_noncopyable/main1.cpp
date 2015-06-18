/********************************************************************
	> File Name: main1.cpp
	> Author: he_CentOS
	> Mail:1778195296@qq.com 
	> Created Time: 2015年04月11日 星期六 20时29分31秒
 *******************************************************************/

#include<iostream>

class A 
{
	public:

		A(int val)
		{
			m_val = val;
		}

		void show()
		{
			std::cout << m_val << std::endl;
		}
	private:
		//如果不想让类对象进行复制，可以在私有成员加上拷贝构造函数的声明，和重载=运算符的声明
		//从而在类外不能对对象进行复制
		A(const A &);
		void operator=(const A &);

	private:
		int m_val;
};
int main(void)
{
	A obj1(5);
	obj1.show();

//	A obj2 = obj1;
//	obj2.show();

	return 0;
}
