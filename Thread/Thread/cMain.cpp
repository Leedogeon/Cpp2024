#include <iostream>
#include <thread>	
#include <atomic>
using namespace std;

struct MyStruct
{
	char a;
	char b;
	char c;
	char d;
};

atomic<MyStruct> myStruct;


int main()
{
	cout << "lock free? : " << myStruct.is_lock_free()<< endl;

	return 0;
}