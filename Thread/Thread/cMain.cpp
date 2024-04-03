#include <iostream>
#include <thread>
#include <atomic> 

using namespace std;

atomic<int> num = 0;

int main()
{
	int expected = 0; // ����Ǵ� ��
	int desired = 1;  // ���ϴ°�

	//num(0) == expected(0) -> num = desired;
	//���� ���Ƽ� �مf���� true �ƴϸ� false
	bool result = num.compare_exchange_weak(expected, desired);
	cout << result << endl;

	//num.compare_exchage_weak
	if (num == expected) // num�� ���� �Ǵ� ���̶��
	{
		//���࿡ �ٸ� �������� ���ط� �߰��� ����
		num = desired;
		expected = num;
		return true;
	}
	else
	{
		expected = num;
		return false;
	}

	//����Ǵ� ���� �ٲ�
	cout << expected << endl;

	return 0;
}
