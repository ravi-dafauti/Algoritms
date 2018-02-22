#include<iostream>
#include<list>
using namespace std;

class Graph
{
	int V;
	list<int>* adj;
	bool isCycleUtil(int u, int visited[], int currentRecur[]);
public:
	Graph(int V);
	void addEdge(int v, int w);
	bool isCycle();
};

Graph::Graph(int V)
{
	this->V = V;
	adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w);
}

bool Graph::isCycleUtil(int u, int visited[], int currentRecur[])
{
	visited[u] = 1;
	currentRecur[u] = 1;
	list<int>::iterator it;
	for (it = adj[u].begin(); it != adj[u].end(); it++)
	{
		if (visited[*it] == 0)
		{
			if (isCycleUtil(*it, visited, currentRecur))
				return true;
		}
		else if (currentRecur[*it] == 1)
		{
			return true;
		}
	}
	currentRecur[u]=0;
	return false;
}
bool Graph::isCycle()
{
	int *visited = new int[V];
	int *currentRecursion = new int[V];
	for (int i = 0; i < V; i++)
	{
		visited[i] = 0;
		currentRecursion[i] = 0;
	}
	for (int i = 0; i < V; i++)
	{
		if (visited[i]==0)
		{
			if (isCycleUtil(i, visited, currentRecursion))
				return true;
		}
	}
	return false;
}
int main()
{
	Graph g(4);
	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(1, 2);
	g.addEdge(2, 0);
	g.addEdge(2, 3);

	if (g.isCycle())
		cout << "Graph contains cycle";
	else
		cout << "Graph doesn't contain cycle";

	return 0;
}