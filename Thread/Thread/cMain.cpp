#include <iostream>
#include <thread>	
#include <atomic>
using namespace std;

atomic<int> num = 0;

int main()
{
	int expected = 0; //예상되는 값
	int desired = 1; //원하는 값

	//num == expected -> num = desired;
	//값이 같아서 바꿧으면 true 아니면 false
	bool res = num.compare_exchange_weak(expected,desired);
	cout << res << endl;
	//res = num.compare_exchange_weak(expected, desired);
	//cout << res << endl;

	//값이 바뀔때까지 반복
	res =num.compare_exchange_strong(desired,expected);
	cout << res << endl;
	return 0;
}