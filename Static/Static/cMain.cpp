#include "GameManager.h"

class A
{
private:

public:
	static A& Create()
	{
		static A a;	// �����ϰ� �ϳ���
		return a;

	}

public:
	void HelloWorld() { cout << "Hello world" << endl; }
};



int main()
{
	A::Create().HelloWorld();

	A::Create().HelloWorld();
	return 0;
}
