#include<Windows.h>
#include "Stack.h"
using namespace std;

int main()
{	
	Stack stk;
	stk.Clear();
	while (true)
	{
		system("cls");
		int num = 0;
		int data = 0;
		cout << "1.�Է�, 2.���� 3.countȮ��, 4.����Ȯ��, 5.����Ȯ�� ,6.�ʱ�ȭ" << endl;
		cout << "�Է� : ";
		cin >> num;

		switch (num)
		{
		case 1: cout << "���� �Է� : ";
			cin >> data;
			stk.Push(data);
			break;
		case 2: stk.Pop();
			break;
		case 3: stk.Count();
			break;
		case 4: stk.IsEmpty();
			break;
		case 5: stk.Check();
			break;
		case 6: stk.Clear();
		default:
			break;
		}
		Sleep(1000);
	}
	
	return 0;
}