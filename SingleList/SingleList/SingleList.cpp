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
}

void SingleList::InsertNode(int _index, int _data)
{
}

void SingleList::UpdateNode(int _index, int _data)
{
}

void SingleList::DeleteNodeData(int _data)
{
}

void SingleList::DeleteIndex(int _index)
{
}

void SingleList::ClearAllNode()
{
}

int SingleList::GetNodeData(int _index)
{
	return 0;
}

int SingleList::GetListSize()
{
	return 0;
}

bool SingleList::IsEmpty()
{
	return false;
}

void SingleList::PrintAll()
{
}

SingleList::SingleList()
{
	head = nullptr;
	curNode = nullptr;
	count = 0;
}

SingleList::~SingleList()
{
	if (head != nullptr)
	{
		delete head;
		delete curNode;
	}
	count = 0;
}
