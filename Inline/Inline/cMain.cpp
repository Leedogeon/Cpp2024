#include<iostream>
using namespace std;

#define Add(a,b) { a + b }

int main()
{
	int inum = Add(1,2);
	float fnum = Add(1.1f, 2);

	cout << inum << endl;
	cout << fnum << endl;
}