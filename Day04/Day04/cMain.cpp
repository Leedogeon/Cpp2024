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
		cout << "1.�����Է� 2.�����˻� 3.��ü�˻� 4.�������� 5.����  :  ";
		
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
		case 5: cout << "���α׷��� �����մϴ�" << endl;
			exit(0);
			break;
		}
		Sleep(1000);
	}
}

