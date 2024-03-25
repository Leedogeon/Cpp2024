#include <iostream>

using namespace std;

class Pet
{
public:
	int num;
};

class Obj
{
public:
	Pet* pet; // int float 
public:
	Obj() = default;
	Obj(const Obj& other)
	{
		pet = new Pet;
		//pet = other.pet;
		pet->num = other.pet->num;
	}
};

int main()
{
	Obj a;
	a.pet = new Pet;

	Obj c(a);
	Obj d = a;

	delete a.pet;

	d.pet->num = 12;
	//d.pet 
	//a.pet 
	return 0;
}

