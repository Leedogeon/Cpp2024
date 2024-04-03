#include <iostream>
#include <thread>	
using namespace std;

int res = 0;

void Add()
{
	for (int i = 0; i < 100000; i++)
	{
		res++;
		//temp = res;
		//temp = temp+1;
		//res = temp;
	}
}
void Sub()
{
	for (int i = 0; i < 100000; i++)
	{
		res--;
		//temp = res;
		//temp = temp-1;
		//res = temp;
	}
}
int main()
{
	thread t1(Add);
	thread t2(Sub);

	t1.join();
	t2.join();

	cout << res << endl; //==> t1,t2동시 실행으로 문제생길수있음

	return 0;
}