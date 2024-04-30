#include "PriorityQueue.h"

bool PriorityQueue::IsEmpty()
{
    if (count == 0) return true;
    return false;
}

void PriorityQueue::Push(int _priority, int _data)
{
    heap[count].priority = _priority;
    heap[count].data = _data;
    count++;
    if (count == 1) return;
    
    //(자식-1)/2 = 부모
    if (GetParentIndex(heap[count].priority) > heap[count].priority)
    {
        while (GetParentIndex(heap[count].priority) > heap[count].priority)
        {
            Swap(GetParentIndex(heap[count].priority), heap[count].priority);
        }
    }
}

Node PriorityQueue::Pop()
{
    if (IsEmpty()) return;


    Node node = heap[0];
    heap[0].priority = heap[count].priority;
    heap[0].data = heap[count].priority;
    count--;
    int cur = heap[0].priority;
    int next = GetChildIndex(cur);
    heap[count] = {};

    if (GetChildIndex(cur) < cur)
    {
        while (GetChildIndex(cur) < cur)
        {
            Swap(GetChildIndex(cur), cur);
            cur = next;
        }
    }

    return node;
}

int PriorityQueue::Count()
{
    return count;
}

int PriorityQueue::GetChildIndex(int selfIndex)
{
    int res = 0;
    if (selfIndex > GetLeftChildIndex(selfIndex))
    {
        //Swap(selfIndex, GetLeftChildIndex(selfIndex));
        res = GetLeftChildIndex(selfIndex);
    }
    else if (selfIndex > GetRightChildIndex(selfIndex))
    {
        //Swap(selfIndex, GetRightChildIndex(selfIndex));
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
