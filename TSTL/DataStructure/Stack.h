#include "stack.hpp"

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
