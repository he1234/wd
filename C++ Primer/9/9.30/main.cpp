/********************************************************************
	> File Name: main.cpp
	> Author: he_CentOS
	> Mail:1778195296@qq.com 
	> Created Time: 2015年03月20日 星期五 16时10分56秒
 *******************************************************************/

#include<iostream>
#include<vector>

int main(void)
{//本例可得：该库文件采取加倍当前容量的分配策略实现重新分配
	std::vector<int> vec;
	std::cout << "vec.size() : " << vec.size() << std::endl;
	std::cout << "vec.capacity() : " << vec.capacity() << std::endl;
	for(std::vector<int>::size_type ix = 0; ix != 11; ++ix)
	{
		vec.push_back(ix);
		std::cout << "vec.size() : " << vec.size() << std::endl;
		std::cout << "vec.capacity() : " << vec.capacity() << std::endl;
	}

	return 0;
}
