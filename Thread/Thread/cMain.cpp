#include <iostream>
#include <thread>	
#include <atomic>
using namespace std;

atomic<int> num = 0;

int main()
{
	int expected = 0; //����Ǵ� ��
	int desired = 1; //���ϴ� ��

	//num == expected -> num = desired;
	//���� ���Ƽ� �مf���� true �ƴϸ� false
	bool res = num.compare_exchange_weak(expected,desired);
	cout << res << endl;
	//res = num.compare_exchange_weak(expected, desired);
	//cout << res << endl;

	//���� �ٲ𶧱��� �ݺ�
	res =num.compare_exchange_strong(desired,expected);
	cout << res << endl;
	return 0;
}