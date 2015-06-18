/********************************************************************
	> File Name: main.cpp
	> Author: he_CentOS
	> Mail:1778195296@qq.com 
	> Created Time: 2015年03月05日 星期四 10时29分07秒
 *******************************************************************/

#include<iostream>
using namespace std;

int main(void)
{
	int ival1=static_cast<int>(3.1415926);
	cout<<"ival1="<<ival1<<endl;
	
	//以下注意：pival和&ival2的值相同，但*pival和ival2的值不同
	//这种情况下，const_cast常用于函数调用中把const参数去掉const属性
	const int ival2=100;
	int* pival=const_cast<int*>(&ival2);
	*pival=20;
	cout<<"*pival="<<*pival<<"	address of pival:"<<pival<<endl;
	cout<<"ival2="<<ival2<<"	address of pival:"<<&ival2<<endl;
	return 0;
}
