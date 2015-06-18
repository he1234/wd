/********************************************************************
	> File Name: main2.cpp
	> Author: he_CentOS
	> Mail:1778195296@qq.com 
	> Created Time: 2015年04月13日 星期一 09时12分36秒
 *******************************************************************/

#include<iostream>

void sayHello()
{
	std::cout << "Hello World !" << std::endl;
}

int sum(int i, int j, int k)
{
	return i + j + k;
}

template <typename T>
class Func
{
	public:
		Func(T fun)
		{
			if(!fun)
			{
				throw "fun nullptr";
			}
			_fun = fun;
		}

		template<typename R, typename A1, typename A2, typename A3, typename A4, typename A5>
		R Call(A1 a1, A2 a2, A3 a3, A4 a4, A5 a5)
		{
			return _fun(a1, a2, a3, a4, a5);
		}

		template<typename R, typename A1, typename A2, typename A3, typename A4>
		R Call(A1 a1, A2 a2, A3 a3, A4 a4)
		{
			return _fun(a1, a2, a3, a4);
		}

		template<typename R, typename A1, typename A2, typename A3>
		R Call(A1 a1, A2 a2, A3 a3)
		{
			return _fun(a1, a2, a3);
		}

		template<typename R, typename A1, typename A2>
		R Call(A1 a1, A2 a2)
		{
			return _fun(a1, a2);
		}

		template<typename R, typename A1>
		R Call(A1 a1)
		{
			return _fun(a1);
		}

		template<typename R>
		R Call()
		{
			return _fun();
		}

		void Call()
		{
			_fun();
		}

	private:
		T _fun;
};

#include<functional>

//R的类型默认值为void
template<typename R = void, typename... Args>
class Fn
{
	public:

		//std::function<R(Args...)> Fn以匿名函数传参， R（Args...)为函数类型
		Fn(std::function<R(Args...)> fun) : _fun(fun){}

		R operator()(Args... args)	//#1
		{//传递多个形参 Args... args
			//使用形参时，用args...
			return _fun(args...);
		}

		std::function<R(Args...)> _fun;
};

int main(void)
{
	Func<void(*)()> sayHelloFunc(sayHello);
	sayHelloFunc.Call();

	Func<int (*)(int, int , int)> sumFunc(sum);
	//sum.Func.Call<int>(1, 2, 3)实例化模板时，一个int就够了
	std::cout<< "sumFunc.Call<int>(1, 2, 3) : " << sumFunc.Call<int>(1, 2, 3) << std::endl;

	std::cout <<"-------------------------------" << std::endl;

	Fn<> sayHelloFn(sayHello);
	sayHelloFn();	//调用程序块#1

	Fn<int, int, int, int> sumFn(sum);
	std::cout << "sumFn(1, 2, 3) : " << sumFn(1, 2, 3) << std::endl;	//sumFn(1, 2, 3)调用程序块#1

	return 0;
}
