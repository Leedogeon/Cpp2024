#include "Deque.h"
#include <Windows.h>
int main()
{
	Deque que;

	while (true)
	{
		system("cls");
		int num = 0;
		int data = 0;
		cout << "1.�Է�, 2.���� 3.countȮ�� 4.����Ȯ�� ,5.�ʱ�ȭ" << endl;
		cout << "�Է� : ";
		cin >> num;

		switch (num)
		{
		case 1: cout << "���� �Է� : ";
			cin >> data;
			que.Enqueue(data);
			break;
		case 2: cout << "1. �պ��� ���� , 2. �ں��� ���� : ";
			cin >> data;
			if (data != 1 && data != 2) break;
			else que.Dequeue(data);
			break;
		case 3: que.Count();
			break;
		case 4: que.Check();
			break;
		case 5: que.Clear();
			break;
		default:
			break;
		}
		Sleep(1000);
	}

	return 0;
}