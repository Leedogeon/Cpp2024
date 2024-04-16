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
	if (_index > count) return;

	Node* nNode = new Node;
	nNode->data = _data;
	Node* Prev = new Node;
	Prev = head;
	for (int i = 0; i < _index; i++)
	{
		Prev = Prev->next;
	}
	nNode->next = Prev->next;
	Prev->next = nNode;


	if (nNode->next == nullptr)
	{
		curNode = nNode;
	}
	count++;
}

void SingleList::UpdateNode(int _index, int _data)
{
	if (_index > count) return;

	Node* nNode = new Node;
	nNode->data = _data;
	Node* Prev = new Node;
	Prev = head;
	for (int i = 0; i < _index; i++)
	{
		Prev = Prev->next;
	}
	Prev->data = nNode->data;

}

void SingleList::DeleteNodeData(int _data)
{
	Node* nNode = new Node;
	nNode = head;
	for (int i = 0; i < count; i++)
	{
		if (nNode->data = _data)
		{
			if (nNode == head)
			{
				/*if (head->next == nullptr)
				{
					delete nNode;
				}*/
				head = head->next;
			}
			else
			{
				Node* Next = new Node;
				Next = nNode->next;
				if (Next->next == nullptr)
				{
					nNode->next = nullptr;
				}
				else
				{
					
					nNode->next = Next;
				}
				
				break;
			}
			
		}
		else nNode = nNode->next;
	}

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
