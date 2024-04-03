#include <iostream>
#include <thread>
#include <atomic> 

using namespace std;

atomic<int> num = 0;

int main()
{
	int expected = 0; // 예상되는 값
	int desired = 1;  // 원하는값

	//조건이 충족될 때까지 반복
	bool result = num.compare_exchange_strong(expected, desired);

	while (true)
	{
		//compare_exchange_weak 함수를 원자적으로 계속 값을 변경 할려고 시도
		num.compare_exchange_weak(expected, desired);
	}

	return 0;
}