#include "GameManager.h"
using namespace std;

int main()
{
	//최초 호출에만 할당
	GameManager::GetInstance()->HelloWorld() ;

	//재활용
	GameManager::GetInstance()->HelloWorld();

	return 0;
}
