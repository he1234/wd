/********************************************************************
	> File Name: main.cpp
	> Author: he_CentOS
	> Mail:1778195296@qq.com 
	> Created Time: 2015年04月06日 星期一 15时14分52秒
 *******************************************************************/

#include<iostream>
#include<string>
#include<assert.h>
#include "smartptr.h"

class Test
{
	public:
		Test()
		{
			std::cout << "Test()无参构造函数" << std::endl;
		}
		~Test()
		{
			std::cout << "~Test()析构函数" << std::endl;
		}

	private:
		Test(const Test &);
		void operator=(const Test&);
};

int main(void)
{
	smartptr<Test> ptr(new Test);
	std::cout << "ptr引用计数为： " << ptr.count() << std::endl;
	assert(ptr.count() == 1);

	smartptr<Test> ptr2(ptr);
	std::cout << "ptr引用计数为： " << ptr.count() << std::endl;

	smartptr<Test> ptr3;
	ptr3 = ptr;
	std::cout << "ptr引用计数为： " << ptr.count() << std::endl;

	if(ptr)		//发生隐式转换，把smartptr<Test>转换为bool型
	{
		std::cout << "ptr is not NULL" << std::endl;
	}

	assert(!ptr.unique());


	return 0;
}
