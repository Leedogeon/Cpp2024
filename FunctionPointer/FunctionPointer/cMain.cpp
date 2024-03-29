#include <iostream>
#include <functional>// 호출

using namespace std;

void A()
{
	cout << "A" << endl;
}

void B()
{
	cout << "B" << endl;
}

//함수 포인터
function<void()> callback;

void Register(function<void()> _callback)
{
	callback = _callback;
}

void Call()
{
	callback();
}

int main()
{
	Register(A);
	Call();

	Register(B);
	Call();


	return 0;
}