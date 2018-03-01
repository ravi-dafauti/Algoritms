#include<iostream>
#include<list>
using namespace std;
class Graph
{
	int V;
	list<int> *adj;
	bool mcolorableUtil(int color[], int m, int v);
	bool isSafeColor(int color[], int v, int c);
public:
	Graph(int);
	void addEdge(int, int);
	bool mColorable(int);
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
bool Graph::mColorable(int m)
{
	int *color = new int[V];
	for (int i = 0; i < V; i++)
		color[i] = 0;
	if (mcolorableUtil(color, m, 0))
		return true;
	return false;
}
bool Graph::mcolorableUtil(int color[], int m, int v)
{
	if (v == V)
		return true;
	for (int i = 1; i <= m; i++)
	{
		if (isSafeColor(color, v, i))
		{
			color[v] = i;
			if (mcolorableUtil(color, m, v + 1))
				return true;
			color[v] = 0;
		}
	}
	return false;
}
bool Graph::isSafeColor(int color[], int v, int c)
{
	list<int>::iterator it;
	for (it = adj[v].begin(); it != adj[v].end(); it++)
	{
		if (color[*it] == c)
			return false;
	}
	return true;
}
int main()
{
	Graph g(4);
	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(0, 3);
	g.addEdge(2, 1);
	g.addEdge(3, 2);
	int m = 2;
	if (g.mColorable(m))
	{
		cout << "is " << m << " colorable";
	}
	else
	{
		cout << "is not " << m << " colorable";
	}
	return 0;
}