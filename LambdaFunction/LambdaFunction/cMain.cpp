#include <iostream>
using namespace std;

int main()
{
	int numA = 1;
	int numB = 2;
	cout <<  "numA : " << &numA << endl;

	//���� �Ҵ�� numA�� numB �� ���ٿ� ����
	//int numA = numA(1); �����ؼ� ���� �־���
	[&numA, numB]() {cout << "lambda numA :"  << &numA << endl; }();
}