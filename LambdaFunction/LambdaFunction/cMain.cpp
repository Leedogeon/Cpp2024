#include <iostream>
using namespace std;

int main()
{
	int numA = 1;
	int numB = 2;
	cout <<  "numA : " << &numA << endl;
	cout << "numB : " << &numB << endl;

	//새로 할당된 numA와 numB 는 람다에 속함
	//int numA = numA(1); 복사해서 값을 넣어줌
	//[&numA, numB]() {cout << "lambda numA :"  << &numA << endl; }();
	[&]() {cout << "lambda numA :" << &numA << endl;
	cout << "lambda numB :" << &numB << endl;
		}();

	[=]() {cout << "lambda numA :" << &numA << endl;
	cout << "lambda numB :" << &numB << endl;
		}();

}