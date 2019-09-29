#include <iostream>
#include <vector>
using namespace std;
int mainfeafs()
{
	vector<int> myvector(3, 100);/* 3个100 */
	vector<int>::iterator it;
	for (it = myvector.begin(); it != myvector.end(); it++)
	{
		/* 迭代器是一个指针，但它的++或者--跳过的字节数不同，根据用户声明的数据类型
		大小来自增*/
		cout << *it << ' ';
	}
	cout << endl;
	it = myvector.begin();
	it = myvector.insert(it, 200);/* 指向新插入的元素的位置 */

	myvector.insert(it, 2, 300);
	//
	it = myvector.begin();/* 容器最开始的位置 */
	//myvector.insert(it, 250);
	
	vector<int> anothervector(2, 400);
	myvector.insert(it + 2, anothervector.begin(), anothervector.end());
	/* 向后移动2个位置 */
    int myarray[] = { 501,502,503 };
	myvector.insert(myvector.begin(), myarray, myarray + 3);

	cout << "myvector contains:";
	for (it = myvector.begin(); it < myvector.end(); it++)
		cout << " " << *it;
	//cout << myvector[3];
	//swap(myvector, anothervector);//交换两个容器
	 
	cout << endl;
	system("pause"); 
	return 0;
}
 


 
