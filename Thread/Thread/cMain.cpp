#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
using namespace std;

vector<int> numbers;;
mutex mtx;

//lockguard ����
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
		// �� �����尡 �ǵ帮�� ������ �����尡 ���ǵ帲
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