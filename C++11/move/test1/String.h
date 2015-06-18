/*************************************************************************
    > File Name: String.h
    > Author: 时中贺
    > Mail: shi_zhonghe@163.com 
    > Created Time: 2015年06月05日 星期五 15时41分23秒
 ************************************************************************/

#include<string.h>
#include<ostream>

class String
{
	public:
		friend std::ostream& operator<<(std::ostream& out, const String& other);

		String(const char *str = NULL)
		{
			std::cout << "构造函数 ！" << std::endl;
			if(NULL == str)
			{
				data_ = new char[1];
				data_[0] = '\0';
			}
			else
			{
				data_ = new char[strlen(str) + 1];
				strcpy(data_, str);
			}
		}

		String(const String &other)
		{
			std::cout << "拷贝构造函数 ！" << std::endl;
			data_ = new char[strlen(other.data_) + 1];
			strcpy(data_, other.data_);
		}

		~String()
		{
			std::cout << "析构函数 ！" << std::endl;
			if(data_)
				delete []data_;
		}

		String& operator=(const String &other)
		{
			std::cout << "赋值函数 ！" << std::endl;
			if(&other == this)
				return *this;
			delete []data_;
			data_ = new char[strlen(other.data_) + 1];
			strcpy(data_, other.data_);
			return *this;
		}

	private:
		char *data_;
};

std::ostream& operator<<(std::ostream& out, const String& other)
{
	out << other.data_;
	return out;
}
