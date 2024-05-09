#include <iostream>
using namespace std;

#define SWAP(a,b) {int temp; temp = a; a = b; b = temp;}

void InsertSort(int* pNum, int num);
void Show(int* pArray, int num);

void main()
{
	int array[10] = { 3,0,1,8,7,2,5,4,9,6 };
	InsertSort(array, 10);
}

void InsertSort(int* pArray, int num)
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = i+1; j < 10; j++)
		{
			if (pArray[i] > pArray[j])
			{
				SWAP(pArray[i], pArray[j]);
			}
		}
	}
	Show(pArray, num);
	//����
}

void Show(int* pArray, int num)
{
	for (int i = 0; i < num; i++)
	{
		cout << pArray[i] << " ";
	}

	cout << endl;
}

