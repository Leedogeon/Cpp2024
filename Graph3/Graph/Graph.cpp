#include "Graph.h"

void Graph::InitializeGraph(int nodeCount)
{
	graph = new Node * [nodeCount];
	for (int i = 0; i < nodeCount; i++)
	{
		graph[i] = CreateNode(i + 1);
	}
}

void Graph::AddEdge(int from, int to)
{
	if (graph[from][0].count == 0)
	{
		graph[from]->count++;

		if (graph[to][0].count == 0)
		{
			graph[to]->next = graph[from];
			graph[to]->count++;
		}
		else
		{
			Node* tNode = new Node[graph[to][0].count+1];
			for (int i = 0; i < graph[to][0].count; i++)
			{
				tNode[i] = graph[to][i];
				tNode[i].data = graph[to][0].data;
				tNode[i].count = graph[to][0].count + 1;
			}

			change(to, tNode);
			graph[to][(graph[to][0].count)-1].next = graph[from];
		}
		graph[from]->next = graph[to];
	}
	else
	{


		for (int i = 0; i < graph[from][0].count; i++)
		{
			if (graph[from][i].next == graph[to])
				return;
		}

		Node* fNode = new Node[graph[from][0].count+1];
		for (int i = 0; i < graph[from][0].count; i++)
		{
			fNode[i] = graph[from][i];
			fNode[i].data = graph[from][0].data;
			fNode[i].count = graph[from][0].count + 1;
		}
		

		if (graph[to][0].count == 0)
		{
			graph[to]->count++;

			change(from, fNode);
			graph[from][graph[from][0].count-1].next = graph[to];
			graph[to]->next = graph[from];
			return;

		}
		else
		{
			Node* ttNode = new Node[graph[to][0].count+1];
			for (int i = 0; i < graph[to][0].count; i++)
			{
				ttNode[i] = graph[to][i];
				ttNode[i].data = graph[to][0].data;
				ttNode[i].count = graph[to][0].count + 1;
			}

			change(from, fNode);
			change(to, ttNode);
			graph[from][graph[from][0].count - 1].next = graph[to];
			graph[to][graph[to][0].count - 1].next = graph[from];
		}

	}

	return;
}

void Graph::DeleteEdge(int node, int deleteEdge)
{
	if (graph[node][0].count == 0) return;

	if (graph[node][0].count == 1)
	{
		if (graph[node]->next == graph[deleteEdge])
		{
			graph[node]->next = nullptr;
			graph[node]->count = 0;

			if (graph[deleteEdge][0].count == 1)
			{
				graph[deleteEdge]->next = nullptr;
				graph[node]->count = 0;
				return;
			}

			else
			{
				
					Node* tNode = new Node[graph[deleteEdge][0].count - 1];
					int temp = 0;
					for (int i = 0; i < graph[deleteEdge][0].count-1; i++)
					{
						if (graph[deleteEdge][i].next == graph[node]) temp++;
						
						tNode[i] = graph[deleteEdge][i+temp];
						tNode[i].data = graph[deleteEdge][0].data;
						tNode[i].count = graph[deleteEdge][0].count-1;
					}

					change(deleteEdge, tNode);
			}
		}
		return;
	}

	else
	{

		Node* fNode = new Node[graph[node][0].count - 1];
		int temp2 = 0;
		for (int i = 0; i < graph[node][0].count-1; i++)
		{
			if (graph[node][i].next == graph[deleteEdge]) temp2++;
			fNode[i] = graph[node][i+temp2];
			fNode[i].data = graph[node][0].data;
			fNode[i].count = graph[node][0].count-1;
		}

		if (graph[deleteEdge][0].count == 1)
		{
			graph[deleteEdge]->count--;
			graph[deleteEdge]->next = nullptr;
			change(node, fNode);
			return;

		}
		else
		{
			Node* ttNode = new Node[graph[deleteEdge][0].count-1];
			int temp3 = 0;
			for (int i = 0; i < graph[deleteEdge][0].count-1; i++)
			{
				if (graph[deleteEdge][i].next == graph[node]) temp3++;
				ttNode[i] = graph[deleteEdge][i + temp3 ];
				ttNode[i].data = graph[deleteEdge][0].data;
				ttNode[i].count = graph[deleteEdge][0].count -1;
			}
			change(node, fNode);
			change(deleteEdge, ttNode);
		}
	}
}


void Graph::ShowGraphEdge(int node)
{
	int cnt = graph[node][0].count;
	cout << graph[node]->data << " ";
	for (int i = 0; i < cnt; i++)
	{
		if (graph[node][i].next == nullptr) break;
		cout << graph[node][i].next->data << " ";
	}
	cout << endl;
}

Node* Graph::CreateNode(int _data)
{
	Node* nNode = new Node;
	nNode->data = _data;
	nNode->next = nullptr;
	nNode->count = 0;

	return nNode;
}

void Graph::change(int _base, Node* _cng)
{
	for (int i = 0; i < 9; i++)
	{
		if (graph[i][0].count != 0)
		{
			for (int j = 0; j < graph[i][0].count; j++)
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

Graph::Graph()
{
	graph = nullptr;

}

Graph::~Graph()
{
	for (int i = 0; i < 9; i++)
	{
		graph[i] = CreateNode(0);
		delete graph[i];
		graph[i] = nullptr;
	}
	delete[] graph;
}
