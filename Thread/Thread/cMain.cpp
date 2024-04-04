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
		unique_lock<mutex> lock(mtx, defer_lock); // ���߿� lock �ϵ��� ����
		lock.lock();//���� ���

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