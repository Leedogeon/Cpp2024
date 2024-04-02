#include <iostream>

using namespace std;

class Obj
{
public:
	int num = 0;
public:
	//1.
	Obj() { cout << "생성자" << endl; }
	//2.
	Obj(Obj& other) noexcept { cout << "왼값 참조 복사 생성자" << endl; }
	Obj(Obj&& other) noexcept { num = other.num; cout << "이동 복사 생성자 호출" << endl; }
public:
	//3.
	//this == 할당된 내 클라스의 주소
	Obj& operator=(Obj&& other)noexcept { cout << "오른값 참조 대입 operator" << endl; return *this; }
};


int main()
{
	//1.
	Obj a;

	a.num = 1;

	cout << "===============" << endl;

	//이동 생성자 호출
	//std::move() a를 오른값 참조로 바꿈
	Obj b = std::move(a);

	Obj c;
	//3. 이동 대입 연산자
	c = std::move(b);

	cout << a.num << endl;
	cout << b.num << endl;
	cout << c.num << endl;

	return 0;
}