#include <iostream>
using namespace std;


struct Obj
{
	int x;
	int y;
};


static void Test(Obj&& obj)
{
	obj.x = 1;
	obj.y = 2;
	cout << "������ ���� : x " << obj.x << " / y : " << obj.y << endl;

}

int main()
{
	Obj a;
	Test(Obj());

	return 0;
}