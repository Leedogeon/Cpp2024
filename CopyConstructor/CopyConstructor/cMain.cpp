#include <iostream>

using namespace std;

class Obj
{
public:
	int num;
public:
	Obj() { cout << "������" << endl; }
	Obj(Obj& other) { cout << "���� ������" << endl; }
	~Obj() { cout << "�Ҹ���" << endl; }
};


int main()
{
	Obj a;	 //������
	cout << "==============" << endl;
	a.num = 1;

	Obj b = a;	//���� ������

	cout << b.num << endl;


	return 0;  //�Ҹ���, �Ҹ���
}

