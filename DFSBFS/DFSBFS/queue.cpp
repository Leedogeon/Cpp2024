#include "queue.h"

void Queue::Clear()
{
    if (IsEmpty())
    {
        delete data;
        data = nullptr;
    }
}

int Queue::Count()
{
    return count;
}

bool Queue::IsEmpty()
{
    if (count == 0) return true;
    else return false;
}

void Queue::Enqueue(int _data)
{
    if (IsEmpty())
    {
        data = new int;
        data[0] = _data;
    }
    else
    {
        int* nData = new int[count + 1];
        for (int i = 0; i < count; i++)
        {
            nData[i] = data[i];
        }
        nData[count] = _data;
        delete data;
        data = nData;
    }
    count++;
}

int Queue::Dequeue()
{
    int res = data[0];
    if (!IsEmpty())
    {
        int* nData = new int[count];
        for (int i = 0; i < count - 1; i++)
        {
            nData[i] = data[i + 1];
        }
        delete data;
        data = nData;
        count--;
    }
    return res;
}

bool Queue::Check(int _data)
{
    if (!IsEmpty())
    {
        for (int i = 0; i < count; i++)
        {
            if (data[i] == _data) return true;
        }
        return false;
    }
    return false;
}

void Queue::PrintAll()
{
    if (!IsEmpty())
    {
        for (int i = 0; i < count; i++)
        {
            cout << data[i] << " ";
        }
        cout << endl;
    }
}

Queue::Queue()
{
    data = nullptr;
    count = 0;
}

Queue::~Queue()
{
    if (data != nullptr)
    {
        delete data;
        data = nullptr;
    }
    count = 0;
}
