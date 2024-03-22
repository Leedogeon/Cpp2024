#include "GameManager.h"

class A
{
private:

public:
	static A& Create()
	{
		static A a;	// 유일하게 하나만
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
