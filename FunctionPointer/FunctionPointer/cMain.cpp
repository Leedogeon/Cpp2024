#include <iostream>
using namespace std;

void Call(void(*p)())
{
	p();
}
void A()
{
	cout << "A" << endl;
}
void B()
{
	cout << "B" << endl;
}
int main()
{
	Call(A);
	Call(B);
	return 0;
}