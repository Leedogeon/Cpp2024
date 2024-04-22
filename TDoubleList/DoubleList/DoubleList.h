#include "DoubleList.hpp"

template<typename T>
inline void DoubleList<T>::Push_Back(T _data)
{
	Node<T>* nNode = CreateNode(_data);
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

template<typename T>
inline void DoubleList<T>::Push_Front(T _data)
{
	Node<T>* nNode = CreateNode(_data);
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

template<typename T>
inline Node<T>* DoubleList<T>::CreateNode(const T& _data)
{
	Node<T>* nNode = new Node<T>();
	nNode->data = _data;
	return nNode;
}

template<typename T>
inline int DoubleList<T>::Pop_Back()
{
	if (count == 1) Clear();
	else
	{
		Node<T>* cur = tail;
		tail = tail->left;
		tail->right = nullptr;
		delete cur;
		count--;
	}
	return 0;
}

template<typename T>
inline int DoubleList<T>::Pop_Front()
{
	if (count == 1) Clear();
	else
	{
		Node<T>* cur = head;
		head = head->left;
		delete cur;
		head->left = nullptr;
		count--;
	}
	return 0;
}

template<typename T>
inline bool DoubleList<T>::Empty()
{
	if (count == 0) return true;
	else return false;
}

template<typename T>
inline void DoubleList<T>::Clear()
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
		Node<T>* cur = tail;
		Node<T>* dNode = nullptr;

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

template<typename T>
inline void DoubleList<T>::Insert(int _index, T _data)
{
	if (_index > count || _index < 0) return;


	Node<T>* nNode = CreateNode(_data);
	if ((count - _index) <= count / 2)
	{
		Node<T>* cur = tail;
		Node<T>* prev = nullptr;
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
		Node<T>* cur = head;
		Node<T>* prev = nullptr;
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

template<typename T>
inline void DoubleList<T>::Insert(int _index, int _count, T _data)
{
	if (_index > count || _index < 0) return;

	if (Empty())
	{
		Node<T>* nNode = CreateNode(_data);
		tail = nNode;
		head = nNode;
		count++;
		_count--;
	}

	if ((count - _index) <= count / 2)
	{
		Node<T>* cur = tail;
		Node<T>* prev = nullptr;

		for (int i = 0; i < (count - _index); i++)
		{
			cur = cur->left;
			prev = cur->right;
		}

		for (int i = 0; i < _count; i++)
		{
			Node<T>* nNode = CreateNode(_data);

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
		Node<T>* cur = head;
		Node<T>* prev = nullptr;

		for (int i = 0; i < _index; i++)
		{
			cur = cur->right;
			prev = cur->left;
		}

		for (int i = 0; i < _count; i++)
		{
			Node<T>* nNode = CreateNode(_data);
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

template<typename T>
inline void DoubleList<T>::DeleteNode(int _index)
{
	if (_index >= count || _index < 0) return;

	if ((count - _index) <= count / 2)
	{
		Node<T>* cur = tail;
		Node<T>* prev = nullptr;
		Node<T>* next = nullptr;
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
		Node<T>* cur = head;
		Node<T>* prev = nullptr;
		Node<T>* next = nullptr;
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

template<typename T>
inline void DoubleList<T>::PrintAll()
{
	Node<T>* cur = head;
	for (int i = 0; i < count; i++)
	{
		cout << cur->data << endl;
		cur = cur->right;
	}
}

template<typename T>
inline DoubleList<T>::~DoubleList()
{
	Clear();
	delete tail;
	delete head;
}
