/********************************************************************
	> File Name: main.cpp
	> Author: he_CentOS
	> Mail:1778195296@qq.com 
	> Created Time: 2015年03月05日 星期四 22时21分02秒
 *******************************************************************/

#include<iostream>

class A
{
	public:
		A(int v=3) :val(v)
		{
		}
		~A()
		{
		}
	private:
		int val;
};

int main(void)
{
	int *pval = new int(3);
	std::cout << "*pval = " << *pval << std::endl;

	char *pval2 = new char[100];
	//sizeof(pval2)计算的是指针的大小
	std::cout << "size of pval2 :" << sizeof(pval2) << std::endl;

	char *p2 = pval2 - 8;
	std::cout << *(int *)p2 << std::endl;
	delete pval;
	delete []pval2;

	class A *pa = new A[10];
	std::cout << "size of pa :"<< sizeof(pa) << std::endl;
	delete []pa;

	return 0;
}
