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
    cout << "count = " << count << endl;
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
        cout << _data << " 입력" << endl;
    }
    count++;
}

int Queue::Dequeue()
{
    if (!IsEmpty())
    {
        cout << data[0] << " 삭제" << endl;
        int* nData = new int[count];
        for (int i = 0; i < count - 1; i++)
        {
            nData[i] = data[i + 1];
        }
        delete data;
        data = nData;
        count--;
    }

    return 0;
}

void Queue::Check()
{
    if (!IsEmpty())
    {
        for (int i = 0; i < count; i++)
        {
            cout << "data[" << i << "] : " << data[i] << endl;
        }
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
