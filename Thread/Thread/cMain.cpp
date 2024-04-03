#include <iostream>
#include <thread>	

using namespace std;

void ThreadFunc()
{
	cout << "Hello Thread" << endl;
	while (true)
	{

	}
}

int main()
{
	std::thread t(ThreadFunc);

	cout << "Main" << endl;

	//t �����尡 joinable ������ ��� == t.join()�Լ��� ȣ�� �Ҽ� �ִ� ���
	if (t.joinable())
	{
		//t �����尡 ������ ������ ���� ���
		t.join();
	}

	return 0;
}