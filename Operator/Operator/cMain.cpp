#include <iostream>

using namespace std;

class Obj
{
public:
	int a;
	int b;
public:
	Obj() = default;
	Obj(const Obj& other)
	{
		cout << "Copy" << endl;
	}
	Obj& operator=(const Obj& other)
	{
		cout << "Operator=" << endl;
		return *this;
	}

};

int main()
{
	Obj a;
	a.a = 1;
	a.b = 2;

	Obj b = a;
	Obj c;
	c = a;
	cout << "c.a : " << c.a << " / c.b : " << c.b << endl;


	return 0;
}