#include <iostream>
using namespace std;

int main()
{
	int numA = 1;
	int numB = 2;

	//���� �Ҵ�� numA�� numB �� ���ٿ� ����
	//int numA = numA(1); �����ؼ� ���� �־���
	[numA, numB]() {cout << numA << ", "  << numB << endl; }();
}