#include "DoubleList.h"
int main()
{
	DoubleList<int> DL;
	DoubleList<char> cDL;
	DL.Push_Back(10);
	DL.Push_Back(20);
	DL.Push_Back(30);
	DL.Push_Back(40);
	DL.Push_Back(50);
	DL.Push_Back(60);

	DL.Insert(1, 2, 56);

	DL.PrintAll();


	cDL.Push_Back('a');
	cDL.Push_Back('b');
	cDL.Push_Back('c');
	cDL.Push_Back('d');
	cDL.Push_Back('e');
	cDL.PrintAll();

	return 0;
}