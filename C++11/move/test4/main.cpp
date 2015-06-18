/*************************************************************************
  > File Name: main.cpp
  > Author: 时中贺
  > Mail: shi_zhonghe@163.com 
  > Created Time: 2015年06月05日 星期五 17时23分56秒
 ************************************************************************/

#include <iostream>
#include <utility>
#include <vector>
#include <string>
int main()
{

	std::string str = "Hello";
	std::vector<std::string> v;

	//调用push_back(const T&),会拷贝一份str
	v.push_back(str);
	std::cout << "After copy, str is \"" << str << "\"\n";

	//使用右值引用，调用push_back(T&&),这意味着不会拷贝一份str
	//相当于把str直接放入vector，此后，str将为空。对应文本的剪切操作
	v.push_back(std::move(str));//move表示把左值引用转换为右值引用
	std::cout << "After move, str is \"" << str << "\"\n";

	std::cout << "The contents of the vector are \"" << v[0] << "\", \"" << v[1] << "\"\n";
}
