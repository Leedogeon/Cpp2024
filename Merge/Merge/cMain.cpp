#include <iostream>
using namespace std;
int arr[10] = {};
#define SWAP(a,b) {int temp; temp = a; a = b; b = temp;}

void MergeSort(int* pNum, int left, int right);
void Show(int* pArray, int num);

void main()
{
	int array[10] = { 4,2,8,6,0,5,1,7,3,9 };
	MergeSort(array, 0, 9);
	Show(array, 10);
}

void MergeSort(int* pNum, int left, int right)
{
	if (left >= right) return;

	int half = (left + right) / 2;
	int lt = left;
	int rt = right;
	int md = half + 1;
	int i = left;

	MergeSort(pNum, left, half);
	MergeSort(pNum, half + 1, right);

	while (lt <= half && md <= right)
	{
		if (pNum[lt] < pNum[md])
		{
			arr[i++] = pNum[lt++];
		}
		else
		{
			arr[i++] = pNum[md++];
		}
	}

	if (lt > half)
	{
		for (int k = md; k <= right; k++)
		{
			arr[i++] = pNum[k];
		}
	}
	else
	{
		for (int k = lt; k <= half; k++)
		{
			arr[i++] = pNum[k];
		}
	}

	for (int k = left; k <= right; k++)
	{
		pNum[k] = arr[k];
	}

}

void Show(int* pArray, int num)
{
	for (int i = 0; i < num; i++)
	{
		cout << pArray[i] << " ";
	}

	cout << endl;
}
