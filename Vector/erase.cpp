#include <iostream>
#include <vector>
using namespace std;

int maindcvdx()
{
	unsigned int i;
	vector<unsigned int> myvector;

	// set some values (from 1 to 10)
	for (i = 1; i <= 10; i++) 
		myvector.push_back(i);

	// erase the 6th element,������5��
	myvector.erase(myvector.begin() + 5);

	// erase the first 3 elements:
	myvector.erase(myvector.begin(), myvector.begin() + 3);

	cout << "myvector contains:";
	for (i = 0; i < myvector.size(); i++)
		cout << " " << myvector[i];
	cout << endl;

	system("pause");
	return 0;
}
