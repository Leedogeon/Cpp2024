#include <iostream>

using namespace std;

void Print()
{
	cout << "Finished!" << endl;
}

//C++ 11 บฮลอ
template<typename T, typename... Args>
void Print(T first, Args... args)
{
	cout << first << " / ";
	Print(args...);
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