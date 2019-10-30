#pragma once

#include <iostream>
using std::cout;
using std::cerr;
using std::endl;

namespace HN
{
	template<typename T> struct hn_list_node;//�±�Ҫ�õ�������������,������ģ��ʹ��extern����ԭ��δ֪
	template<class T> class hn_list;//�±�Ҫ�õ���������������������ģ��ʹ��extern����ԭ��δ֪

	//const������

	template<typename T>
	class const_iterator
	{
	public:
		friend class hn_list<T>;//������Ԫ�Է���hn_list
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
		T& retrieve() const//�ָ������õ��ڵ�
		{
			return current->node;
		}
	private:

	};

	//��ͨ������

	template<typename T>
	class iterator : public const_iterator<T>//�̳���const������
	{
	public:
		friend class hn_list<T>;//������Ԫ�Է���hn_list
		iterator()
		{
		}

		//��constĬ�ϵ��ô˰汾
		const T& operator * ()
		{
			//cout << "���÷�const�汾operator *()" << endl;
			return const_iterator<T>::current->node;
		}

		//���Կ��������Ƿ�Ϊconst����������ʵ������,const������ô˰汾
		const T& operator * () const
		{
			//cout << "����const�汾operator *()" << endl;
			return const_iterator<T>::operator *();
		}

		iterator& operator++()//ǰ������
		{
			const_iterator<T>::current = const_iterator<T>::current->next;
			return *this;
		}

		iterator& operator++(int)//��������
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
