#include <iostream>

using namespace std;


int main()
{
	int a = 5;
	std::move(a); // �ް� --> ���������� ó��
	std::forward<int>(a); //�ް� --> �ް����� ó��
	std::forward<int>(5); //������ --> ���������� ó��

	return 0;
}