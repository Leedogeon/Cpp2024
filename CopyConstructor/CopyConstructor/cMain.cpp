#include <iostream>

using namespace std;

class Obj
{
public:
	int num;
public:
	Obj() { cout << "������" << endl; }
	Obj(int num) { cout << num << " ������" << endl; }
	//Obj& other = a;
	Obj(Obj& other) { cout << "���� ������" << endl; }
	~Obj() { cout << "�Ҹ���" << endl; }
};


int main()
{

	Obj obj(1);

	Obj a;	 //������
	cout << "==============" << endl;
	a.num = 1;

	Obj b = a;	//���� ������
	Obj c(a);   //���� ������

	cout << &b << endl;


	return 0;  //�Ҹ���, �Ҹ���
}

