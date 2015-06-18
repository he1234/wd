/********************************************************************
  > File Name: main.cpp
  > Author: he_CentOS
  > Mail:1778195296@qq.com 
  > Created Time: 2015年03月09日 星期一 16时32分50秒
 *******************************************************************/

#include <iostream>
#include <string.h>

class Computer
{
	public:
		Computer(const char *brand, float price)
		{
			psBrand_ = new char[strlen(brand) + 1];
			strcpy(psBrand_, brand);
			fPrice_ = price;
		}
		Computer(): psBrand_(NULL), fPrice_(0.0) {}

		~Computer()
		{
			if(psBrand_)
			{
				delete[] psBrand_;
				psBrand_ = NULL;
			}
			std::cout << "清理现场 " << std::endl;
		}

		void print()
		{
			std::cout << "品牌：" << psBrand_ << std::endl;
			std::cout << "价格：" << fPrice_ << std::endl;
		}
		Computer(const Computer &rhs)
		{
			psBrand_ = new char[strlen(rhs.psBrand_) + 1];
			if(psBrand_ == NULL)
			{
				std::cout << "memory allocated fail " << std::endl;
				return;
			}
			strcpy(psBrand_, rhs.psBrand_);
			fPrice_ = rhs.fPrice_;
		}

	private:

	private:
		char *psBrand_;
		float fPrice_;
};


int main(void)
{
	Computer pc1("Dell", 7000);
	pc1.print();
	Computer pc2 = pc1;

	pc2.print();


	return 0;
}
