#include <iostream>

using namespace std;

//typedef 함수반환형(*함수포인터 자료형 이름)(함수 매개변수 데이터 타입들);
//typedef int(*Func)(int, int);

int Add(int a, int b) { return a + b; }

//C++
//using 타입정의 = 정의;
using Func = int(*)(int, int);

int main()
{
	Func a = NULL;
	a = Add;
	cout << a(1, 2) << endl;

	return 0;
}