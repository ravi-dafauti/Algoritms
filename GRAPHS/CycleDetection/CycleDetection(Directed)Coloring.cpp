#include<iostream>
#include<list>
using namespace std;

enum Color { WHITE, GRAY, BLACK };
/*WHITE : color represents node is not visited
GREY : color represents a visited node and all its adjacent nodes not completed DFS
BLACK : color represents a visited node and all its adjacent nodes completed DFS
*/

class Graph
{
	int V;
	list<int>* adj;
	bool isCycleUtil(int u, int color[]);
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

bool Graph::isCycleUtil(int u, int color[])
{
	color[u] = GRAY;
	list<int>::iterator it;
	for (it = adj[u].begin(); it != adj[u].end(); it++)
	{
		if (color[*it] == WHITE)
		{
			if (isCycleUtil(*it, color))
				return true;
		}
		else if (color[*it] == GRAY)
		{
			return true;
		}
	}
	color[u] = BLACK;
	return false;
}
bool Graph::isCycle()
{
	int *color = new int[V];
	for (int i = 0; i < V; i++)
		color[i] = WHITE;
	for (int i = 0; i < V; i++)
	{
		if (color[i] == WHITE)
		{
			if (isCycleUtil(i, color))
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