#include <iostream>
#include "GameManager.h"
using namespace std;


int A::num = 0;

int main()
{
	//���� ȣ�⿡�� �Ҵ�
	GameManager::GetInstance();

	//��Ȱ��
	GameManager::GetInstance();

	return 0;
}
