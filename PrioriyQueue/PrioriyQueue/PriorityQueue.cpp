#include "PriorityQueue.h"

bool PriorityQueue::IsEmpty()
{
    if (count == 0) return true;
    return false;
}

void PriorityQueue::Push(int _priority, int _data)
{
    heap[count] = { _priority,_data };
    if (count == 0)
    {
        count++;
        return;
    }

    if (count >= 1)
    {
        for (int i = 0; i < count; i++)
        {
            if (heap[i].priority == _priority)
            {
                heap[count] = {};
                return;
            }
        }
    }
    
    //(자식-1)/2 = 부모
    int cnt = count;
    if (heap[GetParentIndex(cnt)].priority > heap[cnt].priority)
    {
        while (heap[GetParentIndex(cnt)].priority > heap[cnt].priority)
        {
            Swap(GetParentIndex(cnt),cnt);
            cnt = GetParentIndex(cnt);
        }
    }
    count++;

}

Node PriorityQueue::Pop()
{
    Node node = heap[0];
    if (IsEmpty()) return node;

    int cnt = 0;
    int next = cnt;
    count--;

    heap[0] = heap[count];

    heap[count] = {};

    if (heap[GetChildIndex(cnt)].priority < heap[cnt].priority)
    {
        while (heap[GetChildIndex(cnt)].priority < heap[cnt].priority)
        {
            next = GetChildIndex(cnt);
            if (next >= count) break;
            Swap(GetChildIndex(cnt), cnt);
            cnt = next;
        }
    }

    return node;
}

int PriorityQueue::Count()
{
    return count;
}

void PriorityQueue::PrintAll()
{
    for (int i = 0; i < Count(); i++)
    {
        cout << heap[i].data << endl;
    }
}

int PriorityQueue::GetChildIndex(int selfIndex)
{
    int res = 0;
    if (heap[selfIndex].priority > heap[GetLeftChildIndex(selfIndex)].priority)
    {
        if (heap[selfIndex].priority > heap[GetRightChildIndex(selfIndex)].priority)
        {
            res = heap[GetLeftChildIndex(selfIndex)].priority > heap[GetRightChildIndex(selfIndex)].priority ? GetRightChildIndex(selfIndex) : GetLeftChildIndex(selfIndex);
        }
        else res = GetLeftChildIndex(selfIndex);
    }
    else if (heap[selfIndex].priority > heap[GetRightChildIndex(selfIndex)].priority)
    {
        res = GetRightChildIndex(selfIndex);
    }
    
    return res;
}

int PriorityQueue::GetParentIndex(int selfIndex)
{
    selfIndex = (selfIndex - 1) / 2;
    return selfIndex;
}

int PriorityQueue::GetLeftChildIndex(int selfIndex)
{
    selfIndex = (selfIndex * 2) + 1;
    return selfIndex;
}

int PriorityQueue::GetRightChildIndex(int selfIndex)
{
    selfIndex = (selfIndex + 1) * 2;
    return selfIndex;
}

void PriorityQueue::Swap(int firstIndex, int secondIndex)
{
    Node temp = heap[firstIndex];
    heap[firstIndex] = heap[secondIndex];
    heap[secondIndex] = temp;

}

PriorityQueue::PriorityQueue()
{
    for (int i = 0; i < MaxCount; i++)
    {
        heap[i] = {};
    }
    count = 0;
}
