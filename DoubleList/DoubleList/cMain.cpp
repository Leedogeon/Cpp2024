#include "DoubleList.h"

int main()
{
	DoubleList DL;

	/*DL.Push_Back(10);
	DL.Push_Back(20);
	DL.Push_Back(30);
	DL.Push_Back(40);
	DL.Push_Back(50);
	DL.Push_Back(60);*/

	DL.Push_Front(10);
	DL.Insert(0, 3, 10);
	cout << "count = " << DL.count << endl;
	DL.PrintAll();
	DL.Clear();
	cout << "count = " << DL.count << endl;
	cout << "ALL" << endl;
	DL.PrintAll();

	return 0;
}