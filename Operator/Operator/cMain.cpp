#include <iostream>

using namespace std;

class Pet
{};

class Obj
{
public:
	int key;
public:
	bool operator==(const Obj& other)
	{
		return key == other.key;
	}

	bool operator!=(const Obj& other)
	{
		return key != other.key;
	}

};

int main()
{
	Obj a;
	a.key = 1;
	Obj b;
	b.key = 2;

	if (a != b)
	{
		cout << "a��b�� ���� ����" << endl;
	}


	return 0;
}