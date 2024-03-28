#include <iostream>

using namespace std;

class Obj
{
public:
	int *a;
public:
	Obj() = default;
	Obj(const Obj& other)
	{
		a = new int;
		*a = *other.a;
		cout << "Copy" << endl;
	}
	Obj& operator=(const Obj& other)
	{
		a = new int;
		*a = *other.a;
		cout << "Operator=" << endl;
		return *this;
	}

};

int main()
{
	Obj a;
	a.a = new int;
	*a.a = 12;

	Obj b = a;
	Obj c;
	c = b;
	delete a.a;

	cout << a.a  << " , " << b.a << " , " << c.a << endl;
	return 0;
}