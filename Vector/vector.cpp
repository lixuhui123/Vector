#include <iostream>
#include <vector>
#include <stack>
#include "vector.h"
using namespace std;
using namespace work;
int main()
{
#if 0


	stack<int> bb;/* ջ */
	vector<int> a;
	vector<int> b(10,6);
    vector<int> v=b;
	vector<int> v1(b.begin(), b.end());/* ������ */
	for (auto &i:v1)
	{
		cout << i;
	}
	cout << endl;
	int i;
	for (i=0;i<+10;++i)
	{
		a.push_back(i);
	}
	vector<int>::iterator fi;
	vector<int>::reverse_iterator ri;
	for (fi=a.begin();fi!=a.end();fi++)
	{
		/* ��������һ��ָ�룬������++����--�������ֽ�����ͬ�������û���������������
		��С������*/
		cout << *fi << ' ';
	}
	cout << endl;
	for (ri = a.rbegin(); ri != a.rend(); ri++)
	{
		cout << *ri << ' ';
	}
	cout << endl;
	cout << a.capacity()<<endl;
#else
	work::Vector<int> v(10,6);
	Vector<int>::iterator fi;
	for (fi=v.begin();fi!=v.end();++fi)
	{
		cout << *fi << ' ';
	}

#endif
	system("pause"); 
	return 0;
}