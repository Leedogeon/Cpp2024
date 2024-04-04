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
	//읽기전용 - 모든 접근 허용
	//unique_lock 작동시 대기
	shared_lock<shared_mutex> lock(rwLock);
	cout << "Redaer : " << id << "is reading\n";
 }

void WriteFunction(int id)
{
	//쓰기전용 - 유일성 보장
	//shared_lock 작동시 대기했다가 씀
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