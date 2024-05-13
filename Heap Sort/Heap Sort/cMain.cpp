#include <iostream>
using namespace std;
#include <vector>
#define SWAP(a,b) {int temp; temp = a; a = b; b = temp;}
#define Max 7

vector<int>result;
void HeapSort(int *arr,int len, int cnt);
int FindParent(int len);
int main()
{
	int arr[Max] = { 2,7,3,4,5,6,1 };
	int cnt = Max - 1;

	HeapSort(arr, 0 , cnt);

	for (auto num : result)
	{
		cout << result.back() << endl;
		result.pop_back();
	}
	
}

void HeapSort(int *arr, int len, int cnt)
{
	bool cL = false;
	bool cR = false;

	if((len+1)*2 <= Max-1) HeapSort(arr, (len+1)*2 , cnt);
	if((len*2+1) <= Max-2) HeapSort(arr, (len * 2 + 1) , cnt);


	if (len % 2 == 1)
	{
		if (arr[len] > arr[FindParent(len)])
		{
			SWAP(arr[len], arr[FindParent(len)]);
			cR = true;
		}
	}
	else
	{
		int res = arr[len] > arr[len - 1] ? len : (len - 1);

		if (arr[res] > arr[FindParent(len)])
		{
			SWAP(arr[res], arr[FindParent(res)]);
			if (res % 2 == 0) cR = true;
			else cL = true;
		}
	}

	if (cR == true)
	{
		HeapSort(arr, len, cnt);
	}
	else if (cL ==true)
	{
		HeapSort(arr, len - 1, cnt);
	}

	if (len == 0 && cnt>=1)
	{
		result.push_back(arr[0]);
		arr[0] = arr[cnt];
		arr[cnt--] = 0;
		HeapSort(arr, 0, cnt);
	}
	else if (len == 0 && cnt == 0)
	{
		result.push_back(arr[0]);
		return;
	}
}
int FindParent(int len)
{
	return (len - 1) / 2;
}
