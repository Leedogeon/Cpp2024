#include "GameRoom.h"

int main()
{
	GameRoom GR;
	USER user1 = {"a",1,0};
	USER user2 = { "b",1,0 };
	USER user3 = { "c",1,0 };
	USER user4 = { "d",1,0 };
	USER user5 = { "e",1,0 };
	USER user6 = { "f",1,0 };

	GR.AddUser(user1);
	GR.AddUser(user2);
	GR.AddUser(user3);
	GR.AddUser(user4);
	GR.AddUser(user5);
	GR.AddUser(user6);
	

	cout << GR.Count() << endl;



}