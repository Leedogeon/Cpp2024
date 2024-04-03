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

	//t 스레드가 joinable 상태인 경우 == t.join()함수를 호출 할수 있는 경우
	if (t.joinable())
	{
		//t 스레드가 실행이 끝날때 까지 대기
		t.join();
	}

	return 0;
}