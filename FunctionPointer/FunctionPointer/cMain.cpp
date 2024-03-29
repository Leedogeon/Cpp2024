#include <iostream>

using namespace std;

int Add(int a, int b) { return a + b; }

//typedef 함수반환형(*함수포인터 자료형 이름)(함수 매개변수 데이터 타입들);
typedef int(*A)(int, int);

int main()
{
	int(*p)(int, int) = Add;
	int(*p2)(int, int) = Add;

	A p3 = Add;
	A p4 = NULL;
	p4 = p3;
	cout << p4(1, 2) << endl;

	return 0;
}