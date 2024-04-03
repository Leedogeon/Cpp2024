#include<iostream>
#include<thread>
using namespace std;

void ThreadFunc()
{
	cout << "tread" << endl;
}

int main()
{
	thread t(ThreadFunc);
	cout << "main" << endl;

	t.join();//thread Á¾·á
	return 0;
}