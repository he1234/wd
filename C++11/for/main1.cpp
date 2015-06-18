/********************************************************************
	> File Name: main1.cpp
	> Author: he_CentOS
	> Mail:1778195296@qq.com 
	> Created Time: 2015年04月12日 星期日 22时25分31秒
 *******************************************************************/

#include<iostream>
#include<string.h>
#include<algorithm>

void f1(int &i) {i *= 2;}

void f2(int &i) {std::cout << i << std::endl;}

int main(void)
{
	int a[] = {1, 2, 3, 4, 5};
	int arr[5] = {0};
	memcpy(arr, a, sizeof(a));

	for(int *p = arr; p < arr + sizeof(arr)/sizeof(int); ++p)
		*p *= 2;
	for(int *p = arr; p < arr + sizeof(arr)/sizeof(int); ++p)
		std::cout << *p << std::endl;

	std::cout << "\n--------------------------------" << std::endl;

	memcpy(arr, a, sizeof(a));

	std::for_each(arr, arr + sizeof(arr)/sizeof(int), f1);
	std::for_each(arr, arr + sizeof(arr)/sizeof(int), f2);

	std::cout << "\n--------------------------------" << std::endl;

	memcpy(arr, a, sizeof(a));
	for(auto &i : arr)
		i *= 2;
	for(auto &i : arr)
		std::cout << i << std::endl;
	return 0;
}
