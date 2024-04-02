#include <iostream>

using namespace std;

//�ް� ����
void Value(int& num)
{
	cout << "�ް� ���� : " << num << endl;
}

//������ ����
void Value(int&& num)
{
	cout << "������ ���� : " << num << endl;
}

//���� ����
//T&& T �ް� -> �ް� / T ������ -> ������
template<typename T> // template�ε� &&
void Forwarder(T&& arg) // ������ ���� �ƴ�
{
	Value(std::forward<T>(arg)); //������ ���� �� ī�װ��� �����ϸ� ����
}

int main()
{
	int a = 5;

	Forwarder(a); // a�� lvalue, T&& left value ����

	Forwarder(5); // 5�� rvalue, T&& right value ����

	return 0;
}