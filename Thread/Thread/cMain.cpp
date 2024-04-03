#include <iostream>
#include <thread>
#include <atomic> 

using namespace std;

atomic<bool> isConnected;

void Disconnect()
{
	if (isConnected.exchange(false) == false)
	{
		return;
	}
	cout << "DisConnected" << endl;

}

int main()
{
	isConnected.store(true);

	Disconnect();
	Disconnect();


	return 0;
}