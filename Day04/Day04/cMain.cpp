#include "StudentInfo.h";
#include "Function.h"
Function Fc;
int main()
{
	Fc.Start();
	int what = 0;
	while (true)
	{
		system("cls");
		cout << "1.정보입력 2.정보검색 3.전체검색 4.정보삭제 5.종료  :  ";
		
		cin >> what;
		switch (what)
		{
		case 0: 
		case 1: Fc.Input();
			break;
		case 2: Fc.Find();
			break;
		case 3: Fc.FindAll();
			break;
		case 4: Fc.DeleteInfo();
			break; 
		case 5: cout << "프로그램을 종료합니다" << endl;
			exit(0);
			break;
		}
		Sleep(1000);
	}
}

