/********************************************************************
  > File Name: main.cpp
  > Author: he_CentOS
  > Mail:1778195296@qq.com 
  > Created Time: 2015年03月09日 星期一 16时40分21秒
 *******************************************************************/
#include <iostream>
#include <string.h>

class Computer
{
	public:
		Computer() : psBrand_(NULL), fPrice_(0.0){}
		Computer(const char* brand, float price)
		{
			if(brand)
			{
				psBrand_ = new char[strlen(brand) + 1];
				strcpy(psBrand_,brand);
			}
			fPrice_ = price;
			total_price_ += price;
		}

		~Computer()
		{
			if(this)
			{
				delete []psBrand_;
				psBrand_ = NULL;
			}
			std::cout << "调用析构函数" << std::endl;
		}

		Computer(const Computer &rhs)
		{
			if(&rhs)
			{
				if(rhs.psBrand_)
				{
					psBrand_ = new char[strlen(rhs.psBrand_) + 1];
					strcpy(psBrand_, rhs.psBrand_);
				}
				fPrice_ = rhs.fPrice_;
				total_price_ += rhs.fPrice_;
			}
		}

		Computer& operator=(const Computer &rhs)
		{
			if(this == &rhs)
			{
				return (*this);
			}
			if(psBrand_)
			{
				delete []psBrand_;
				psBrand_ = NULL;
			}
			psBrand_ = new char[strlen(rhs.psBrand_) + 1];
			if(psBrand_ == NULL)
			{
				std::cout << "memory allocated fail" << std::endl;
				return (*this);
			}

			strcpy(psBrand_, rhs.psBrand_);
			total_price_ -= fPrice_;
			fPrice_ = rhs.fPrice_;
			total_price_ += rhs.fPrice_;

			std::cout << "赋值重载函数被调用" << std::endl;
			return (*this);
		}

		void print()
		{
			std::cout << "品牌：" << psBrand_ << std::endl;
			std::cout << "价格：" << fPrice_ << std::endl;
		}

		static void print_total()
		{
			std::cout << "总价 ：" << total_price_ << std::endl;
		}

	private:
		char *psBrand_;
		float fPrice_;
		static float total_price_;
};

float Computer::total_price_ = 0;
int main(void)
{
	Computer pc("华硕",4000);
	pc.print();
	Computer::print_total();

	Computer pc2("hp", 5000);
	pc2.print();
	Computer::print_total();

	pc = pc2;
	pc.print();
	Computer::print_total();

	return 0;
}
