#include<iostream>
using namespace std;

int main()
{
	char a;
	//1. �� ����Ұ�
	const char c = a;

	//2. ���ʸ� ���� �Ұ�
	const char* c = &a;
	char* const c = &a;

	//3. ��,�ּ� ���� �Ұ�
	const char* const c = &a;
}