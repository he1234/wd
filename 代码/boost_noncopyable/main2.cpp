/********************************************************************
	> File Name: main2.cpp
	> Author: he_CentOS
	> Mail:1778195296@qq.com 
	> Created Time: 2015年04月11日 星期六 21时14分19秒
 *******************************************************************/

#include<iostream>
//boost库noncopyable.hpp文件中定义了类noncopyable
//该类禁止复制，不能调用拷贝构造函数和赋值函数
#include<boost/noncopyable.hpp>

//新建一个派生类A继承noncopyable，类A便禁止复制
class A : boost::noncopyable	//默认私有继承
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
		int m_val;
};
int main(void)
{
	A obj1(5);
//	A obj2 = obj1;
	obj1.show();

	return 0;
}
