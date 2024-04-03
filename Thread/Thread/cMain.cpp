#include <iostream>
#include <thread>	
#include <atomic>
using namespace std;

atomic<int> num;


int main()
{
	num.store(0);
	int value = num.load();

	cout << value << endl;
	return 0;
}