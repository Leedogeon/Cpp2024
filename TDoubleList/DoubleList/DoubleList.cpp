#include "DoubleList.h"

template<typename T>
inline void DoubleList<T>::Push_Back(T _data)
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

template<typename T>
inline void DoubleList<T>::Push_Front(T _data)
{
}

template<typename T>
inline Node* DoubleList<T>::CreateNode(T _data)
{
	Node* nNode = new Node;
	nNode->data = _data;
	return nNode;
}

template<typename T>
inline int DoubleList<T>::Pop_Back()
{
	return 0;
}

template<typename T>
inline int DoubleList<T>::Pop_Front()
{
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
}

template<typename T>
inline void DoubleList<T>::Insert(int _index, T _data)
{
}

template<typename T>
inline void DoubleList<T>::Insert(int _index, int _count, T _data)
{
}

template<typename T>
inline void DoubleList<T>::DeleteNode(int _index)
{
}

template<typename T>
inline void DoubleList<T>::PrintAll()
{
	Node* cur = head;
	for (int i = 0; i < count; i++)
	{
		cout << cur->data << endl;
		cur = cur->right;
	}
}

template<typename T>
inline DoubleList<T>::~DoubleList()
{
}
