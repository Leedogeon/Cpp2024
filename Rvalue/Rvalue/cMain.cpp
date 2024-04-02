#include <iostream>

using namespace std;

//왼값 참조
void Value(int& num)
{
	cout << "왼값 참조 : " << num << endl;
}

//오른값 참조
void Value(int&& num)
{
	cout << "오른값 참조 : " << num << endl;
}

//보편 참조
//T&& T 왼값 -> 왼값 / T 오른값 -> 오른값
template<typename T> // template인데 &&
void Forwarder(T&& arg) // 오른값 참조 아님
{
	Value(std::forward<T>(arg)); //인자의 원래 값 카테고리를 유지하며 전달
}

int main()
{
	int a = 5;

	Forwarder(a); // a는 lvalue, T&& left value 대응

	Forwarder(5); // 5는 rvalue, T&& right value 대응

	return 0;
}