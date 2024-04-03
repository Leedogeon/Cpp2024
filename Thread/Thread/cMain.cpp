#include<iostream>
#include<thread>
using namespace std;

void ThreadFunc(int index)
{
	cout << "tread " << index << endl;
}

int main()
{
	thread t(ThreadFunc, 1);
	thread t2;
	t2 = thread(ThreadFunc, 2);
	cout << "main" << endl;

	t.join();//thread Á¾·á
	t2.join();
	return 0;
}