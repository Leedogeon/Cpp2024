#include<iostream>
using namespace std;

int main()
{
	char a;
	//1. 값 변경불가
	const char c = a;

	//2. 한쪽만 변경 불가
	const char* c = &a;
	char* const c = &a;

	//3. 값,주소 변경 불가
	const char* const c = &a;
}