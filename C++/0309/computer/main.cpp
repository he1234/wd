/********************************************************************
  > File Name: main.cpp
  > Author: he_CentOS
  > Mail:1778195296@qq.com 
  > Created Time: 2015年03月09日 星期一 16时11分16秒
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
			//释放堆空间时，有必要判断是否为空，防止多次释放
			if(NULL != psBrand_)
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
		Computer(const Computer &rhs);
			//{
			//    psBrand_ = rhs.psBrand_;
			//    fPrice_ = rhs.fPrice_;
			//}

	private:

	private:
			char *psBrand_;
			float fPrice_;
};

Computer pc("Acer", 5000);

int main(void)
{
	{
		Computer pc1("Dell", 7000);
		pc1.print();
		pc1.~Computer();
		std::cout << std::endl;
	}
	std::cout << "--------------------" << std::endl;
	//动态分配时，构造对象
	Computer *pc3 = new Computer("Mac", 10000);

	pc3->print();
	//delete对象时，调用析构函数
	delete pc3;
	std::cout << "--------------------" << std::endl;
	
	pc.print();
	return 0;
}
