#include "StudentInfo.h"
int stdCheck = 0;
int allStd = 0;
void StudentInfo::ResetInfo()
{
	for (int i = 0; i < MaxStd; i++)
	{
		students[i] = nullptr;
	}
}

void StudentInfo::inputInfo(string _name, int _kor, int _eng, int _math)
{
	
	if (stdCheck == MaxStd)
	{
	
		if (allStd != MaxStd)
		{
			for (int i = 0; i < MaxStd; i++)
			{
				if (students[i] == nullptr)
				{
					students[i] = new Students;
					students[i]->name = _name;
					students[i]->kor = _kor;
					students[i]->eng = _eng;
					students[i]->math = _math;
					cout << "������� ������ �߰��Ǿ����ϴ�. �л��� : " << allStd + 1 << endl;
					allStd++;
					break;
				}
			}
		}
		else
		{
			cout << "������ ����á���ϴ�." << endl;
		}
				
	}
	else
	{
		students[stdCheck] = new Students;
		students[stdCheck]->name = _name;
		students[stdCheck]->kor = _kor;
		students[stdCheck]->eng = _eng;
		students[stdCheck]->math = _math;
		
		cout << "������ �߰��Ǿ����ϴ�. �л��� : " << allStd+1 << endl;
		allStd++;
		stdCheck++;
	}

	

}

void StudentInfo::viewInfo(string _name)
{
	for (int i = 0; i < stdCheck; i++)
	{
		if (students[i]->name == _name)
		{
			cout << students[i]->name << " �л��� ���� " << "���� : " << students[i]->kor << ", ���� : " << students[i]->eng << ", ���� : " << students[i]->math << endl;
			
		}
	}	
}

void StudentInfo::viewAll()
{
	for (int i = 0; i < stdCheck; i++)
	{
		if (students[i] == nullptr)
		{
			cout << "EMPTY" << endl;
		}
		else
		{
			cout << students[i]->name << " �л��� ���� " << "���� : " << students[i]->kor << ", ���� : " << students[i]->eng << ", ���� : " << students[i]->math << endl;
		}
		

	}
}

void StudentInfo::deleteInfo(string _name)
{
	for (int i = 0; i < stdCheck; i++)
	{
		if (students[i] == nullptr) continue;

		else if (students[i]->name == _name)
		{
			cout << students[i]->name << "�л��� ������ �����Ǿ����ϴ�." << endl;
			delete students[i];
			students[i] = nullptr;
			allStd--;
		}
	}
}

