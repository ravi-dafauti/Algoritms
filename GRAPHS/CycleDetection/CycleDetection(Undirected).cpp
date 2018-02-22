#include<iostream>
#include <list>
using namespace std;

class Graph
{
	int V;
	list<int> *adj; 
	bool isCyclicUtil(int v, bool visited[], int parent);
public:
	Graph(int V);
	void addEdge(int v, int w);
	bool isCyclic();
};

Graph::Graph(int V)
{
	this->V = V;
	adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w);
	adj[w].push_back(v); 
}

bool Graph::isCyclicUtil(int v, bool visited[], int parent)
{
	visited[v] = true;
	list<int>::iterator it;
	for (it = adj[v].begin(); it != adj[v].end(); it++)
	{
		if (!visited[*it])
		{
			if (isCyclicUtil(*it, visited, v))
				return true;
		}
		else if (*it != parent)
			return true;
	}
	return false;
}

bool Graph::isCyclic()
{
	bool *visited = (bool*)malloc(sizeof(bool)*V);
	for (int i = 0; i < V; i++)
		visited[i] = false;
	for (int i = 0; i < V; i++)
	{
		if (visited[i] == false)
		{
			if (isCyclicUtil(i, visited, -1))
				return true;
		}
	}
	return false;
}

int main()
{
	Graph g1(5);
	g1.addEdge(1, 0);
	g1.addEdge(0, 2);
	g1.addEdge(1, 3);
	g1.addEdge(0, 3);
	g1.addEdge(3, 4);
	g1.isCyclic() ? cout << "Graph contains cycle\n" :
		cout << "Graph doesn't contain cycle\n";

	Graph g2(3);
	g2.addEdge(0, 1);
	g2.addEdge(1, 2);
	g2.isCyclic() ? cout << "Graph contains cycle\n" :
		cout << "Graph doesn't contain cycle\n";


	return 0;
}