#include <iostream>
using namespace std;

int(*p)(int, int);

void Register(int(*_p)(int, int))
{
	p = _p;
}

int Call(int a, int b)
{
	return	p(a, b);
}


int main()
{
	Register([](int a, int b) {return a + b; });
	cout << "=====================" << endl;
	cout << Call(1, 1) << endl;

	Register([](int a, int b) {return a - b; });
	cout << Call(1, 1) << endl;
	return 0;
}

