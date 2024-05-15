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
            graph[to]->pio = pio;
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
    queue<int> pque;

    pque.push(node);
    visitVertex(node);

    Breadth(node, pque);

    
    cout << "°æ·Î : ";
    for (int i = 1; i < Max; i++)
    {
        cout << pque.front();
        pque.pop();
        if (pque.size() != 1) cout << "->";
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

void Dijkstra::Breadth(int node, queue<int>& pque)
{
    int check = 0;
    for (int i = 0; i < graph[node][0].cnt; i++)
    {
        if (vertexs[graph[node][i].next->data]) continue;
        check++;

        if (dis[graph[node][i].next->data] == 0)
        {
            dis[graph[node][i].next->data] = dis[node] + graph[node][i].pio;

        }
        else
        {
            if (dis[graph[node][i].next->data] > dis[node] + graph[node][i].pio)
            {
                dis[graph[node][i].next->data] = dis[node] + graph[node][i].pio;
            }
        }
    }
    if (check == 0)
    {
        pque.push(node);
        visitVertex(node);
        return;
    }
    int temp = 99;
    int res = 0;
    for (int i = 1; i < dis.size(); i++)
    {
        if (dis[i] == 0) continue;
        if (vertexs[i] == true) continue;
        if (dis[i] < temp)
        {
            temp = dis[i];
            res = i;
        }
    }
    pque.push(res);

    visitVertex(res);

    Breadth(res, pque);
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
    for (int i = 0; i < Max; i++)
    {
        dis.insert({ i,0 });
    }
}

Dijkstra::~Dijkstra()
{
}

