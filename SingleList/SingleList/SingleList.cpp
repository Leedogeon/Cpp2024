#include "SingleList.h"
void SingleList::AddNode(int _data)
{
	Node* nNode = new Node;
	nNode->data = _data;
	nNode->next = nullptr;
	if (head == nullptr)
	{
		head = nNode;
		curNode = head;
	}
	else
	{
		curNode->next = nNode;
		curNode = curNode->next;
	}
	count++;
}

void SingleList::InsertNode(int _index, int _data)
{
	if (_index < 0 || _index > count || count == 0) return;

	Node* nNode = new Node;
	nNode->data = _data;
	nNode->next = nullptr;

	if (_index == 0)
	{
		nNode->next = head;
		head = nNode;
		if (curNode == nullptr) curNode = head;
	}
	else
	{
		Node* prev = head;
		for (int i = 1; i < _index; i++)
		{
			prev = prev->next;
		}

		nNode->next = prev->next;
		prev->next = nNode;

		if (nNode->next == nullptr) curNode = nNode;
	}
	count++;
}

void SingleList::UpdateNode(int _index, int _data)
{
	if (_index < 0 || _index >= count) return;

	Node* cur = head;
	for (int i = 0; i < _index; i++)
	{
		cur = cur->next;
	}
	cur->data = _data;

}

void SingleList::DeleteNodeData(int _data)
{
	Node* cur = head;
	Node* prev = nullptr;

	while (cur != nullptr)
	{
		if (cur->data == _data)
		{
			if (prev == nullptr)
			{
				head = cur->next;
				if (head == nullptr) curNode = nullptr;
			}
			else
			{
				prev->next = cur->next;
				if (prev->next == nullptr) curNode = prev;
			}

			delete cur;
			count--;
			return;
		}

		prev = cur;
		cur = cur->next;
	}
}

void SingleList::DeleteIndex(int _index)
{
	if (_index < 0 || _index > count) return;

	Node* cur = head;
	Node* prev = nullptr;

	if (_index == 0)
	{
		head = cur->next;
		if (head == nullptr) curNode = nullptr;
		count--;
		return;
	}
	else
	{
		for (int i = 0; i < _index; i++)
		{
			prev = cur;
			cur = cur->next;
		}
		prev->next = cur->next;
		if (prev->next == nullptr) curNode = prev;
		delete cur;
		count--;
	}
	
}

void SingleList::ClearAllNode()
{
	Node* cur = head;
	Node* next = nullptr;
	while (cur != nullptr)
	{
		next = cur->next;
		delete cur;
		cur = next;
	}
	head = nullptr;
	curNode = nullptr;
	count = 0;
}

int SingleList::GetNodeData(int _index)
{
	if (_index < 0 || _index >= count)
	{
		cout << "범위 밖입니다." << endl;
		return 0;
	}

	Node* find = new Node;
	find = head;
	for (int i = 0; i < _index; i++)
	{
		find = find->next;
	}
	int res = find->data;
	return res;
}

int SingleList::GetListSize()
{
	return count;
}

bool SingleList::IsEmpty()
{
	if (count == 0 || head == nullptr)
	{
		return true;
	}
	return false;
}

void SingleList::PrintAll()
{
	Node* nNode = new Node;
	nNode = head;
	for (int i = 0; i < count; i++)
	{
		cout << nNode->data << endl;
		nNode = nNode->next;
	}
}

SingleList::SingleList()
{
	head = nullptr;
	curNode = nullptr;
	count = 0;
}

SingleList::~SingleList()
{
	Node* cur = head;
	Node* next = nullptr;
	while (cur != nullptr)
	{
		next = cur->next;
		delete cur;
		cur = next;
	}
	head = nullptr;
	curNode = nullptr;
	count = 0;
}