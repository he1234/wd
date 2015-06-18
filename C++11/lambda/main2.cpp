/********************************************************************
	> File Name: main2.cpp
	> Author: he_CentOS
	> Mail:1778195296@qq.com 
	> Created Time: 2015年04月12日 星期日 21时45分15秒
 *******************************************************************/

#include<iostream>
#include<algorithm>
#include<list>

struct
{
	public:
		void operator()(const int& i)
		{
			std::cout << i << std::endl;
		}
		int val_;
}p1;

int main(void)
{
	std::vector<int> ids{1, 2, 3, 4, 5};
	std::for_each(ids.begin(), ids.end(), p1);
	std::cout << "\n--------------------------" << std::endl;

	std::for_each(ids.begin(), ids.end(), [](int& i){std::cout << i << std::endl;});

	return 0;
}
