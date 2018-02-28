/*A directed graph has an eulerian cycle if following conditions are true
1) All vertices with nonzero degree belong to a single strongly connected component.
2) In degree and out degree of every vertex is same.*/
#include<iostream>
#include<list>
using namespace std;
class Graph
{
	int V;
	list<int> *adj;
	int *indegree;
	Graph transpose();
public:
	Graph(int);
	void addEdge(int, int);
	void DFS_Util(int s, int vis[]);
	bool isStronglyConnected();
	bool isEularian();
};
Graph::Graph(int V)
{
	this->V = V;
	adj = new list<int>[V];
	indegree = new int[V];
	for (int i = 0; i < V; i++)
		indegree[i] = 0;
}
void Graph::addEdge(int u, int v)
{
	adj[u].push_back(v);
	indegree[v]++;
}
Graph Graph::transpose()
{
	Graph revg(V);
	list<int>::iterator it;
	for (int i = 0; i < V; i++)
	{
		for (it = adj[i].begin(); it != adj[i].end(); it++)
			revg.addEdge(*it, i);
	}
	return revg;
}
void Graph::DFS_Util(int s, int visited[])
{
	visited[s] = 1;
	list<int>::iterator it;
	for (it = adj[s].begin(); it != adj[s].end(); it++)
	{
		if (visited[*it] == 0)
		{
			DFS_Util(*it, visited);
		}
	}
}

// method which return true if all vertices with degree non zero are strongly connected as one component
bool Graph::isStronglyConnected()
{
	int *visited = new int[V];
	for (int i = 0; i < V; i++)
		visited[i] = 0;
	int n;
	for (n = 0; n < V; n++)
	{
		if (adj[n].size() != 0)
			break;
	}
	if (n == V)
		return true;
	DFS_Util(n, visited);
	for (int i = 0; i < V; i++)
	{
		if (adj[i].size()>0 && visited[i] == 0) 
			return false;
	}
	for (int i = 0; i < V; i++)
		visited[i] = 0;
	Graph rev(V);
	rev = transpose(); 
	rev.DFS_Util(n, visited);
	for (int i = 0; i < V; i++)
	{
		if (adj[i].size()>0 && visited[i] == 0) 
			return false;
	}
	return true;
}
bool Graph::isEularian()
{
	if (!isStronglyConnected())
		return false;
	for (int i = 0; i < V; i++)
	{
		if (adj[i].size() != indegree[i])
			return false;
	}
	return true;
}
int main()
{
	Graph g(5);
	g.addEdge(1, 0);
	g.addEdge(0, 2);
	g.addEdge(2, 1);
	g.addEdge(0, 3);
	g.addEdge(3, 4);
	g.addEdge(4, 0);

	if (g.isEularian())
		cout << "Given directed graph is eulerian";
	else
		cout << "Given directed graph is NOT eulerian";
	return 0;
}