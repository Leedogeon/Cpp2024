#pragma once
#include "Header.h"

struct Students
{
	string name;
	int kor;
	int eng;
	int math;
};
class StudentInfo
{
private:
	Students* students[MaxStd] = {};
	
public:
	void ResetInfo();

	void inputInfo(string _name, int _kor, int _eng, int _math);
	void viewInfo(string _name);
	void viewAll();
	void deleteInfo(string _name);
};

