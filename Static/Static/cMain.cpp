#include "GameManager.h"
using namespace std;

int main()
{
	//���� ȣ�⿡�� �Ҵ�
	GameManager::GetInstance()->HelloWorld() ;

	//��Ȱ��
	GameManager::GetInstance()->HelloWorld();

	return 0;
}
