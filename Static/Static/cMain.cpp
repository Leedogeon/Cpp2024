#include <iostream>
#include "GameManager.h"
using namespace std;


int A::num = 0;

int main()
{
	//최초 호출에만 할당
	GameManager::GetInstance();

	//재활용
	GameManager::GetInstance();

	return 0;
}
