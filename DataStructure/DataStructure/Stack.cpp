#include "Stack.h"

void Stack::Clear()
{
    for (int i = 0; i < MaxCount; i++)
    {
        data[i] = 0;
    }
    count = 0;
    cout << "Stack 초기화, count : " << count << endl;
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
        cout << "가득참" << endl;
        return false;
    }

    else
    {
        cout << "비어있음" << endl; return true;
    }
}

bool Stack::Push(int _data)
{
    if (count != MaxCount)
    {
        data[count] = _data;
        count++;
        cout << _data << " 입력 완료" << endl;
        return true;
    }
    else
    {
        cout << _data << " 입력 실패" << endl;
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
        cout << temp << " Pop 성공" << endl;
        return temp;
    }
    else
    {
        cout << "Pop 실패";
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
    cout << "생성자" << endl;
}
