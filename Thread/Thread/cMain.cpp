#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
using namespace std;

vector<int> numbers;;
mutex mtx;

void Push()
{
	for (int i = 0; i < 10000; i++)
	{
		//mtx.lock();
		unique_lock<mutex> lock(mtx, defer_lock); // 나중에 lock 하도록 설정
		lock.lock();//수동 잠금

		// 내 스레드가 건드리고 있으면 스레드가 못건드림
		numbers.push_back(1);
	}
}

int main()
{
	thread t1(Push);
	thread t2(Push);

	t1.join();
	t2.join();

	cout << numbers.size() << endl;
	return 0;
}