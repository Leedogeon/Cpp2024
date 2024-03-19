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
	cout << "정보를 입력해주세요\n" << endl;
	cout << "이름 : ";
	cin >> sName;
	cout << "국어점수 : ";
	cin >> kor;
	cout << "영어점수 : ";
	cin >> eng;
	cout << "수학점수 : ";
	cin >> math;
	stdi.inputInfo(sName, kor, eng, math);
}

void Function::Find()
{
	cout << "학생의 이름 : ";
	cin >> sName;
	stdi.viewInfo(sName);
}

void Function::FindAll()
{
	stdi.viewAll();
}

void Function::DeleteInfo()
{
	cout << "정보를 삭제할 학생의 이름 : ";
	cin >> sName;
	stdi.deleteInfo(sName);
}