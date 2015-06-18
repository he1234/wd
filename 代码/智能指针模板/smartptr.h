/********************************************************************
	> File Name: smartptr.h
	> Author: he_CentOS
	> Mail:1778195296@qq.com 
	> Created Time: 2015年04月06日 星期一 14时03分11秒
 *******************************************************************/

#ifndef __SMARTPTR_H__
#define __SMARTPTR_H__

template <typename T>
class smartptr
{
	public:
		typedef T value_type;
		typedef T *pointer;
		typedef const T *const_pointer;
		typedef T &reference;
		typedef const T &const_reference;

		explicit smartptr(T *p = NULL);
		smartptr(const smartptr<T> &other);
		~smartptr();

		smartptr<T> &operator=(const smartptr<T> &other);

		reference operator*() const throw()
		{
			return *ptr_;
		}

		pointer operator ->() const throw()
		{
			return ptr_;
		}

		size_t count() const
		{
			return *count_;
		}

		void swap(smartptr<T> &other) throw()
		{
			std::swap(ptr_, other.ptr_);
			std::swap(count_, other.count_);
		}

		void reset(T *ptr = NULL) throw()
		{
			dispose();
			ptr_ = ptr;
			count_ = new size_t(1);
		}

		pointer get() const throw()
		{
			return ptr_;
		}

		bool unique() const throw()
		{
			return *count_ == 1;
		}
		#if 0
		//operator bool()表示本类型对象到bool的隐式转换，比如：
		ofstream ofs("output.txt");
		if(ofs)
		{
		}
		//其中，if(ofs)，该句代码就有ofstream类型到bool类型的隐式转换
		#endif
		operator bool()
		{
			std::cout << "调用operator bool()函数" << std::endl;
			return ptr_ != NULL;
		}

	private:
		void dispose()
		{
			if(--*count_ == 0)
			{
				delete ptr_;
				delete count_;
			}
		}

		T *ptr_;

		//引用计数采用指针,我个人认为
		//1.多个相同对象可以指向同一内存空间，共享内存
		//2.析构之后比较容易修改指针指向
		//如果不用指针的话，析构之后，需要重新分配空间
		size_t *count_;
};

template <typename T>
smartptr<T>::smartptr(T *p):ptr_(p), count_(new size_t(1))
{
}

template <typename T>
smartptr<T>::smartptr(const smartptr<T> &other)
	:ptr_(other.ptr_), count_(other.count_)
{
	++*count_;
}

template <typename T>
smartptr<T>::~smartptr()
{
	std::cout << "调用~smartptr()析构函数" << std::endl;
	dispose();
}

template <typename T>
smartptr<T> &smartptr<T>::operator= (const smartptr<T> &other)
{
	++*other.count_;
	dispose();
	ptr_ = other.ptr_;
	count_ = other.count_;

	return *this;
}

#endif
