#include <iostream>
using namespace std;
int FindMax(int num[], int size) {
#if 1
	if (size <= 0)
	{
		return 0;
	}
	int max = num[0];
	int tmp = num[0];
	for (int i = 1; i < size; i++)
	{
		tmp = tmp + num[i];
		if (num[i] > tmp)
			tmp = num[i];
		if (tmp > max)
			max = tmp;
	}
	return max;
#else
	int *f = new int[size];
	f[0] = num[0];
	for (int i = 1; i < size; i++)
	{
		if (f[i - 1] + num[i] > num[i])
			f[i] = f[i - 1] + num[i];
		else
			f[i] = num[i];
	}
	int max = f[0];
	for (int i = 1; i < size; i++)
		if (max < f[i])
			max = f[i];
	delete[] f;
	return max;
#endif
	
}
int maincdsa()
{
	int num[7] = {1,-5,6,7,-3,5,2};
	cout << FindMax(num, 7);
	system("pause"); 
	return 0;
}