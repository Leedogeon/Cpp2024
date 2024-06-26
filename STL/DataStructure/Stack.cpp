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
        cout << _data << " 입력성공" << endl;
   
    count++;
   
}

int Stack::Pop()
{
    if (count != 0)
    {
        count--;
        cout << data[count] << " 제거" << endl;
        int* nData = new int[count];
        for (int i = 0; i < count; i++)
        {
            nData[i] = data[i];
        }
        delete data;
        data = nData;
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
