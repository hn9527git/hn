// list_impl.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include "hn_list.h"

using namespace HN;

void show(hn_list<int> li)
{
	hn_list<int>::const_iterator it = li.begin();
	for (; it != li.end(); it++)
	{
		//调用过程 it.operator->()->node;
		cout << it->node << "  ";//调用重载箭头操作符访问node，
	}
	cout << endl;
}

int main()
{
	std::cout << "Hello World!\n";
	cout << "使用默认无参构造+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++=" << endl;
	hn_list<int> la;
	hn_list_node<int> na(1);
	hn_list_node<int> nb(3);
	hn_list_node<int> nc(5);
	la.push_back(na);
	la.push_back(nb);
	la.push_back(nc);
	cout << "使用const迭代器" << endl;
	show(la);
	cout << "使用普通迭代器" << endl;
	hn_list<int>::iterator it2 = la.begin();
	for (; it2 != la.end(); it2++)
	{
		cout << *it2 << "  ";
	}
	cout << endl;
	cout << "使用拷贝构造+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
	hn_list<int> lb(la);
	show(lb);
	cout << "使用赋值运算符+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
	hn_list<int> lc;
	hn_list<int> ld;
	ld = lc = lb;
	show(lc);
	lc.resize(2);
	cout << "lc.size  " << lc.size() << endl;
	show(lc);
	lc.resize(10);
	cout << "lc.size  " << lc.size() << endl;
	show(lc);
	cout << "lc.front  " << lc.front() << endl;
	cout << "lc.back  " << lc.back() << endl;
	lc.insert(lc.end(), 6);
	cout << "lc.size  " << lc.size() << endl;
	show(lc);
	lc.remove(6);
	cout << "after lc.remove  size: " << lc.size() << endl;
	show(lc);
	lc.pop_front();
	cout << "lc.pop_front" << endl;
	cout << "after lc.pop_front  size: " << lc.size() << endl;
	show(lc);
	lc.push_front(9);
	show(lc);
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
