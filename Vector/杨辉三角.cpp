#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> generate(int numRows)
{
	vector<vector<int>> data(numRows);
	if (!numRows)
	{
		return data;
	}
	//data[0] = (numRows, 0);
	int i, j;
	data[0].push_back(1);
	for (i=1;i<numRows;++i)
	{
		data[i] = data[i-1];
		for (j=i-1;j>0;--j)
		{
			data[i][j] += data[i][j - 1];

		}
		//data[i][j].push_back(1);
		data[i].push_back(1);//∂‘”¶i-1
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
int mainvg()
{
	yanghui(10);
	system("pause"); 
	return 0;
}