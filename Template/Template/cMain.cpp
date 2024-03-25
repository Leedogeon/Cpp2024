#include<iostream>
using namespace std;

template<typename T1, typename T2>
T2 Add(T1 a, T2 b)
{
	return a + b;
}

int main()
{
	cout << Add(1, 2) << endl;
	cout << Add(1, 2.2f) << endl;

	return 0;
}