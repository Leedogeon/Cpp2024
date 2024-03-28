#include <iostream>

using namespace std;

class A
{
public:
	void Function(const int& x)
	{
	}
};

// 참조로 전달된 x의 값을 
//Function 내에서 변경 불가
void Function(const int& x)
{
}


int main()
{

	return 0;
}