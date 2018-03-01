/* color a graph using approximation as coloring with chromatic no is NP problem
we make sure that max no of colors used are d+1,where d is maximum degree in graph
we color a vertex with minimum color no unused by its adjacent*/
#include<iostream>
#include<list>
using namespace std;
class Graph
{
	int V;
	list<int> *adj;
	void colorGraphUtil(int color[], int u);
public:
	Graph(int);
	void addEdge(int, int);
	void colorGraph();
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
void Graph::colorGraphUtil(int color[], int u)
{
	int *assigned = new int[V];
	for (int i = 0; i < V; i++)
		assigned[i] = 0;
	list<int>::iterator it;
	for (it = adj[u].begin(); it != adj[u].end(); it++)
	{
		if (color[*it] != -1)
			assigned[color[*it]] = 1;
	}
	for (int i = 0; i < V; i++)
		if (assigned[i] == 0)
		{
			color[u] = i;
			break;
		}
}
//greedy algorithm to color graph
void Graph::colorGraph()
{
	int *color = new int[V];
	for (int i = 0; i < V; i++)
		color[i] = -1;
	for (int i = 0; i < V; i++)
	{
		colorGraphUtil(color, i);
	}
	for (int i = 0; i < V; i++)
	{
		cout << color[i] << " ";
	}
	cout << "\n";
}
int main()
{
	Graph g1(5);
	g1.addEdge(0, 1);
	g1.addEdge(0, 2);
	g1.addEdge(1, 2);
	g1.addEdge(1, 3);
	g1.addEdge(2, 3);
	g1.addEdge(3, 4);
	cout << "Coloring of graph 1 \n";
	g1.colorGraph();

	Graph g2(5);
	g2.addEdge(0, 1);
	g2.addEdge(0, 2);
	g2.addEdge(1, 2);
	g2.addEdge(1, 4);
	g2.addEdge(2, 4);
	g2.addEdge(4, 3);
	cout << "\nColoring of graph 2 \n";
	g2.colorGraph();
	return 0;
}