#include<iostream>
#include<list>
using namespace std;
class Graph
{
	int V;
	list<int> *adj;
	bool isSafe(int index, int u, int path[]);
	bool isHamilUtil(int u, int path[]);
public:
	Graph(int);
	void addEdge(int, int);
	bool isHamiltonianCycle();
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
bool Graph::isHamiltonianCycle()
{
	int *path = new int[V];
	for (int i = 0; i < V; i++)
		path[i] = -1;
	path[0] = 0;
	if (!isHamilUtil(1, path))
	{
		return false;
	}
	return true;
}
bool Graph::isHamilUtil(int index, int path[])
{
	if (index == V)
	{
		list<int>::iterator it = find(adj[path[index - 1]].begin(), adj[path[index - 1]].end(), 0);
		if (it != adj[path[index - 1]].end())
			return true;
	}
	for (int i = 1; i < V; i++)
	{
		if (isSafe(index, i, path))
		{
			path[index] = i;
			if (isHamilUtil(index + 1, path))
				return true;
		}
	}
	return false;
}
bool Graph::isSafe(int index, int u, int path[])
{
	list<int>::iterator it = find(adj[path[index - 1]].begin(), adj[path[index - 1]].end(), u);
	if (it== adj[path[index - 1]].end())
		return false;
	int i;
	for (i = 0; i < index; i++)
		if (path[i] == u)
			return false;
	return true;
}
int main()
{
	Graph g(5);
	g.addEdge(0, 1);
	g.addEdge(0, 3);
	g.addEdge(1, 2);
	g.addEdge(1, 3);
	g.addEdge(1, 4);
	g.addEdge(3, 4);
	g.addEdge(2, 4);
	cout << g.isHamiltonianCycle();
	return 0;
}