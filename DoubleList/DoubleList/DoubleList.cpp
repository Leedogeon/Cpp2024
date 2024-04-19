#include "DoubleList.h"

void DoubleList::Push_Back(int _data)
{
	Node* nNode = CreateNode(_data);
	if (Empty())
	{
		tail = nNode;
		head = nNode;
	}
	else
	{
		tail->right = nNode;
		nNode->left = tail;
		tail = nNode;
	}
	count++;
}

void DoubleList::Push_Front(int _data)
{
	Node* nNode = CreateNode(_data);
	nNode->data = _data;
	if (Empty())
	{
		tail = nNode;
		head = nNode;
	}
	else
	{
		head->left = nNode;
		nNode->right = head;
		head = nNode;
	}
	count++;
}

Node* DoubleList::CreateNode(int _data)
{
	Node* nNode = new Node;
	nNode->data = _data;
	return nNode;
}

int DoubleList::Pop_Back()
{
	if (count == 1) Clear();
	else
	{
		Node* cur = tail;
		tail = tail->left;
		tail->right = nullptr;
		delete cur;
		count--;
	}
	return 0;
}

int DoubleList::Pop_Front()
{
	if (count == 1) Clear();
	else
	{
		Node* cur = head;
		head = head->left;
		delete cur;
		head->left = nullptr;
		count--;
	}
	return 0;
}

bool DoubleList::Empty()
{
	if (count == 0) return true;
	else return false;
}

void DoubleList::Clear()
{
	int cnt = count;
	if (count == 1)
	{
		head = nullptr;
		tail = nullptr;
		count = 0;
	}
	else
	{
		Node* cur = tail;
		Node* dNode = nullptr;
		
		for (int i = 1; i < cnt; i++)
		{
			cur = cur->left;
			dNode = cur->right;
			tail = cur;
			delete dNode;
			dNode = nullptr;
			count--;
		}
		if (count == 1)
		{
			Clear();
		}
			
	}


}

void DoubleList::Insert(int _index, int _data)
{
	if (_index > count || _index < 0) return;


	Node* nNode = CreateNode(_data);
	if ((count - _index) <= count / 2)
	{
		Node* cur = tail;
		Node* prev = nullptr;
		for (int i = 0; i < (count - _index); i++)
		{
			cur = cur->left;
			prev = cur->right;
		}
		cur->right = nNode;
		nNode->left = cur;
		if (prev != nullptr)
		{
			prev->left = nNode;
			nNode->right = prev;
		}
		else tail = nNode;
	}
	else
	{
		Node* cur = head;
		Node* prev = nullptr;
		for (int i = 0; i < _index; i++)
		{
			cur = cur->right;
			prev = cur->left;
		}
		cur->left = nNode;
		nNode->right = cur;
		if (prev != nullptr)
		{
			prev->right = nNode;
			nNode->left = prev;
		}
		else head = nNode;
	}

	count++;
}

void DoubleList::Insert(int _index, int _count, int _data)
{
	if (_index > count || _index < 0) return;
	
	if (Empty())
	{
		Node* nNode = CreateNode(_data);
		tail = nNode;
		head = nNode;
		count++;
		_count--;
	}

	if ((count - _index) <= count / 2)
	{
		Node* cur = tail;
		Node* prev = nullptr;

		for (int i = 0; i < (count - _index); i++)
		{
			cur = cur->left;
			prev = cur->right;
		}

		for (int i = 0; i < _count; i++)
		{
			Node* nNode = CreateNode(_data);
			
			cur->right = nNode;
			nNode->left = cur;
			cur = cur->right;
			count++;
		}
		if (prev != nullptr)
		{
			prev->left = cur;
			cur->right = prev;
		}
		else tail = cur;
	}
	else
	{
		Node* cur = head;
		Node* prev = nullptr;

		for (int i = 0; i < _index; i++)
		{
			cur = cur->right;
			prev = cur->left;
		}

		for (int i = 0; i < _count; i++)
		{
			Node* nNode = CreateNode(_data);
			cur->left = nNode;
			nNode->right = cur;
			cur = cur->left;
			count++;
		}
		if (prev != nullptr)
		{
			prev->right = cur;
			cur->left = prev;
		}
		else head = cur;
	}
}

void DoubleList::DeleteNode(int _index)
{
	if (_index >= count || _index < 0) return;

	if ((count - _index) <= count / 2)
	{
		Node* cur = tail;
		Node* prev = nullptr;
		Node* next = nullptr;
		for (int i = 1; i < (count - _index); i++)
		{
			cur = cur->left;
			prev = cur->right;
		}
		next = cur->left;
		if (prev != nullptr)
		{
			next->right = prev;
			prev->left = next;
		}
		if (cur == tail)
		{
			next->right = nullptr;
			tail = next;
		}
		delete cur;
		cur = nullptr;
	}
	else
	{
		Node* cur = head;
		Node* prev = nullptr;
		Node* next = nullptr;
		for (int i = 0; i < _index; i++)
		{
			cur = cur->right;
			prev = cur->left;
		}
		next = cur->right;
		if (prev != nullptr)
		{
			next->left = prev;
			prev->right = next;
		}
		if (cur == head)
		{
			next->left = nullptr;
			head = next;
		}
		delete cur;
		cur = nullptr;
	}

	count--;

}

void DoubleList::PrintAll()
{
	Node* cur = head;
	for (int i = 0; i < count; i++)
	{
		cout << cur->data << endl;
		cur = cur->right;
	}
}



DoubleList::~DoubleList()
{
	Clear();
	delete tail;
	delete head;
}
