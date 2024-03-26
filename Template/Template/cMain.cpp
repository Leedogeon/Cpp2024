#include <iostream>
using namespace std;

template <typename T>
class A
{
public:
	T temp;
public:
	//A() {}
	A<T>() {} // default »ı¼ºÀÚ
	A<T>(T data)
	{
		temp = data;
	}
	//~A() {}
	~A<T>() {}
};

int main()
{

	A<int> a; // T == int
	a.temp = 1;

	A<float> b(1.1); // T == float

	return 0;
}