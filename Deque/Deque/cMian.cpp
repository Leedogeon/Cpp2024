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
		int sel = 0;
		cout << "1.�Է�, 2.���� 3.countȮ�� 4.����Ȯ�� ,5.�ʱ�ȭ" << endl;
		cout << "�Է� : ";
		cin >> num;

		switch (num)
		{
		case 1: cout << "���� �Է� : ";
			cin >> data;
			cout << "1. �տ� �߰�, 2. �ڿ��߰� : ";
			cin >> sel;
			if (sel != 1 && sel != 2) break;
			que.Enqueue(data,sel);
			break;
		case 2: cout << "1. �պ��� ���� , 2. �ں��� ���� : ";
			cin >> sel;
			if (sel != 1 && sel != 2) break;
			else que.Dequeue(sel);
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