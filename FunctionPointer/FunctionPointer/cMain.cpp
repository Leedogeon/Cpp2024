#include<iostream>
using namespace std;
void A()
{
	cout << "Hello World" << endl;
}
int main()
{
	void* p = A;
	(*(void(*)())p)();
	return 0;
}