#include <iostream>

using namespace std;


int main()
{
	int a = 5;
	std::move(a); // 왼값 --> 오른값으로 처리
	std::forward<int>(a); //왼값 --> 왼값으로 처리
	std::forward<int>(5); //오른값 --> 오른값으로 처리

	return 0;
}