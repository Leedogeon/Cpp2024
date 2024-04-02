#include <iostream>

using namespace std;

class Obj
{
public:
	int num = 0;
public:
	//1.
	Obj() { cout << "������" << endl; }
	//2.
	Obj(Obj& other) noexcept { cout << "�ް� ���� ���� ������" << endl; }
	Obj(Obj&& other) noexcept { num = other.num; cout << "�̵� ���� ������ ȣ��" << endl; }
public:
	//3.
	//this == �Ҵ�� �� Ŭ���� �ּ�
	Obj& operator=(Obj&& other)noexcept { cout << "������ ���� ���� operator" << endl; return *this; }
};


int main()
{
	//1.
	Obj a;

	a.num = 1;

	cout << "===============" << endl;

	//�̵� ������ ȣ��
	//std::move() a�� ������ ������ �ٲ�
	Obj b = std::move(a);

	Obj c;
	//3. �̵� ���� ������
	c = std::move(b);

	cout << a.num << endl;
	cout << b.num << endl;
	cout << c.num << endl;

	return 0;
}