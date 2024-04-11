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

void Stack::Count()
{
    cout << "count : " << count << endl;
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
    if (IsEmpty())
    {
        data = new int;
        data[0] = _data;
        cout << _data << " 입력성공" << endl;
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
        cout << _data << " 입력성공" << endl;
    }
    count++;
   
}

int Stack::Pop()
{
    if (count != 0)
    {
        cout << data[count-1] << "제거" << endl;
        int* nData = new int[count - 1];
        for (int i = 0; i < count-1; i++)
        {
            nData[i] = data[i];
        }
        delete data;
        data = nData;
        count--;
    }
    
    return 0;
}

int Stack::Check()
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
