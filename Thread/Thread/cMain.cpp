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

	t.join();//thread ����
	return 0;
}