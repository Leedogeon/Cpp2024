#include <iostream>
using namespace std;

#define SWAP(a,b) {int temp; temp = a; a = b; b = temp;}

void ShellSort(int* pNum, int num);
void Show(int* pArray, int num);

void main()
{
	int array[10] = { 3,0,1,8,7,2,5,4,9,6 };
	ShellSort(array, 10);
}

void ShellSort(int* pNum, int num)
{
	int half = num/2;
	for (int i = 0;i<9;i++)
	{

		for (int j = 0;j<num-half; j++)
		{
			if (pNum[j] > pNum[j+half])
			{
				SWAP(pNum[j],pNum[j+half]);

				for (int i = j; j > 0;)
				{
					if (pNum[j] < pNum[j - half])
						SWAP(pNum[j], pNum[j - half]);

					j = j - half;
				}
			}
		}
		half /= 2;
	}

	Show(pNum, num);
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

