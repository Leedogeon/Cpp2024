#include "Stack.h"

void Stack::Clear()
{
    if (!IsEmpty())
    {
        delete data;
        data = nullptr;
        count = 0;
    }
}

int Stack::Count()
{
    return count;
}

bool Stack::IsEmpty()
{
    if (count == 0)
    {
        return true;
    }
    else return false;
}

void Stack::Push(int _data)
{

    int* nData = new int[count + 1];

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

int Stack::Pop()
{
    int res = data[count - 1];
    if (count != 0)
    {
        count--;
        int* nData = new int[count];
        for (int i = 0; i < count; i++)
        {
            nData[i] = data[i];
        }
        delete data;
        data = nData;
    }

    return res;
}

bool Stack::Check(int _data)
{
    if (!IsEmpty())
    {
        for (int i = 0; i < count; i++)
        {
            if (data[i] == _data)
                return true;
        }
        return false;
    }
    return false;
}

void Stack::PrintAll()
{
    if (!IsEmpty())
    {
        for (int i = 0; i < count; i++)
        {
            cout << data[i] << " ";
        }
    }
    cout << endl;
}

Stack::Stack()
{
    data = nullptr;
    count = 0;
}

Stack::~Stack()
{
    if (data != nullptr)
    {
        delete data;
        data = nullptr;
    }

    count = 0;
}
