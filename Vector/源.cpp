//#include <iostream>
//#include <vector>
//using namespace std;
//int FindGreatestSumOfSubArray(vector<int> array)
//{
//	/* 最大连续子串和 */
//	if (array.size() <= 0)
//	{
//		return 0;
//	}
//	int max = array[0];
//	int tmp = array[0];
//	for (int i = 1; i < array.size(); i++)
//	{
//		tmp = tmp + array[i];
//		if (array[i] > tmp)
//			tmp = array[i];
//		if (tmp > max)
//			max = tmp;
//	}
//	return max;
//
//}
//int main()
//{
//	
//	system("pause"); 
//	return 0;
//}