#include <iostream>
#include <vector>
using namespace std;
int singleNumber(vector<int>& nums) 
{
	int tmp = 0;
	for (auto &i:nums)
	{
		tmp ^= i;
	}
	return tmp;
}
int mainnhgfb()
{
	
	system("pause"); 
	return 0;
}