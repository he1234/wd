/********************************************************************
  > File Name: main.cpp
  > Author: he_CentOS
  > Mail:1778195296@qq.com 
  > Created Time: 2015年03月16日 星期一 18时49分52秒
 *******************************************************************/

#include<iostream>
#include<list>
class Foo
{
	public:
		Foo(int val)
		{
			val_ = val;
		}
		~Foo()
		{

		}

		void print() const
		{
			std::cout << "val = " << val_ << std::endl;
		}

	private:
		int val_;
};
int main(void)
{
	std::list< Foo > li(10,1);
	std::list< Foo >::iterator iter = li.begin();
	for(; iter != li.end(); ++iter)
	{
		(*iter).print();
	}
	return 0;
}
