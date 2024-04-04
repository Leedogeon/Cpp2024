#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
using namespace std;

vector<int> numbers;;
mutex mtx;

//lockguard 구현
template<typename T>
class LockGuard
{
private:
	T* mutx;
public:
	LockGuard(T& m)
	{
		mutx = &m;
		mutx->lock();
	}
	~LockGuard()
	{
		mutx->unlock();
	}
};

void Push()
{
	for (int i = 0; i < 10000; i++)
	{
		//mtx.lock();
		//LockGuard<mutex> lock(mtx);
		lock_guard<mutex> lock(mtx);
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