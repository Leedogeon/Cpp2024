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
		cout << "1.입력, 2.제거 3.count확인 4.정보확인 ,5.초기화" << endl;
		cout << "입력 : ";
		cin >> num;

		switch (num)
		{
		case 1: cout << "정보 입력 : ";
			cin >> data;
			que.Enqueue(data);
			break;
		case 2: cout << "1. 앞부터 제거 , 2. 뒤부터 제거 : ";
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