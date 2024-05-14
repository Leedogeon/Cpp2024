#include "Dijkstra.h"

void Dijkstra::Init(int nodeCount)
{
    graph = new Node * [nodeCount];
    vertexs = new bool[nodeCount];
    for (int i = 0; i < nodeCount; i++)
    {
        graph[i] = createNode(i);
        vertexs[i] = false;
    }
}

void Dijkstra::AddEdge(int from, int to, int pio)
{
    if (graph[from][0].cnt == 0)
    {
        graph[from]->cnt++;

        if (graph[to][0].cnt == 0)
        {
            graph[to]->next = graph[from];
            graph[to]->cnt++;
        }
        else
        {
            Node* tNode = new Node[graph[to][0].cnt + 1];
            for (int i = 0; i < graph[to][0].cnt; i++)
            {
                tNode[i] = graph[to][i];
                tNode[i].data = graph[to][0].data;
                tNode[i].pio = graph[to][i].pio;
                tNode[i].cnt = graph[to][0].cnt + 1;
            }

            change(to, tNode);
            graph[to][(graph[to][0].cnt) - 1].next = graph[from];
            graph[to][(graph[to][0].cnt) - 1].pio = pio;
        }
        graph[from]->next = graph[to];
        graph[from]->pio = pio;
    }
    else
    {
        for (int i = 0; i < graph[from][0].cnt; i++)
        {
            if (graph[from][i].next == graph[to]) return;
        }


        for (int i = 0; i < graph[from][0].cnt; i++)
        {
            if (graph[from][i].next == graph[to])
                return;
        }

        Node* fNode = new Node[graph[from][0].cnt + 1];
        for (int i = 0; i < graph[from][0].cnt; i++)
        {
            fNode[i] = graph[from][i];
            fNode[i].pio = graph[from][i].pio;
            fNode[i].data = graph[from][0].data;
            fNode[i].cnt = graph[from][0].cnt + 1;
        }


        if (graph[to][0].cnt == 0)
        {
            graph[to]->cnt++;

            change(from, fNode);
            graph[from][graph[from][0].cnt - 1].next = graph[to];
            graph[from][graph[from][0].cnt - 1].pio = pio;
            graph[to]->next = graph[from];
            graph[to]->pio = pio;
            return;

        }
        else
        {
            Node* ttNode = new Node[graph[to][0].cnt + 1];
            for (int i = 0; i < graph[to][0].cnt; i++)
            {
                ttNode[i] = graph[to][i];
                ttNode[i].pio = graph[to][i].pio;
                ttNode[i].data = graph[to][0].data;
                ttNode[i].cnt = graph[to][0].cnt + 1;
            }

            change(from, fNode);
            change(to, ttNode);
            graph[from][graph[from][0].cnt - 1].next = graph[to];
            graph[from][graph[from][0].cnt - 1].pio = pio;

            graph[to][graph[to][0].cnt - 1].next = graph[from];
            graph[to][graph[to][0].cnt - 1].pio = pio;
        }

    }
    return;
}
void Dijkstra::ShowGraphEdge(int node)
{
    cout << graph[node]->data << " ";
    for (int i = 0; i < graph[node][0].cnt; i++)
    {
        cout << graph[node][i].next->data << " ";
    }
    cout << endl;
}



bool Dijkstra::visitVertex(int node)
{
    if (vertexs[node] == false) return vertexs[node] = true;
    else return vertexs[node] == false;
}

void Dijkstra::BreadthFirstSerch(int node)
{
    queue<int> que;
    queue<int> pque;

    pque.push(node);
    visitVertex(node);

    Breadth(node, que, pque);

    for (int i = 0; i < pque.size(); i++)
    {
        cout << pque.front() << " ";
        pque.front()++;
    }

    for (int i = 0; i < Max; i++)
    {
        visitVertex(i);
    }
}

Node* Dijkstra::createNode(int data)
{
    Node* node = new Node;
    node->data = data;
    node->next = nullptr;
    node->cnt = 0;
    node->pio = 0;

    return node;
}

void Dijkstra::Breadth(int node, queue<int>& que, queue<int>& pque)
{
    for (int i = 0; i < graph[node][0].cnt; i++)
    {
        if (vertexs[graph[node][i].next->data]) continue;
        que.push(graph[node][i].next->data);
    }
    if (que.empty()) return;
    
    int temp = 99;
    int qf1 = que.front();
    for (int i = 0; i < que.size(); i++)
    {
        for (int i = 0; i < graph[node][0].cnt; i++)
        {
            if (graph[node][i].next->data == qf1)
            {
                if (temp > graph[node][i].pio)
                {
                    temp = graph[node][i].pio;
                    node = que.front();
                }
            }
        }
    }
    
    
    node = que.front();
    que.pop();
    
    int qf = pque.front();
    bool check = false;
    while (true)
    {
        qf = pque.front();
        
        for (int i = 0; i < pque.size(); i++)
        {
            if (qf == node)
            {
                check = true;
                break;
            }
            else qf++;
        }
        if (check == true)
        {
            que.pop();
            if (que.empty()) break;
            node = que.front();
            check = false;
        }
        else break;
    }
    

    if (vertexs[node] == false)
    {
        pque.push(node);
        visitVertex(node);
    }

    if (que.empty())
    {
        qf = pque.front();
        for (int i = 0; i < pque.size(); i++)
        {
            if (qf == node) return;
        }
    }
    Breadth(node, que, pque);

}

void Dijkstra::change(int _base, Node* _cng)
{
    for (int i = 0; i < Max; i++)
    {
        if (graph[i][0].cnt != 0)
        {
            for (int j = 0; j < graph[i][0].cnt; j++)
            {
                if (graph[i][j].next == graph[_base])
                {
                    graph[i][j].next = _cng;
                    break;
                }
            }
        }
    }
    graph[_base] = _cng;
}

Dijkstra::Dijkstra()
{
    count = 0;
    vertexs = nullptr;
    graph = nullptr;
}

Dijkstra::~Dijkstra()
{
}
