#include <iostream>

using namespace std;

template <typename T>
void A(T a)
{}

template <typename T> // 포인터 전용
void B(T* a)
{}

template <typename T>
void C(T& a)
{
}

int main()
{
	A(1); // T == int
	B(new int);// T == int

	int a = 0;
	A(a);
	B(&a); // int

	C(a); //int& a = a;
	C(new int); // T == int*  int*& a = new int;


	int* t;

	return 0;
}