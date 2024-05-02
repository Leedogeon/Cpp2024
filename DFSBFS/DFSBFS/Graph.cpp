#include "Graph.h"

void Graph::InitializeGraph(int nodeCount)
{
    graph = new Node* [nodeCount];
	vertexs = new bool[nodeCount];
    for (int i = 0; i < nodeCount; i++)
    {
		graph[i] = CreateNode(i);
		vertexs[i] = false;
    }
}

void Graph::AddEdge(int from, int to)
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
				tNode[i].cnt = graph[to][0].cnt + 1;
			}

			change(to, tNode);
			graph[to][(graph[to][0].cnt) - 1].next = graph[from];
		}
		graph[from]->next = graph[to];
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
			fNode[i].data = graph[from][0].data;
			fNode[i].cnt = graph[from][0].cnt + 1;
		}


		if (graph[to][0].cnt == 0)
		{
			graph[to]->cnt++;

			change(from, fNode);
			graph[from][graph[from][0].cnt - 1].next = graph[to];
			graph[to]->next = graph[from];
			return;

		}
		else
		{
			Node* ttNode = new Node[graph[to][0].cnt + 1];
			for (int i = 0; i < graph[to][0].cnt; i++)
			{
				ttNode[i] = graph[to][i];
				ttNode[i].data = graph[to][0].data;
				ttNode[i].cnt = graph[to][0].cnt + 1;
			}

			change(from, fNode);
			change(to, ttNode);
			graph[from][graph[from][0].cnt - 1].next = graph[to];
			graph[to][graph[to][0].cnt - 1].next = graph[from];
		}

	}
	return;
}

void Graph::DeleteEdge(int node, int deleteEdge)
{
	if (graph[node][0].cnt == 0) return;

	if (graph[node][0].cnt == 1)
	{
		if (graph[node]->next == graph[deleteEdge])
		{
			graph[node]->next = nullptr;
			graph[node]->cnt = 0;

			if (graph[deleteEdge][0].cnt == 1)
			{
				graph[deleteEdge]->next = nullptr;
				graph[node]->cnt = 0;
				return;
			}

			else
			{

				Node* tNode = new Node[graph[deleteEdge][0].cnt - 1];
				int temp = 0;
				for (int i = 0; i < graph[deleteEdge][0].cnt - 1; i++)
				{
					if (graph[deleteEdge][i].next == graph[node]) temp++;

					tNode[i] = graph[deleteEdge][i + temp];
					tNode[i].data = graph[deleteEdge][0].data;
					tNode[i].cnt = graph[deleteEdge][0].cnt - 1;
				}

				change(deleteEdge, tNode);
			}
		}
		return;
	}

	else
	{

		Node* fNode = new Node[graph[node][0].cnt - 1];
		int temp2 = 0;
		for (int i = 0; i < graph[node][0].cnt - 1; i++)
		{
			if (graph[node][i].next == graph[deleteEdge]) temp2++;
			fNode[i] = graph[node][i + temp2];
			fNode[i].data = graph[node][0].data;
			fNode[i].cnt = graph[node][0].cnt - 1;
		}

		if (graph[deleteEdge][0].cnt == 1)
		{
			graph[deleteEdge]->cnt--;
			graph[deleteEdge]->next = nullptr;
			change(node, fNode);
			return;

		}
		else
		{
			Node* ttNode = new Node[graph[deleteEdge][0].cnt - 1];
			int temp3 = 0;
			for (int i = 0; i < graph[deleteEdge][0].cnt - 1; i++)
			{
				if (graph[deleteEdge][i].next == graph[node]) temp3++;
				ttNode[i] = graph[deleteEdge][i + temp3];
				ttNode[i].data = graph[deleteEdge][0].data;
				ttNode[i].cnt = graph[deleteEdge][0].cnt - 1;
			}
			change(node, fNode);
			change(deleteEdge, ttNode);
		}
	}

}

void Graph::ShowGraphEdge(int node)
{
	cout << graph[node]->data << " ";
	for (int i = 0; i < graph[node][0].cnt; i++)
	{
		cout << graph[node][i].next->data << " ";
	}
	cout << endl;
}

bool Graph::visitVertex(int node)
{
	if (vertexs[node] == false) return vertexs[node] = true;
	else return vertexs[node] = false;
}

void Graph::BreadthFirstSerch(int node)//queue
{
	cout << "Breath" << endl;
	Queue que;
	Queue pque;

	pque.Enqueue(node);
	visitVertex(node);

	Breadth(node, que, pque);
	pque.PrintAll();

	for (int i = 0; i < maxCount; i++)
	{
		visitVertex(i);
	}
}

void Graph::DepthFirstSerch(int node)//stack
{
	cout << "depth" << endl;
	Stack stk;
	Stack pstk;
	pstk.Push(node);
	visitVertex(node);

	Depth(node, stk, pstk);
	pstk.PrintAll();


	for (int i = 0; i < maxCount; i++)
	{
		visitVertex(i);
	}
}

Node* Graph::CreateNode(int data)
{
    Node* nNode = new Node;
    nNode->data = data;
    nNode->next = nullptr;
    nNode->cnt = 0;
    return nNode;
}

void Graph::change(int _base, Node* _cng)
{
	for (int i = 0; i < maxCount; i++)
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

void Graph::Depth(int node, Stack& _stk, Stack& _pstk)
{
	for (int i = 0; i < graph[node][0].cnt; i++)
	{
		if (vertexs[graph[node][i].next->data] == true) continue;
		_stk.Push(graph[node][i].next->data);
	}
	
	if (_stk.IsEmpty()) return;
	node = _stk.Pop();

	while(_pstk.Check(node))
	{
		node = _stk.Pop();
		if (_stk.IsEmpty())
		{

			break;
		}
	}
	if (vertexs[node] == false)
	{
		_pstk.Push(node);
		visitVertex(node);
	}


	if (_stk.IsEmpty() && _pstk.Check(node))
	{
		return;
	}

	Depth(node, _stk, _pstk);
}

void Graph::Breadth(int node, Queue& _que, Queue& _pque)
{
	for (int i = 0; i < graph[node][0].cnt; i++)
	{
		if (vertexs[graph[node][i].next->data]) continue;
		_que.Enqueue(graph[node][i].next->data);
	}
	if (_que.IsEmpty()) return;
	node = _que.Dequeue();
		
	while (_pque.Check(node))
	{	
		node = _que.Dequeue();
		if (_que.IsEmpty()) break;
	}

	if (vertexs[node] == false)
	{
		_pque.Enqueue(node);
		visitVertex(node);
	}

	if (_que.IsEmpty() && _pque.Check(node))
	{
		return;
	}
	Breadth(node, _que, _pque);

}


Graph::Graph()
{
    count = 0;
	vertexs = nullptr;
    graph = nullptr;
}

Graph::~Graph()
{

	for (int i = 0; i < maxCount; i++)
	{
		graph[i] = CreateNode(0);
		delete graph[i];
		graph[i] = nullptr;
		vertexs[i] = false;
	}

    delete[] graph;
    count = 0;
	delete[] vertexs;
    vertexs = nullptr;
}
