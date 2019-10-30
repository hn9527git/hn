#pragma once

#include "hn_iterator.h"

namespace HN
{
	//template<typename T> class const_iterator;
	//template<typename T> class iterator;

	//����ڵ�
	template<typename T>
	struct hn_list_node
	{
		hn_list_node<T> * pre;
		hn_list_node<T> * next;
		T node;
		
		hn_list_node() :pre(nullptr), next(nullptr)
		{
		}
		hn_list_node(const T & obj) :node(obj), pre(nullptr), next(nullptr)
		{
		}
	};

	//����
	template<class T>
	class hn_list
	{
	public:
		typedef const_iterator<T> const_iterator;//��
		typedef iterator<T> iterator;//��
		hn_list() :head_node_ptr(new hn_list_node<T>()), tail_node_ptr(new hn_list_node<T>()), theSize(0)
		{
			cout << "����hn_list�޲ι���" << endl;
			head_node_ptr->next = tail_node_ptr;
			tail_node_ptr->pre = head_node_ptr;
		}
		hn_list(int size) :head_node_ptr(new hn_list_node<T>()), tail_node_ptr(new hn_list_node<T>()), theSize(size)
		{
			cout << "����hn_listָ����С����" << endl;
			head_node_ptr->next = tail_node_ptr;
			tail_node_ptr->pre = head_node_ptr;
			for (int i = 0; i < theSize; i++)
			{
				hn_list_node<T> * tmp = new hn_list_node<T>();
				tail_node_ptr->pre->next = tmp;
				tmp->pre = tail_node_ptr->pre;
				tmp->next = tail_node_ptr;
				tail_node_ptr->pre = tmp;
			}
		}

		const_iterator begin() const
		{
			const_iterator it;
			it.current = head_node_ptr->next;
			return it;
		}

		const_iterator  end() const
		{
			const_iterator it;
			it.current = tail_node_ptr;
			return it;
		}

		iterator begin()
		{
			iterator it;
			it.current = head_node_ptr->next;
			return it;
		}

		//�������캯��
		hn_list(const hn_list<T> & rhs) :head_node_ptr(new hn_list_node<T>()), tail_node_ptr(new hn_list_node<T>()), theSize(rhs.theSize)
		{
			cout << "����hn_list��������" << endl;
			head_node_ptr->next = tail_node_ptr;
			tail_node_ptr->pre = head_node_ptr;
			for (const_iterator it = rhs.begin(); it != rhs.end(); it++)
			{
				push_back(*it);
			}
		}

		void push_back(const hn_list_node<T>& rhs)
		{
			hn_list_node<T> *tmp = new hn_list_node<T>(rhs);
			tail_node_ptr->pre->next = tmp;
			tmp->pre = tail_node_ptr->pre;
			tmp->next = tail_node_ptr;
			tail_node_ptr->pre = tmp;
			++theSize;
		}

		void push_front(const T& rhs)
		{
			hn_list_node<T> * tmp = new hn_list_node<T>(rhs);
			head_node_ptr->next->pre = tmp;
			tmp->next = head_node_ptr->next;
			head_node_ptr->next = tmp;
			tmp->pre = head_node_ptr;
			++theSize;
		}
		void pop_front()
		{
			if (empty())
				return;
			hn_list_node<T> * tmp = head_node_ptr->next;
			head_node_ptr->next = tmp->next;
			tmp->next->pre = head_node_ptr;
			delete tmp;
			--theSize;
		}
		void pop_back()
		{
			if (empty())
				return;
			hn_list_node<T>* tmp = tail_node_ptr->pre;
			tmp->pre->next = tail_node_ptr;
			tail_node_ptr->pre = tmp->pre;
			delete tmp;
			--theSize;
		}
		bool empty()
		{
			return theSize == 0 ? true : false;
		}
		void clear()
		{
			while (!empty())
			{
				pop_back();
			}
		}
		void resize(int num)
		{
			if (num==theSize)
			{
				return;
			}
			else if (num > theSize)
			{
				int n = num - theSize;
				for (int i = 0; i < n; i++)
				{
					push_back(T());
				}
			}
			else
			{
				int n = theSize - num;
				for (int i = 0; i < n; i++)
				{
					pop_back();
				}
			}

		}
		const T& front()
		{
			return head_node_ptr->next->node;
		}
		const T& back()
		{
			return tail_node_ptr->pre->node;
		}
		int size()const
		{
			return theSize;
		}

		//Ӧ��ʵ��һ��iterator�汾
		void insert(const_iterator it, const T& rhs)
		{
			hn_list_node<T> * tmp = it.current;
			hn_list_node<T> * new_node = new hn_list_node<T>(rhs);
			tmp->pre->next = new_node;
			new_node->pre = tmp->pre;
			new_node->next = tmp;
			tmp->pre = new_node;
			++theSize;

		}

		//ֻɾ����һ����ȵĽڵ�
		void remove(const T& rhs)
		{
			if (empty())
				return;
			else
			{
				for (iterator it = begin(); it != end(); it++)
				{
					if (*it == rhs)
					{
						cout << "remove  " <<*it<< endl;
						hn_list_node<T> * tmp = it.current;
						tmp->next->pre = tmp->pre;
						tmp->pre->next = tmp->next;
						delete tmp;
						--theSize;
						return;//�Ѿ�remove�ˣ�Ӧ�����أ���Ϊ�������Ѿ�ʧЧ��
					}
				}
			}
		}
		//�˴�����hn_list<T>&������֧�����ȣ���ld = lc = lb;
		//Ҳ���Է���void
		const hn_list<T>& operator = (const hn_list<T>& rhs)
		{
			cout << "���븳ֵ�����" << endl;
			if (this == &rhs)
			{
				return *this;
			}
			else
			{
				this->clear();
				hn_list::const_iterator it = rhs.begin();
				for (; it != rhs.end(); it++)
				{
					push_back(*it);
				}
				return *this;
			}
		}

		~hn_list()
		{
			cout << "����hn_list����" << endl;
			if (head_node_ptr != NULL)
				delete head_node_ptr;
			if (tail_node_ptr !=NULL)
			{
				delete tail_node_ptr;
			}
		}

	private:
		hn_list_node<T> * head_node_ptr;
		hn_list_node<T> * tail_node_ptr;
		int theSize;
	};

	

}