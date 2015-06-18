/********************************************************************
	> File Name: main.cpp
	> Author: he_CentOS
	> Mail:1778195296@qq.com 
	> Created Time: 2015年04月05日 星期日 21时19分38秒
 *******************************************************************/

#include "str.h"

//std::cin >> astr;和operator>>(std::cin, astr);都对
std::istream& operator>>(std::istream& in, STR::mystr &obj)
{
	std::cout << "重载operator>>" << std::endl;
	std::string str;
	in >> str;
	if(!in.good())
	{
		throw std::runtime_error(">> error");
	}
	obj.set(str.c_str());
	in.clear();
	return in;
}

//重载运算符函数写在全局区时，此例中std::cout << astr << std::endl;会调用该函数
std::ostream& operator<<(std::ostream& out, const STR::mystr &obj)
{
	std::cout << "重载operator<<" << std::endl;
	out << obj.get();
	return out;
}

#if 1
int main(void)
{
	STR::mystr astr("world");
	STR::mystr astr1("hahaha");
	std::cout << astr << std::endl;
	std::cin >> astr;
//	operator>>(std::cin, astr);
	std::cout << astr << std::endl;

//	astr[-1] = "!";		//检验数组越界的处理情况
	std::cout << "astr[0] = " << astr[0] << std::endl;
	std::cout << "--------------打印astr + astr1的函数调用过程------------" << std::endl;
	//下句代码中astr + astr1执行时，由重载+号函数调用拷贝构造函数返回mystr型数据，存储在临时数据中
	//并且，下句代码执行完后，该mystr临时数据生命周期结束，调用析构函数
	std::cout << "+" << astr + astr1 << std::endl;	

	std::cout << "------------------------------------" << std::endl;
	STR::mystr astr3("how");
	std::cout << "astr3: " << astr3 << std::endl;
	std::cout << "--------------打印astr3 += astr1的函数调用过程----------" << std::endl;
	std::cout << "astr3: +=\n" << (astr3 += astr1) << std::endl;
	std::cout << "--------------后续工作-----------------" << std::endl;



	return 0;
}
#endif

#if 0
int main(void)
{
	char* p = new char[32]();
	strcpy(p, "hello");
	STR::mystr str1(p);
	str1 = str1;

	STR::mystr str2(str1);
	STR::mystr str3;
	str3 = str2;
	std::cout << "ref_cnt: " << str1.get_cnt() << std::endl;

	std::cout << "str1: " << str1.get() << std::endl;
	std::cout << "str2: " << str2.get() << std::endl;
	std::cout << "str3: " << str3.get() << std::endl;

	str2.set("world");
	std::cout << "str1: " << str1.get() << std::endl;
	std::cout << "str2: " << str2.get() << std::endl;
	std::cout << "str3: " << str3.get() << std::endl;

	std::cout << "---------------------------" << std::endl;
	return 0;
}

#endif
