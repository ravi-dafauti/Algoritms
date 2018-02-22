#include<iostream>
#include<vector>
using namespace std;

class Graph
{
	int V;
	vector<pair<int, int>> edges;
	int root(int set[], int u);
	bool find(int set[], int u, int v);
	void union_fun(int set[], int u, int v);
public:
	Graph(int);
	void addEdge(int, int);
	bool isCycle();
};
Graph::Graph(int V)
{
	this->V = V;
}
void Graph::addEdge(int u, int v)
{
	edges.push_back(make_pair(u, v));
}

int Graph::root(int set[], int u)
{
	while (set[u] != u)
	{
		set[u] = set[set[u]];
		u = set[u];
	}
	return u;
}

bool Graph::find(int set[], int u, int v)
{
	int root1 = root(set, u);
	int root2 = root(set, v);
	if (root1 == root2)
		return true;
	return false;
}

void Graph::union_fun(int set[], int u, int v)
{
	if (root(set, u) == root(set, v))
		return;
	set[root(set, u)] = root(set, v);
}

bool Graph::isCycle()
{
	int *set = (int*)malloc(sizeof(int)*V);
	for (int i = 0; i < V; i++)
	{
		set[i] = i;
	}
	for (int i = 0; i < edges.size(); i++)
	{
		if (find(set, edges[i].first, edges[i].second))
		{
			return true;
		}
		union_fun(set, edges[i].first, edges[i].second);
	}
	return false;
}
int main()
{
	Graph g(3);
	g.addEdge(0, 1);
	g.addEdge(1, 2);
	g.addEdge(2, 0);
	if (g.isCycle())
		cout << "cycle exists\n";
	else
		cout << "cycle does not exists\n";
	return 0;
}