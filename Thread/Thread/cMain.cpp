#include <iostream>
#include <thread>	
#include <atomic>
using namespace std;

//res에 대한 동시접근이 원자적으로 차단
atomic<int> res;

void Add()
{
	for (int i = 0; i < 100000; i++)
	{
		//res++;
		res.fetch_add(1);
	}
}
void Sub()
{
	for (int i = 0; i < 100000; i++)
	{
		//res--;
		//res.fetch_add(-1);
		res.fetch_sub(1);
	}
}
int main()
{
	//res = 0;
	res.store(0);

	thread t1(Add);
	thread t2(Sub);

	t1.join();
	t2.join();

	cout << res << endl;

	return 0;
}