#include <iostream>

using namespace std;

int Add(int a, int b) { return a + b; }

//typedef �Լ���ȯ��(*�Լ������� �ڷ��� �̸�)(�Լ� �Ű����� ������ Ÿ�Ե�);
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