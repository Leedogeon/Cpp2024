#include "Deque.h"

void Deque::Clear()
{
    if (IsEmpty())
    {
        delete data;
        data = nullptr;
    }
}

int Deque::Count()
{
    cout << "count = " << count << endl;
    return count;
}

bool Deque::IsEmpty()
{
    if (count == 0) return true;
    else return false;
}

void Deque::Enqueue(int _data)
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

int Deque::Dequeue(int _num)
{
    if (!IsEmpty())
    {
        if (_num == 1)
        {
            cout << data[0] << " 삭제" << endl;
            int* nData = new int[count];
            for (int i = 0; i < count - 1; i++)
            {
                nData[i] = data[i + 1];
            }
            delete data;
            data = nData;
           
        }
        else if (_num == 2)
        {
            cout << data[count - 1] << "제거" << endl;
            int* nData = new int[count - 1];
            for (int i = 0; i < count - 1; i++)
            {
                nData[i] = data[i];
            }
            delete data;
            data = nData;
            
        }
        count--;
    }
   

    return 0;
}

void Deque::Check()
{
    if (!IsEmpty())
    {
        for (int i = 0; i < count; i++)
        {
            cout << "data[" << i << "] : " << data[i] << endl;
        }
    }
}

Deque::Deque()
{
    data = nullptr;
    count = 0;
}

Deque::~Deque()
{
    if (data != nullptr)
    {
        delete data;
        data = nullptr;
    }
    count = 0;
}
