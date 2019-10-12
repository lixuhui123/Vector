#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> generate(int numRows)
{

	vector<vector<int>> data(numRows);/* 会被返回的值,二维vector */
	if (!numRows)
	{
		return data;
	}
 
	int i, j;
	data[0].push_back(1);
	for (i=1;i<numRows;++i)
	{
		data[i] = data[i-1];/*将上一个vector拉过来使用 */
		/* 从后往前计算，此处为什么是j-1呢，因为vector从下标0开始，并且i从1开始 */
		for (j=i-1;j>0;--j)
		{
			data[i][j] += data[i][j - 1];

		}
		 
		data[i].push_back(1);//添加上最后一个1
	}
	return data;

}
void printarr(vector<int>&v,int n)
{
	for (int i=0;i<n;++i)
	{
		cout << v[i] << '\t';
	}
	cout << endl;
}
void yanghui(int n)
{
	vector<int> v(n, 0);
	v[0] = 1;
	printarr(v, 1);
	int i, j;
	for (i=1;i<n;++i)
	{
		for (j=i;j>0;--j)
		{
			v[j] += v[j - 1];
		}
		printarr(v, i+1);
	}
	
}
int mainddsew()
{
	yanghui(10);
	//generate(10);
		 
	system("pause"); 
	return 0;
}