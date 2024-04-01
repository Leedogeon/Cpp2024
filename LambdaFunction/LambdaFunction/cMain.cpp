#include <iostream>
using namespace std;

int main()
{
	int numA = 1;
	int numB = 2;

	//새로 할당된 numA와 numB 는 람다에 속함
	//int numA = numA(1); 복사해서 값을 넣어줌
	[numA, numB]() {cout << numA << ", "  << numB << endl; }();
}