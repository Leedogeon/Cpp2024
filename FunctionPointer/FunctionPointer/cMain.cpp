#include <iostream>

using namespace std;

//typedef �Լ���ȯ��(*�Լ������� �ڷ��� �̸�)(�Լ� �Ű����� ������ Ÿ�Ե�);
//typedef int(*Func)(int, int);

int Add(int a, int b) { return a + b; }

//C++
//using Ÿ������ = ����;
using Func = int(*)(int, int);

int main()
{
	Func a = NULL;
	a = Add;
	cout << a(1, 2) << endl;

	return 0;
}