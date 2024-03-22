#include <iostream>

using namespace std;

class A
{
public:
	static int a;
};

int A::a = 0;

int main()
{

	A a;
	A b;
	A c;
	a.a = 1;
	b.a = 1;
	c.a = 3;

	cout << a.a << endl;
	cout << b.a << endl;
	cout << c.a << endl;

	cout << &a.a << endl;
	cout << &b.a << endl;
	cout << &c.a << endl;
}