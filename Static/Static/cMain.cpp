#include <iostream>

using namespace std;

class A
{
public:
	static int num;

	static void Print()
	{
		cout << "Hello World"<<endl;
	}
};

int A::num = 0;

int main()
{
	A a;
	a.Print();
	A::Print();
	return 0;
}
