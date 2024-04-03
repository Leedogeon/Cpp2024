#include <iostream>
#include <thread>	
#include <atomic>
using namespace std;

//res에 대한 동시접근이 원자적으로 차단
atomic<int> res = 0;

void Add()
{
	for (int i = 0; i < 100000; i++)
	{
		res++;
	}
}
void Sub()
{
	for (int i = 0; i < 100000; i++)
	{
		res--;
	}
}
int main()
{
	thread t1(Add);
	thread t2(Sub);

	t1.join();
	t2.join();

	cout << res << endl;

	return 0;
}