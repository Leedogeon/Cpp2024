#include <iostream>
#include <thread>
#include <atomic> 

using namespace std;

atomic<int> num = 0;

int main()
{
	int expected = 0; // 예상되는 값
	int desired = 1;  // 원하는값

	//num(0) == expected(0) -> num = desired;
	//값이 같아서 바꿧으면 true 아니면 false
	bool result = num.compare_exchange_weak(expected, desired);
	cout << result << endl;

	//num.compare_exchage_weak
	if (num == expected) // num이 예상 되는 값이라면
	{
		//만약에 다른 스레드의 방해로 중간에 실패
		num = desired;
		expected = num;
		return true;
	}
	else
	{
		expected = num;
		return false;
	}

	//예상되는 값이 바뀜
	cout << expected << endl;

	return 0;
}
