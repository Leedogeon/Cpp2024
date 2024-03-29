#include<iostream>
using namespace std;
void A()
{
	cout << "Hello World" << endl;
}
int main()
{
	void(*p)();
	p = A;

	A();
	p();

	return 0;
}