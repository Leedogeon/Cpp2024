#include <iostream>
using namespace std;

class Obj
{
public:
	int lv = 1;
public:
	Obj& operator ++()
	{
		++lv; return *this;
	}
	Obj& operator ++(int)
	{
		lv++; return *this;
	}
};


int main()
{
	Obj a;
	a.lv = 1;

	Obj b = a++;

	cout << b.lv << endl;
}

