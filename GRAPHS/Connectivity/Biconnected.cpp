#include<iostream>
#include<list>
using namespace std;
class Graph
{
	int V;
	list<int> *adj;
	int min(int, int);
	bool DFS_util(int u, int vis[], int parent[], int low[], int dfsno[]);
public:
	Graph(int);
	void addEdge(int u, int v);
	bool isBiconnected();
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
bool Graph::DFS_util(int u, int vis[], int parent[], int low[], int dfsno[])
{
	static int no = 0;
	vis[u] = 1;
	dfsno[u] = low[u] = ++no;
	int child = 0;
	list<int>::iterator it;
	for (it = adj[u].begin(); it != adj[u].end(); it++)
	{
		if (vis[*it] == 0)
		{
			child++;
			parent[*it] = u;
			if (DFS_util(*it, vis, parent, low, dfsno))
				return true;
			low[u] = min(low[u], low[*it]);
			if (parent[u] == -1 && child > 1)
				return true;
			else if (parent[u] != -1 && low[*it] >= dfsno[u])
				return true;
		}
		else if (parent[u] != *it)
		{
			low[u] = min(low[u], dfsno[*it]);
		}
	}
	return false;
}
bool Graph::isBiconnected()
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

	if (DFS_util(0, visited, parent, low, dfsno))
		return false;

	for (int i = 0; i < V; i++)
	{
		if (visited[i] == false)
			return false;
	}
	return true;
}
int main()
{
	Graph g1(2);
	g1.addEdge(0, 1);
	g1.isBiconnected() ? cout << "Yes\n" : cout << "No\n";

	Graph g2(5);
	g2.addEdge(1, 0);
	g2.addEdge(0, 2);
	g2.addEdge(2, 1);
	g2.addEdge(0, 3);
	g2.addEdge(3, 4);
	g2.addEdge(2, 4);
	g2.isBiconnected() ? cout << "Yes\n" : cout << "No\n";

	Graph g3(3);
	g3.addEdge(0, 1);
	g3.addEdge(1, 2);
	g3.isBiconnected() ? cout << "Yes\n" : cout << "No\n";

	Graph g4(5);
	g4.addEdge(1, 0);
	g4.addEdge(0, 2);
	g4.addEdge(2, 1);
	g4.addEdge(0, 3);
	g4.addEdge(3, 4);
	g4.isBiconnected() ? cout << "Yes\n" : cout << "No\n";

	Graph g5(3);
	g5.addEdge(0, 1);
	g5.addEdge(1, 2);
	g5.addEdge(2, 0);
	g5.isBiconnected() ? cout << "Yes\n" : cout << "No\n";
	return 0;
}