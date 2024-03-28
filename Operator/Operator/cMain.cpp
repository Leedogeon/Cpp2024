#include <iostream>
using namespace std;

class Obj
{
public:
	int x;
	int y;
public:
	Obj operator +(const Obj& other)
	{
		Obj obj;
		obj.x = x + other.x;
		obj.y = x + other.y;

		return obj;
	}
};

int main()
{
	Obj a;
	a.x = 1;
	a.y = 1;

	Obj b;
	b.x = 2;
	b.y = 2;

	Obj c{ a.x + b.x, a.y + b.y };
	Obj d = a + b;

}
