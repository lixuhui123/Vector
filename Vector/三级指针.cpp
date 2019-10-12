#include <iostream>
#include <stdio.h>
using namespace std;
int main()
{
	const char *p[] = { "TENCENT","CAMPUS","RECRUITING" };
	const char **pp[] = { p + 2,p + 1,p };
	const char ***ppp = pp;
	printf("%s", **++ppp);
	printf("%s", *++*++ppp);
	system("pause"); 
	return 0;
}