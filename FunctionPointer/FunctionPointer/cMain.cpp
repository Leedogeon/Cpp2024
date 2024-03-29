#include <iostream>
#include <functional>// »£√‚

using namespace std;

using P = void(*)(int, int);

void A()
{
	cout << "A" << endl;
}

int main()
{
	function<void()> a;
	function<void(void)> b;

	a = A;
	b = A;

	a();

	return 0;
}