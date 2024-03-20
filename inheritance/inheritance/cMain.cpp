#include<iostream>
using namespace std;
class Human
{
public:
	virtual void A() abstract
	{
		cout << "H" << endl;
	}
};
class Player : public::Human
{
public:
	void A()
	{
		cout << "P" << endl;
	}
};


int main()
{
	Human* a = new Player;
	Player* b = new Player;
	b->A();

	return 0;
}