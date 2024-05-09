#include <iostream>
using namespace std;

#define SWAP(a,b) {int temp; temp = a; a = b; b = temp;}

void BubbleSort(int* pNum, int num);
void Show(int* pArray, int num);

void main()
{
	int array[10] = { 3,0,1,8,7,2,5,4,6,9 };
	BubbleSort(array, 10);

	
}

void BubbleSort(int* pArray, int num)
{
	int max = 9;
	for (int i = 0; i<max+1; i++)
	{
		for (int j = 0; j < max; j++)
		{
			if (pArray[j] > pArray[j+1])
			{
				SWAP(pArray[j], pArray[j+1]);
				
			}
			if (j == max-1)
			{
				cout << "test" << endl;
				max -= 2;
			}
		}
	}
	Show(pArray, num);
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

