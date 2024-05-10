#include <iostream>
#include <vector>
using namespace std;

#define SWAP(a,b) {int temp; temp = a; a = b; b = temp;}

void MergeSort(int* pNum, int left, int right);
void Show(int* pArray, int num);

void main()
{
	int array[10] = { 4,2,8,6,0,5,1,7,3,9 };
	MergeSort(array, 0, 9);
	
}

void MergeSort(int* pNum, int left, int right)
{
	int half = (right + left) / 2;
	int low = left;
	int high = right;

	cout << "low = " << low << endl;
	cout << "high = " <<high << endl;

	if (low < half)
		MergeSort(pNum, low, half);

	if (half + 1 < high)
		MergeSort(pNum, half + 1, high);

	vector<int> temp;	

	while (low < high)
	{
		if (pNum[low] > pNum[high])
		{
			temp.push_back(pNum[high]);
			high--;
		}
		else
		{
			temp.push_back(pNum[low]);
			low++;
		}
	}
	for (int j = 0; j < temp.size(); j++)
	{
		pNum[left] = temp[j];
	}
	



	/*//if (left == 0 && right == 9)
	//{
	//	int arr2[10] = {};

	//	int i = 0;
	//	int mid = right / 2 + 1;
	//	while (true)
	//	{
	//		if (pNum[left] < pNum[mid])
	//		{
	//			arr2[i] = pNum[left];
	//			left++;
	//		}
	//		else
	//		{
	//			arr2[i] = pNum[mid];
	//			mid++;
	//		}
	//		i++;
	//		if (left > half || mid > right) break;
	//	}

	//	//if (low > half)
	//	//{
	//	//	for (int k = mid; k <= high; k++)
	//	//	{
	//	//		arr2[i] = pNum[k];
	//	//		i++;
	//	//	}
	//	//}
	//	//else
	//	//{
	//	//	for (int k = low; k <= half; k++)
	//	//	{
	//	//		arr2[i] = pNum[k];
	//	//		i++;
	//	//	}
	//	//}
	//	cout << "arr2" << endl;
	//	Show(arr2, 10);

	//}*/



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
