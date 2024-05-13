#include <iostream>
using namespace std;

#define SWAP(a,b) {int temp; temp = a; a = b; b = temp;}

void QuickSort(int* pNum, int left, int right);
void Show(int* pArray, int num);

void main()
{
	int array[10] = { 3,0,1,8,7,2,5,4,9,6 };
	QuickSort(array, 0, 9);

	Show(array,10);
}

void QuickSort(int* pNum, int left, int right)
{
	int cnt = 0;
	bool check = false;
	int low = left;
	int max = right;
	while (left < right)
	{
		if (pNum[left] > pNum[right])
		{
			SWAP(pNum[left], pNum[right]);
			if (check == false) check = true;
			else if (check == true) check = false;

			cnt++;

		}
		if (check == true) left++;
		else right--;
	}
	if (cnt == 0) return;

	if (low >= left) return;
	QuickSort(pNum, low, left);
	if (left+1 >= max) return;
	QuickSort(pNum, left+1 , max);
}

void Show(int* pArray, int num)
{
	for (int i = 0; i < num; i++)
	{
		cout << pArray[i] << " ";
	}

	cout << endl;
}

