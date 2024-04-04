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
		mtx.lock();
		// 내 스레드가 건드리고 있으면 스레드가 못건드림
		numbers.push_back(1);
		mtx.unlock();
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