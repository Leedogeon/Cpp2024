#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
#include <shared_mutex>
using namespace std;

vector<int> numbers;

shared_mutex rwLock;


void ReadFunction(int id)
{
	//�б����� - ��� ���� ���
	//unique_lock �۵��� ���
	shared_lock<shared_mutex> lock(rwLock);
	cout << "Redaer : " << id << "is reading\n";
 }

void WriteFunction(int id)
{
	//�������� - ���ϼ� ����
	//shared_lock �۵��� ����ߴٰ� ��
	unique_lock<shared_mutex> lock(rwLock);
	cout << "Writer : " << id << "is writing\n";
}


int main()
{
	thread readers[5];
	thread writers[2];

	for (int i = 0; i < 5; i++)
	{
		readers[i] = thread(ReadFunction, i);
	}
	for (int i = 0; i < 2; i++)
	{
		writers[i] = thread(WriteFunction, i);
	}

	for (int i = 0; i < 5; i++)
	{
		if (readers[i].joinable())
		{
			readers[i].join();
		}
	}
	for (int i = 0; i < 2; i++)
	{
		if (writers[i].joinable())
		{
			writers[i].join();
		}
	}
	return 0;
}