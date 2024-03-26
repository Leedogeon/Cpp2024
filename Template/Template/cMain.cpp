#include<iostream>
using namespace std;

template<typename T>
struct A
{
	T temp;
};

int main()
{
	A<int> a;
	a.temp = 1;
	cout << a.temp << endl;
	A<float> b;
	b.temp = 1.1;
	cout << b.temp << endl;
	return 0;
}