#include "MST.h"

void MST::Init(int nodeCount)
{
    graph = new Node * [nodeCount];
    vertexs = new bool[nodeCount];
    for (int i = 0; i < nodeCount; i++)
    {
        graph[i] = createNode(i);
        vertexs[i] = false;
    }
}

void MST::AddEdge(int from, int to, int pio)
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
void MST::ShowGraphEdge(int node)
{
    cout << graph[node]->data << " ";
    for (int i = 0; i < graph[node][0].cnt; i++)
    {
        cout << graph[node][i].next->data << " ";
    }
    cout << endl;

}

bool MST::visitVertex(int node)
{
    if (vertexs[node] == false) return vertexs[node] = true;
    else return vertexs[node] == false;
}

void MST::BreadthFirstSerch()
{
    queue<int> pque;
    
    for (int i = 1; i < Max; i++)
    {
        
        for (int j = 0; j < graph[i][0].cnt; j++)
        {
            int check = 0;
            for (auto num : FT)
            {
                if (num.from == i && num.to == graph[i][j].next->data)
                {
                    check++;
                    break;
                }
                if (num.from == graph[i][j].next->data && num.to == i)
                {
                    check++;
                    break;
                }
            }
            if(check == 0)
            FT.push_back({ i, graph[i][j].next->data, graph[i][j].pio });
        }
    }


    for (auto num : FT)
    {
        cout << "from = " << num.from  << ", to = " << num.to  << " , pio = " << num.pio << endl;
    }




}

Node* MST::createNode(int data)
{
    Node* node = new Node;
    node->data = data;
    node->next = nullptr;
    node->cnt = 0;
    node->pio = 0;

    return node;
}

void MST::Breadth(int node, queue<int>& pque)
{
    int check = 0;
    for (int i = 0; i < graph[node][0].cnt; i++)
    {
        if (vertexs[graph[node][i].next->data]) continue;
        check++;
        vs[graph[node][i].next->data] = node;


        if (dis[graph[node][i].next->data] == 0)
        {
            dis[graph[node][i].next->data] = graph[node][i].pio;
        }
        else
        {
            if (dis[graph[node][i].next->data] > graph[node][i].pio)
            {
                dis[graph[node][i].next->data] = graph[node][i].pio;
            }
        }
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
    visitVertex(res);
    pque.push(res);
    if (check == 0)
    {
        return;
    }
    Breadth(res, pque);


    int tm = 99;
    for (int i = 1; i < Max; i++)
    {
        if (vertexs[i] == false && vs[i] == res)
        {

            if (dis[i] != 0 && tm > dis[i])
            {
                tm = dis[i];
            }
        }
    }
    if (tm != 99)
    {
        visitVertex(tm);
        pque.push(tm);
        Breadth(tm, pque);
    }

}

void MST::change(int _base, Node* _cng)
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



MST::MST()
{
    count = 0;
    vertexs = nullptr;
    graph = nullptr;
    
    for (int i = 0; i < Max; i++)
    {
        dis.insert({ i,0 });
        vs.insert({ i,0 });
        
    }
}

MST::~MST()
{
}

