#include <iostream>

using namespace std;

//C++ 11 บฮลอ
template<typename... Args>
void Print(Args... args)
{
	cout << "Args..." << endl;
}


int main()
{

	Print(1);
	cout << "============" << endl;
	Print(1, 2, 3.14f);
	cout << "============" << endl;
	Print(1, 2, "Hello world");
	cout << "============" << endl;
	Print("Hello world", 'a');

	return 0;
}