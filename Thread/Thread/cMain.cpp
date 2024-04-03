#include <iostream>
#include <thread>
#include <atomic> 

using namespace std;

atomic<int> num = 0;

int main()
{
	int expected = 0; // ����Ǵ� ��
	int desired = 1;  // ���ϴ°�

	//������ ������ ������ �ݺ�
	bool result = num.compare_exchange_strong(expected, desired);

	while (true)
	{
		//compare_exchange_weak �Լ��� ���������� ��� ���� ���� �ҷ��� �õ�
		num.compare_exchange_weak(expected, desired);
	}

	return 0;
}