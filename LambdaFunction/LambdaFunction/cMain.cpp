#include <iostream>
using namespace std;

using P = int(*)();
void A()
{
	cout << "Test" << endl;
}

int main()
{
	P p;
	p = []() -> int {cout << "TEST" << endl; return 0; };
	p();
}