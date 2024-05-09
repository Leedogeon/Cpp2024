#include <iostream>
using namespace std;

#define SWAP(a,b) {int temp; temp = a; a = b; b = temp;}

void QuickSort(int* pNum, int left, int right);
void Show(int* pArray, int num);

void main()
{
	int array[10] = { 3,0,1,8,7,2,5,4,9,6 };
	QuickSort(array, 0, 9);
}

void QuickSort(int* pNum, int left, int right)
{
	bool check = false;
	while (left <= right)
	{
		if (pNum[left] > pNum[right])
		{
			SWAP(pNum[left], pNum[right]);
			if (check == false) check = true;
			else if (check == true) check = false;

		}
		
		if (check == true) left++;
		else right--;
	}

	cout << "left = " << left << endl;
	cout << "right = " << right << endl;

	if(left >= 1)
	{
		QuickSort(pNum, 0, left - 1);
		cout << left << endl;
	}
	
	//if ()
	//{
	//	QuickSort(pNum, right + 2, 9);
	//	return;
	//}



	Show(pNum, 10);
	//±¸Çö
}

void Show(int* pArray, int num)
{
	for (int i = 0; i < num; i++)
	{
		cout << pArray[i] << " ";
	}

	cout << endl;
}

