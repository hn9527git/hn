#pragma once

#include <iostream>
using std::cout;
using std::cerr;
using std::endl;

namespace HN
{
	template<typename T> struct hn_list_node;//下边要用到，所以先声明,仅声明模板使用extern报错，原因未知
	template<class T> class hn_list;//下边要用到，所以先声明，仅声明模板使用extern报错，原因未知

	//const迭代器

	template<typename T>
	class const_iterator
	{
	public:
		friend class hn_list<T>;//设置友元以访问hn_list
		const_iterator() :current(NULL)
		{
		}

		const T& operator*() const
		{
			return current->node;
		}

		const_iterator & operator++(int)
		{
			const_iterator old = *this;
			++(*this);
			return old;
		}

		const_iterator & operator++()
		{
			current = current->next;
			return *this;
		}

		bool operator == (const const_iterator & rhs) const
		{
			return current == rhs.current ? true : false;
		}

		bool operator != (const const_iterator & rhs) const
		{
			return !(current == rhs.current);
		}

		hn_list_node<T> * operator -> ()
		{
			return current;
		}

		~const_iterator()
		{
		}

	protected:
		hn_list_node<T> * current;
		T& retrieve() const//恢复，即得到节点
		{
			return current->node;
		}
	private:

	};

	//普通迭代器

	template<typename T>
	class iterator : public const_iterator<T>//继承自const迭代器
	{
	public:
		friend class hn_list<T>;//设置友元以访问hn_list
		iterator()
		{
		}

		//非const默认调用此版本
		const T& operator * ()
		{
			//cout << "调用非const版本operator *()" << endl;
			return const_iterator<T>::current->node;
		}

		//可以看到根据是否为const对象函数可以实现重载,const对象调用此版本
		const T& operator * () const
		{
			//cout << "调用const版本operator *()" << endl;
			return const_iterator<T>::operator *();
		}

		iterator& operator++()//前置自增
		{
			const_iterator<T>::current = const_iterator<T>::current->next;
			return *this;
		}

		iterator& operator++(int)//后置自增
		{
			iterator old = *this;
			++(*this);
			return old;
		}

		~iterator()
		{
		}
	};
}
