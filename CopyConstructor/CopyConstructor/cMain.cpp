#include <iostream>

using namespace std;

class Obj
{
public:
	int num;
public:
	Obj() { cout << "생성자" << endl; }
	Obj(int num) { cout << num << " 생성자" << endl; }
	//Obj& other = a;
	Obj(Obj& other) { cout << "복사 생성자" << endl; }
	~Obj() { cout << "소멸자" << endl; }
};


int main()
{

	Obj obj(1);

	Obj a;	 //생성자
	cout << "==============" << endl;
	a.num = 1;

	Obj b = a;	//복사 생성자
	Obj c(a);   //복사 생성자

	cout << &b << endl;


	return 0;  //소멸자, 소멸자
}

