/********************************************************************
	> File Name: main.cpp
	> Author: he_CentOS
	> Mail:1778195296@qq.com 
	> Created Time: 2015年04月11日 星期六 22时18分42秒
 *******************************************************************/

#include<iostream>
#include<functional>


struct Foo
{
	Foo(int num) : num_(num){}
	void print_add(int i) const
	{
		std::cout << num_ + i << std::endl;
	}
	int num_;
};

void print_num(int i)
{
	std::cout << i << std::endl;
}

struct PrintNum
{
	void operator()(int i) const
	{
		std::cout << i << std::endl;
	}
};

int main(void)
{
	//store a free function
	std::function<void(int)> f_display = print_num;
	f_display(-9);

	//store a lambda
	std::function<void()> f_display_42 = [](){ print_num(42);};
	f_display_42();

	//store the result of a call to std::bind
	std::function<void()> f_display_31337 = std::bind(print_num, 31337);
	f_display_31337();

	//store a call of to a member function
	std::function<void(const Foo&, int)> f_add_display = &Foo::print_add;
	const Foo foo (314159);
	f_add_display(foo, 1);

	//store a call to a member function and object
	using std::placeholders::_1;
	std::function<void(int)> f_add_display2 = std::bind(&Foo::print_add,foo, _1);
	f_add_display2(2);

	//store a call to a function object
	std::function<void(int)> f_display_obj = PrintNum();
	f_display_obj(18);

	return 0;
}
