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
	vector<int>::iterator fi;
	int arr[1000] = { 0 };
	fi = v1.begin();
	//fi=v1.insert(fi, 8,8);
	//cout << *fi << endl;/* ����ֵָ�򱻲����λ�ã��������±�Ϊ5�ĵط��壬���صĻ����±�5 */
	v1.erase(fi + 1, fi + 9);
	for (auto &i:v1)
	{
		cout << i<<' ';
	}
	//cout << endl;
	//int i;
	//for (i=0;i<10;++i)
	//{
	//	a.push_back(i);
	//}
	//vector<int>::iterator fi;
	//vector<int>::reverse_iterator ri;
	//for (fi=a.begin();fi!=a.end();fi++)
	//{
	//	/* ��������һ��ָ�룬������++����--�������ֽ�����ͬ�������û���������������
	//	��С������*/
	//	cout << *fi << ' ';
	//}
	//cout << endl;
	//for (ri = a.rbegin(); ri != a.rend(); ri++)
	//{
	//	cout << *ri << ' ';
	//}
	//cout << endl;
	//cout << a.capacity()<<endl;
#else
	work::Vector<int> v(10,6);
	Vector<int> v2 ;
	v2 = v;
	Vector<int>::iterator fi;
	fi = v.begin() + 8;
	v.insert(fi, 4);
	v.erase(fi - 1);
	for (fi = v2.begin(); fi != v2.end(); ++fi)
	{
		cout << *fi << ' ';
	}
	cout << endl;
	cout << v.capacity() << ' ' << v.size();
	Vector<int> v1(19, 6);
	 
	for (fi = v1.begin(); fi != v1.end(); ++fi)
	{
		cout << *fi << ' ';
	}
	cout << endl;
	cout<< v1.capacity()<<' '<< v1.size();
#endif
	system("pause"); 
	return 0;
}