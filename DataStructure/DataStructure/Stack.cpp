#include "Stack.h"

void Stack::Clear()
{
    for (int i = 0; i < MaxCount; i++)
    {
        data[i] = 0;
    }
    count = 0;
    cout << "Stack �ʱ�ȭ, count : " << count << endl;
}

int Stack::Count()
{
    count = 0;
    for (int i = 0; i < MaxCount; i++)
    {
        if (data[i] != 0) count++;
    }
    cout << "count : " << count << endl;
    return count;
}

bool Stack::IsEmpty()
{
    if (count == MaxCount)
    {
        cout << "������" << endl;
        return false;
    }

    else
    {
        cout << "�������" << endl; return true;
    }
}

bool Stack::Push(int _data)
{
    if (count != MaxCount)
    {
        data[count] = _data;
        count++;
        cout << _data << " �Է� �Ϸ�" << endl;
        return true;
    }
    else
    {
        cout << _data << " �Է� ����" << endl;
        return false;
    }
   
}

int Stack::Pop()
{
    if (count != 0)
    {
        
        int temp = 0;
        temp = data[count-1];
        data[count -1] = 0;
        count--;
        cout << temp << " Pop ����" << endl;
        return temp;
    }
    else
    {
        cout << "Pop ����";
        return 0;
    }
}

int Stack::Check()
{
    for (int i = 0; i < MaxCount; i++)
    {
        cout << "data[" << i <<"] : " << data[i] << endl;
    }
    return 0;
}

Stack::Stack()
{
    cout << "������" << endl;
}
