#include<iostream>
#include<list>
using namespace std;
class Graph
{
	int V;
	list<int> *adj;
	int min(int, int);
	void DFS_util(int u, int vis[], int parent[], int low[], int dfsno[]);
public:
	Graph(int);
	void addEdge(int u, int v);
	void Bridges();
};
Graph::Graph(int V)
{
	this->V = V;
	adj = new list<int>[V];
}
void Graph::addEdge(int u, int v)
{
	adj[u].push_back(v);
	adj[v].push_back(u);
}
int Graph::min(int a, int b)
{
	if (a < b)
		return a;
	return b;
}
void Graph::DFS_util(int u, int vis[], int parent[], int low[], int dfsno[])
{
	static int no = 0;
	vis[u] = 1;
	dfsno[u] = low[u] = ++no;
	list<int>::iterator it;
	for (it = adj[u].begin(); it != adj[u].end(); it++)
	{
		if (vis[*it] == 0)
		{
			parent[*it] = u;
			DFS_util(*it, vis, parent, low, dfsno);
			low[u] = min(low[u], low[*it]);
			if (low[*it] > dfsno[u])
				cout << u << "-" << *it << "\n";
		}
		else if (parent[u] != *it)
		{
			low[u] = min(low[u], dfsno[*it]);
		}
	}
}
void Graph::Bridges()
{
	int *visited = new int[V];
	int *low = new int[V];
	int *dfsno = new int[V];
	int *parent = new int[V];
	for (int i = 0; i < V; i++)
	{
		visited[i] = 0;
		parent[i] = -1;
	}
	for (int i = 0; i < V; i++)
	{
		DFS_util(i, visited, parent, low, dfsno);
	}
}
int main()
{
	cout << "\nBridges in first graph \n";
	Graph g1(5);
	g1.addEdge(1, 0);
	g1.addEdge(0, 2);
	g1.addEdge(2, 1);
	g1.addEdge(0, 3);
	g1.addEdge(3, 4);
	g1.Bridges();

	cout << "\nBridges in second graph \n";
	Graph g2(4);
	g2.addEdge(0, 1);
	g2.addEdge(1, 2);
	g2.addEdge(2, 3);
	g2.Bridges();

	cout << "\nBridges in third graph \n";
	Graph g3(7);
	g3.addEdge(0, 1);
	g3.addEdge(1, 2);
	g3.addEdge(2, 0);
	g3.addEdge(1, 3);
	g3.addEdge(1, 4);
	g3.addEdge(1, 6);
	g3.addEdge(3, 5);
	g3.addEdge(4, 5);
	g3.Bridges();
	return 0;
}