#include<iostream>
using namespace std;

inline int Add(int a, int b)
{
	return a + b;
};

int main()
{
	int inum = Add(1,2);

	cout << inum << endl;
}