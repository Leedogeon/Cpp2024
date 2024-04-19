#pragma once
#include<iostream>
using namespace std;
#define MaxCount 5
template <typename T>
class Stack
{
private:
	T *data;
	int count;
public:
	bool IsEmpty();
	void Push(T _data); //값넣기
	int Check();
public:
	Stack(); //생성자
	~Stack();
};


template <typename T>
bool Stack<T>::IsEmpty()
{
    if (count == 0)
    {
        return true;
    }
    else return false;
}


template <typename T>
void Stack<T>::Push(T _data)
{

    T* nData = new T[count + 1];

    for (int i = 0; i < count; i++)
    {

        nData[i] = data[i];
    }
    nData[count] = _data;
    if (!IsEmpty())
    {
        delete data;
    }
    data = nData;

    count++;

}
template <typename T>
int Stack<T>::Check()
{
    if (!IsEmpty())
    {
        for (int i = 0; i < count; i++)
        {
            cout << "data[" << i << "] = " << data[i] << endl;
        }
    }

    return 0;

}
template <typename T>
Stack<T>::Stack()
{
    data = nullptr;
    count = 0;
}
template <typename T>
Stack<T>::~Stack()
{
    if (data != nullptr)
    {
        delete data;
        data = nullptr;
    }

    count = 0;
}
