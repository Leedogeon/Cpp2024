#include "GameRoom.h"

int main()
{
	GameRoom GR;
	USER user = {"a",1,2};
	GR.AddUser(user);

	cout << GR.Count() << endl;
}