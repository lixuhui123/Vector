#include <iostream>
#include <vector>
using namespace std;
int mainfeafs()
{
	vector<int> myvector(3, 100);/* 3��100 */
	vector<int>::iterator it;
	for (it = myvector.begin(); it != myvector.end(); it++)
	{
		/* ��������һ��ָ�룬������++����--�������ֽ�����ͬ�������û���������������
		��С������*/
		cout << *it << ' ';
	}
	cout << endl;
	it = myvector.begin();
	it = myvector.insert(it, 200);/* ָ���²����Ԫ�ص�λ�� */

	myvector.insert(it, 2, 300);
	//
	it = myvector.begin();/* �����ʼ��λ�� */
	//myvector.insert(it, 250);
	
	vector<int> anothervector(2, 400);
	myvector.insert(it + 2, anothervector.begin(), anothervector.end());
	/* ����ƶ�2��λ�� */
    int myarray[] = { 501,502,503 };
	myvector.insert(myvector.begin(), myarray, myarray + 3);

	cout << "myvector contains:";
	for (it = myvector.begin(); it < myvector.end(); it++)
		cout << " " << *it;
	//cout << myvector[3];
	//swap(myvector, anothervector);//������������
	 
	cout << endl;
	system("pause"); 
	return 0;
}
 


 
