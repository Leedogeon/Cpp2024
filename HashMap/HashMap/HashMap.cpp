#include "HashMap.h"

void HashMap::Add(int _key, int value)
{
	if (Count() == TABLE_SIZE) return;

	Node* nNode = new Node;
	nNode->key = _key;
	nNode->data = value;
	while (table[_key % TABLE_SIZE] != nullptr)
	{
		_key += 1;
	}
	table[_key % TABLE_SIZE] = nNode;

}

int HashMap::GetValue(int _key)
{

	if (table[_key % TABLE_SIZE] != nullptr)
	{
		return table[_key % TABLE_SIZE]->data;
	}
	return 0;
}

void HashMap::Remove(int _key)
{
	if (table[_key % TABLE_SIZE] != nullptr)
	{
		delete table[_key % TABLE_SIZE];
		table[_key % TABLE_SIZE] = nullptr;
	}

}

int HashMap::Count()
{
	int count = 0;
	for (int i = 0; i < TABLE_SIZE; i++)
	{
		if (table[i] != nullptr) count++;
	}
	return count;
}

void HashMap::Clear()
{
	for (int i = 0; i < TABLE_SIZE; ++i)
	{
		delete table[i];
		table[i] = nullptr;
	}
}

void HashMap::View()
{
	for (int i = 0; i < TABLE_SIZE; i++)
	{
		if (table[i] != nullptr)
		{
			cout << "i = " << i << endl;
			cout << table[i]->data << endl;
		}

	}
}

HashMap::HashMap()
{
	table = new Node * [TABLE_SIZE];
	for (int i = 0; i < TABLE_SIZE; i++)
	{
		table[i] = nullptr;
	}
}

HashMap::~HashMap()
{
	Clear();
	delete[] table;
}
