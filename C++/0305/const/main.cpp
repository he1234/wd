/********************************************************************
	> File Name: main.cpp
	> Author: he_CentOS
	> Mail:1778195296@qq.com 
	> Created Time: 2015年03月05日 星期四 14时53分01秒
 *******************************************************************/

#include<iostream>
using namespace std;

int main(void)
{//以下为错误代码示例
	const int ival=10;
	
	//指针指向的内容为const
	const int *pival=&ival;
	*pival=3;
	cout<<"*pival="<<*pival<<endl;

	int ival21 =20;
	int ival22=3;
	//指针为const
	int *const pival2=&ival21;
	pival2=&ival22;

	int ival3=30;

	int ival4=40;
	const int *const pival4=&ival4;
	int ival5=50;

	*pival4=60;//指针指向的内容为const
	pival4=&ival3;//指针为const
	
	return 0;
}
