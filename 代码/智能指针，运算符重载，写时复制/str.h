/********************************************************************
	> File Name: str.h
	> Author: he_CentOS
	> Mail:1778195296@qq.com 
	> Created Time: 2015年04月05日 星期日 21时19分01秒
 *******************************************************************/

#ifndef __STR_H__
#define __STR_H__
#include<iostream>
#include<stdexcept>
#include<cstring>
namespace STR
{
	class ref_cnt
	{//智能指针引用计数
		friend class mystr;
		int m_cnt;
		int m_size;
		char* m_ptr;
		ref_cnt(char* ptr = NULL, int size = 0, int use = 0):m_ptr(ptr), m_cnt(use), m_size(size)
		{
		}

		void increment()
		{
			m_cnt ++;
		}
		void decrement()
		{
			m_cnt --;
		}
		int get_cnt() const
		{
			return m_cnt;
		}
		char* get_ptr()
		{
			return m_ptr;
		}
		~ref_cnt()
		{
			delete []m_ptr;
		}
	};

	class mystr
	{
		public:
//			friend std::istream& ::operator>>(std::istream& in, mystr &obj);
//			friend std::ostream& ::operator<<(std::ostream& out, const mystr &obj);
			mystr():m_use(NULL)
			{
				std::cout << "无参构造函数" << std::endl;
				std::cout << __func__ << ":" << __LINE__ << std::endl;
			}

			mystr(const char* ptr):m_use(new ref_cnt(new char[strlen(ptr) + 1](), strlen(ptr) + 1, 1))
			{
				std::cout << "1参数构造函数" << std::endl;
				strcpy(m_use -> m_ptr, ptr);
				std::cout << __func__ << ":" << __LINE__ << std::endl;
			}

			mystr(const mystr& obj):m_use(obj.m_use)
			{
				std::cout << "拷贝构造函数" << std::endl;
				m_use -> increment();
				std::cout << "ref_cnt: " << m_use -> get_cnt() << std::endl;
				std::cout << __func__ << ":" << __LINE__ << std::endl;
			}

			mystr& operator=(const mystr& obj)
			{
				std::cout << "重载operator=" << std::endl;
				if(this == &obj)
				{
					return *this;
				}
				if(m_use != NULL)
				{
					m_use -> decrement();
					if(m_use -> get_cnt() == 0)
					{
						delete m_use;
					}
				}
				m_use = obj.m_use;
				m_use -> increment();
			}

			bool operator<(const mystr& right)
			{
				std::cout << "重载operator<" << std::endl;
				return strcmp(this ->get(), right.get()) < 0;
			}
			bool operator>(const mystr& right)
			{
				std::cout << "重载operator>" << std::endl;
				return strcmp(right.get(), this -> get()) < 0;
			}
			bool operator==(const mystr& right)
			{
				std::cout << "重载operator==" << std::endl;
				return strcmp(this -> get(), right.get()) == 0;
			}

			char& operator[](int pos)
			{
				std::cout << "重载operator[]" << std::endl;
				if(!(pos >= 0 && pos < strlen(m_use -> m_ptr)))
				{
					throw std::runtime_error("out of range");
				}
				if(m_use -> m_cnt == 1)
				{//只有一个对象引用ref_ cnt指针
					return m_use -> m_ptr[pos];
				}
				else
				{//有多个对象引用ref_cnt指针时，重新分配空间，并初始化新的ref_cnt指针，在新的ref_cnt指针上进行操作
					ref_cnt* tmp = m_use;
					m_use -> m_cnt --;
					m_use = new ref_cnt(new char[tmp -> m_size], tmp -> m_size, 1);
					strcpy(m_use -> m_ptr, tmp -> m_ptr);
					return m_use -> m_ptr[pos];
				}
			}
			//返回时，调用拷贝构造函数
			mystr operator+(const mystr& right)
			{
				std::cout << "重载operator+" << std::endl;
				if(m_use == NULL)
				{
					return right;
				}
				else
				{
					mystr tmp_obj;
					int size = strlen(this -> m_use -> m_ptr) + strlen(right.m_use -> m_ptr) + 1;
					tmp_obj.m_use = new ref_cnt(new char[size](), size, 1);
					strcpy(tmp_obj.m_use -> m_ptr, this -> m_use -> m_ptr);
					strcat(tmp_obj.m_use -> m_ptr, right.m_use -> m_ptr);
					return tmp_obj;
				}
			}

			mystr& operator+=(const mystr& right)
			{
				std::cout << "重载operator+=" << std::endl;
				*this = *this + right;
				return *this;
			}

			mystr& set(const char* str)
			{
				if(m_use == NULL)
				{
					m_use = new ref_cnt(new char[strlen(str) + 1], strlen(str) + 1, 1);
					strcpy(m_use -> m_ptr, str);
				}
				else
				{
					if(m_use -> m_cnt == 1)
					{
						delete [] m_use -> m_ptr;
						m_use -> m_size = strlen(str) + 1;
						m_use -> m_ptr = new char[m_use -> m_size]();
						strcpy(m_use -> m_ptr, str);
					}
					else
					{
						m_use -> decrement();
						m_use = new ref_cnt(new char[strlen(str) + 1], strlen(str) + 1, 1);
						strcpy(m_use -> m_ptr, str);
					}
				}
			}

			char* get() const
			{
				return m_use -> m_ptr;
			}
			int get_cnt()
			{
				return m_use -> get_cnt();
			}

			~mystr()
			{
				std::cout << "析构函数" << std::endl;
				std::cout << m_use -> m_ptr << std::endl;
				if(NULL == m_use)
				{
					return;
				}
				std::cout << __func__ << ":" << __LINE__ << std::endl;
				m_use -> decrement();
				if(m_use -> get_cnt() == 0)
				{
					std::cout << "delete" << __LINE__ << std::endl;
					delete m_use;
				}
			}
		private:
			ref_cnt* m_use;
	};
}
#endif
