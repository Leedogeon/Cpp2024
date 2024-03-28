#include <iostream>

using namespace std;

class A
{
public:
	//멤버 변수들
	int a;
	int b;
public:
	//이함수는 클라스의 멤버 변수 변경 불가
	void Function()	const
	{
		//  a=12  << X
	}
};


int main()
{

	return 0;
}