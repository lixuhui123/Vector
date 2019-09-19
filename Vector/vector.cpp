#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main()
{
	stack<int> bb;/* Õ» */
	vector<int> a;
	vector<int> b(10,6);
    vector<int> v=b;
	vector<int> v1(b.begin(), b.end());/* µü´úÆ÷ */
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
		cout << *fi << ' ';
	}
	cout << endl;
	for (ri = a.rbegin(); ri != a.rend(); ri++)
	{
		cout << *ri << ' ';
	}
	cout << endl;
	cout << a.capacity()<<endl;
	system("pause"); 
	return 0;
}