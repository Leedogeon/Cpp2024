#include "Function.h"
#include "StudentInfo.h";
string sName;
StudentInfo stdi;
void Function::Start()
{
	stdi.ResetInfo();
}
void Function::Input()
{
	int kor;
	int eng;
	int math;
	cout << "������ �Է����ּ���\n" << endl;
	cout << "�̸� : ";
	cin >> sName;
	cout << "�������� : ";
	cin >> kor;
	cout << "�������� : ";
	cin >> eng;
	cout << "�������� : ";
	cin >> math;
	stdi.inputInfo(sName, kor, eng, math);
}

void Function::Find()
{
	cout << "�л��� �̸� : ";
	cin >> sName;
	stdi.viewInfo(sName);
}

void Function::FindAll()
{
	stdi.viewAll();
}

void Function::DeleteInfo()
{
	cout << "������ ������ �л��� �̸� : ";
	cin >> sName;
	stdi.deleteInfo(sName);
}