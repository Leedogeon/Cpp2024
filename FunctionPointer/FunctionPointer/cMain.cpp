#include <iostream>
#include <functional>// »£√‚

using namespace std;



bool A(int a, int b)
{
	cout << "A" << endl;
	return true;
}

bool B(int a, int b)
{
	cout << "B" << endl;
	return false;
}

using Func = function<bool(int, int)>;
//function<bool(int, int)> funcs[2];
Func funcs[2];

int main()
{
	funcs[0] = A;
	funcs[1] = B;

	for (int i = 0; i < 2; i++)
	{
		funcs[i](1, 1);
	}

	return 0;
}