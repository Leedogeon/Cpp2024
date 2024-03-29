#include <iostream>

using namespace std;

template<typename T>
T Add(T a, T b) { return a + b; }
template<typename T>
T Sub(T a, T b) { return a - b; }
template<typename T>
T Mul(T a, T b) { return a * b; }
template<typename T>
T Div(T a, T b) { return a / b; }

template<typename T>
T Calculator(T(*p)(T, T), T valueA, T valueB)
{
	return p(valueA, valueB);
}


int main()
{
	cout << Calculator(Add, 1.1, 2.2) << endl;
	cout << Calculator(Sub, 1, 2) << endl;
	cout << Calculator(Mul, 1.1, 2.2) << endl;
	cout << Calculator(Div, 1, 2) << endl;

	return 0;
}