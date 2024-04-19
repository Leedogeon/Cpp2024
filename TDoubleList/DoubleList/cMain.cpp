#include "DoubleList.h"
template <typename T>
int main()
{
	DoubleList DL;

	DL.Push_Back(10);
	DL.Push_Back(20);
	DL.Push_Back(30);
	DL.Push_Back(40);
	DL.Push_Back(50);
	DL.Push_Back(60);

	DL.PrintAll();

	return 0;
}