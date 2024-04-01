#include <iostream>
#include <functional>

using namespace std;

//2
typedef int(*TypeP)(int, int);

//3	 c++11
using UsingP = int(*)(int, int);


int main()
{
	//1
	int(*p)(int, int);
	p = [](int a, int b) {return a + b; };

	//2
	TypeP typeP = [](int a, int b) {return a + b; };

	//3
	UsingP usingP = [](int a, int b) {return a + b; };

	//4
	std::function<int(int, int)> funcP = [](int a, int b) {return a + b; };

	auto a = 3; // auto -> int
	auto b = 1.1f; //auto -> float

	//5 
	auto autoP = [](int a, int b) {return a + b; };

	cout << p(1, 2) << endl;
	cout << typeP(1, 2) << endl;
	cout << usingP(1, 2) << endl;
	cout << funcP(1, 2) << endl;
	cout << autoP(1, 2) << endl;

	return 0;
}

