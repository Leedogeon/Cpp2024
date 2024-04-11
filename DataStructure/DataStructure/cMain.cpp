#include<Windows.h>
#include "Stack.h"
using namespace std;

int main()
{	

	Stack stk;
	
	while (true)
	{
		system("cls");
		int num = 0;
		int data = 0;
		cout << "1.입력, 2.제거 3.count확인, 4.정보확인 ,5.초기화" << endl;
		cout << "입력 : ";
		cin >> num;

		switch (num)
		{
		case 1: cout << "정보 입력 : ";
			cin >> data;
			stk.Push(data);
			break;
		case 2: stk.Pop();
			break;
		case 3: stk.Count();
			break; 
		case 4: stk.Check();
			break;
		case 5: stk.Clear();
			break;
		default:
			break;
		}
		Sleep(1000);
	}
	
	return 0;
}