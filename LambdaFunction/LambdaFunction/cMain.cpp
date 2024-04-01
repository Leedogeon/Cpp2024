#include <iostream>
using namespace std;

using P = void(*)();
void A()
{
	cout << "Test" << endl;
}

int main()
{
	P p;
	p = []() {cout << "TEST" << endl; };
	p();
}