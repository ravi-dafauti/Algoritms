/*Eulerian Cycle
An undirected graph has Eulerian cycle if following two conditions are true.
….a) All vertices with non-zero degree are connected. We don’t care about vertices with zero degree because they don’t belong to Eulerian Cycle or Path (we only consider all edges).
….b) All vertices have even degree.

Eulerian Path
An undirected graph has Eulerian Path if following two conditions are true.
….a) Same as condition (a) for Eulerian Cycle
….b) If zero or two vertices have odd degree and all other vertices have even degree. Note that only one vertex with odd degree is not possible in an undirected graph (sum of all degrees is always even in an undirected graph)*/
#include<iostream>
#include<list>
using namespace std;
class Graph
{
	int V;
	list<int> *adj;
	bool isConnected();
	void DFS_Util(int s, int vis[]);
public:
	Graph(int);
	void addEdge(int, int);
	int isEularian();
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
void Graph::DFS_Util(int s, int vis[])
{
	vis[s] = 1;
	list<int>::iterator it;
	for (it = adj[s].begin(); it != adj[s].end(); it++)
	{
		if (vis[*it] == 0)
			DFS_Util(*it, vis);
	}
}
bool Graph::isConnected()
{
	int *vis = new int[V];
	for (int i = 0; i < V; i++)
	{
		vis[i] = 0;
	}
	int i;
	for (i = 0; i < V; i++)
	{
		if (adj[i].size() > 0)
			break;
	}
	if (i == V)
		return true;
	DFS_Util(i, vis);
	for (int i = 0; i < V; i++)
	{
		if (adj[i].size() > 0 && vis[i] == 0)
			return false;
	}
	return true;
}
int Graph::isEularian()
{
	if (!isConnected())
		return 0;
	int odd = 0;
	for (int i = 0; i < V; i++)
	{
		if (adj[i].size() % 2 != 0)
			odd++;
	}
	if (odd > 2)
		return 0;
	if (odd == 0)
		return 2;
	return 1;
}

void test(Graph &g)
{
	int res = g.isEularian();
	if (res == 0)
		cout << "graph is not Eulerian\n";
	else if (res == 1)
		cout << "graph has a Euler path\n";
	else
		cout << "graph has a Euler cycle\n";
}
int main()
{

	// Let us create and test graphs shown in above figures
	Graph g1(5);
	g1.addEdge(1, 0);
	g1.addEdge(0, 2);
	g1.addEdge(2, 1);
	g1.addEdge(0, 3);
	g1.addEdge(3, 4);
	test(g1);

	Graph g2(5);
	g2.addEdge(1, 0);
	g2.addEdge(0, 2);
	g2.addEdge(2, 1);
	g2.addEdge(0, 3);
	g2.addEdge(3, 4);
	g2.addEdge(4, 0);
	test(g2);

	Graph g3(5);
	g3.addEdge(1, 0);
	g3.addEdge(0, 2);
	g3.addEdge(2, 1);
	g3.addEdge(0, 3);
	g3.addEdge(3, 4);
	g3.addEdge(1, 3);
	test(g3);

	// Let us create a graph with 3 vertices
	// connected in the form of cycle
	Graph g4(3);
	g4.addEdge(0, 1);
	g4.addEdge(1, 2);
	g4.addEdge(2, 0);
	test(g4);

	// Let us create a graph with all veritces
	// with zero degree
	Graph g5(3);
	test(g5);

	return 0;
}