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
				tNode[i].count++;
			}
			*graph[to] = *tNode;
			
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
			fNode[i].count++;
		}
		*graph[from] = *fNode;
		graph[from][(graph[from][0].count) - 1].next = graph[to];

		if (graph[to][0].count == 0)
		{
			graph[to]->next = graph[from];
			graph[to]->count++;
		}
		else
		{
			Node* ttNode = new Node[graph[to][0].count+1];
			for (int i = 0; i < graph[to][0].count; i++)
			{
				ttNode[i] = graph[to][i];
				ttNode[i].count++;
			}
			*graph[to] = *ttNode;

			cout << graph[to][0].count << endl;
			graph[to][(graph[to][0].count) - 1].next = graph[from];
		}
	}

	return;
}

void Graph::DeleteEdge(int node, int deleteEdge)
{
	if (graph[node][0].count == 0) return;

	int cn = graph[node][0].count;
	int cd = graph[deleteEdge][0].count;
	int count = graph[node][0].count;

	for (int i = 0; i < cn; i++)
	{
		if (graph[node][i].next == graph[deleteEdge])
			cout << "test" << endl;
	}

	//if (count == 1)
	//{
	//	if (graph[node]->next == graph[deleteEdge])
	//	{
	//		Node* cur = new Node;
	//		cur->data = graph[node]->data;
	//		cur->next = nullptr;
	//		cur->count = 0;

	//		graph[node] = cur;

	//		if (graph[deleteEdge][0].count == 1)
	//		{
	//			Node* cur2 = new Node;
	//			cur2->data = graph[deleteEdge]->data;
	//			cur2->next = nullptr;
	//			cur2->count = 0;

	//			graph[deleteEdge] = cur2;
	//		}

	//		else
	//		{
	//			for (int i = 0; i < graph[deleteEdge][0].count; i++)
	//			{

	//				Node* cur2 = new Node[graph[deleteEdge][0].count - 1];
	//				int temp = 0;
	//				for (int j = 0; j < count; j++)
	//				{
	//					if (i == j)
	//					{
	//						temp++;

	//					}
	//					cur2[j].data = graph[deleteEdge][0].data;
	//					cur2[j].count = count - 1;
	//					cur2[j].next = nullptr;
	//					cur2[j].next = graph[deleteEdge][j + temp].next;
	//				}
	//				graph[deleteEdge] = cur2;

	//			}
	//		}

	//	}
	//	return;
	//}


	//for (int i = 0; i < count; i++)
	//{
	//	if (graph[node][i].next == graph[deleteEdge])
	//	{
	//		Node* cur = new Node[count - 1];
	//		int temp = 0;
	//		for (int j = 0; j < count; j++)
	//		{
	//			if (i == j)
	//			{
	//				temp++;

	//			}
	//			cur[j].data = graph[node][0].data;
	//			cur[j].count = count - 1;
	//			cur[j].next = nullptr;
	//			cur[j].next = graph[node][j + temp].next;
	//		}
	//		graph[node] = cur;
	//		break;
	//	}
	//}

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

//Node* Graph::DeleteNode(int _node)
//{
//	int cnt = graph[_node][0].count;
//	cout << "cnt = " << cnt << endl;
//
//	if (cnt == 1)
//	{
//		Node* cur = new Node;
//		cur->data = graph[_node]->data;
//		cur->next = nullptr;
//		cur->count = 0;
//
//		graph[_node] = cur;
//	}
//	else
//	{
//		for (int i = 0; i < cnt; i++)
//		{
//			Node* cur = new Node[cnt - 1];
//			int temp = 0;
//			for (int j = 0; j < cnt; j++)
//			{
//				if (i == j)
//				{
//					temp++;
//
//				}
//				cur[j].data = graph[_node][0].data;
//				cur[j].count = cnt - 1;
//				cur[j].next = nullptr;
//				cur[j].next = graph[cnt][j + temp].next;
//			}
//			graph[_node] = cur;
//			break;
//		}
//	}
//
//
//	return graph[_node];
//}


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
