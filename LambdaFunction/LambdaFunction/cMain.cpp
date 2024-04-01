#include <iostream>
using namespace std;

void A()
{
	cout << "Test" << endl;
}

int main()
{
	int res = 0;
	A();
	res = [](int a, int b)
		{
			cout << "Lambda" << endl;
			return a+b;
		}(1,2);
	cout << res << endl;
}