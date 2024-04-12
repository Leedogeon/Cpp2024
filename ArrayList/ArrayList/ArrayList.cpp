#include "ArrayList.h"

void ArrayList::AddNode(int _data)
{
	int* nData = new int[count+1];
	for (int i = 0; i < count; i++)
	{
		nData[i] = data[i];
	}
	nData[count] = _data;
	if(!IsEmpty())
	{
		delete data;
	}
	data = nData;
	count++;
}

void ArrayList::InsertNode(int _index, int _data)
{
	if (_index > count) return;

	int chk = 0;
	int* nData = new int[count + 1];
	for (int i = 0; i < count + 1; i++)
	{
		if (_index == i)
		{
			nData[i] = _data;
			chk++;
			continue;
		}
		else nData[i] = data[i-chk];
	}
	if (!IsEmpty())
	{
		delete data;
	}
	data = nData;
	count++;
}

void ArrayList::InsertNode(int _index, int _count, int _data)
{
	if (_index > count) return;

	int chk = 0;
	int cnt = count;
	int* nData = new int[(count + _count)];

	for (int i = 0; i < cnt+1; i++)
	{
		if (_index == i)
		{
			for (int j = 0; j < _count; j++)
			{
				nData[i+chk] = _data;
				chk++;
			}
		}
		else
		{
			if (data != nullptr)
			{
				if (chk == 0)  nData[i] = data[i];
				else nData[i + chk - 1] = data[i - 1];
			}
			
		}
	}
	if (!IsEmpty())
	{
		delete data;
	}
	data = nData;
	count += _count;
}

void ArrayList::UpdateNode(int _index, int _data)
{
	data[_index] = _data;
}

void ArrayList::DeleteNodeData(int _data)
{
	int Dchk = 0;
	for (int i = 0; i < count; i++)
	{
		if (_data == data[i])
		{
			Dchk++;
		}
	}
	if (Dchk != 0)
	{
		int chk = 0;
		int* nData = new int[count - Dchk];
		for (int i = 0; i < count; i++)
		{
			if (_data == data[i])
			{
				chk++;
				continue;
			}
			nData[i - chk] = data[i];
		}
		delete data;
		data = nData;
		count -= Dchk;
	}
	else return;	
}

void ArrayList::DeleteIndex(int _index)
{
	if ((count - 1) < _index) return;
	
		int chk = 0;
		count--;
		int* nData = new int[count];
		for (int i = 0; i < count+1; i++)
		{
			if (_index == i)
			{
				
				chk++;
				continue;
			}
			nData[i-chk] = data[i];
		} 
		delete data;
		data = nData;
	

}

void ArrayList::ClearAllNode()
{
	delete data;
	data = nullptr;
	count = 0;
}

int ArrayList::GetNodeData(int _index)
{
	int res = data[_index];
	return res;
}

int ArrayList::GetListSize()
{
	return count;
}

bool ArrayList::IsEmpty()
{
	if (count == 0) return true;
	else return false;
}

void ArrayList::PrintAll()
{
	for (int i = 0; i < count; i++)
	{
		cout << "data[" << i << "] : " << data[i] << endl;
	}
}

ArrayList::ArrayList()
{
	data = nullptr;
	count = 0;
}

ArrayList::~ArrayList()
{
	if (data != nullptr)
	{
		delete data;
		data = nullptr;
	}
	count = 0;
}
