/* this algorithm checks if the given graph is bipartite.
 we use a 2 coloring algo. If the graph is two colorable then the graph is bipartite
 we use backtracking algorithm for finding if the graph is two colorable
 complexity is 2^V*/
#include<iostream>
#include<list>
using namespace std;
class Graph
{
	int V;
	list<int> *adj;
	bool isBipartiteUtil(int color[], int index);
	bool isSafeColor(int color[], int v, int c);
public:
	Graph(int);
	void addEdge(int, int);
	bool isBipartite();
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
bool Graph::isBipartite()
{
	int *color = new int[V];
	for (int i = 0; i < V; i++)
		color[i] = -1;
	color[0] = 0; // color vertex 0 with 0
	if (isBipartiteUtil(color, 1)) // check if rest vertices can be colored using 0 or 1
		return true;
	return false;
}
bool Graph::isBipartiteUtil(int color[], int index)
{
	if (index == V)   // colored all vertices with 0 and 1
		return true;
	for (int i = 0; i < 2; i++)
	{
		if (isSafeColor(color, index, i))   // check if we can assign color i to this vertex
		{
			color[index] = i;
			if (isBipartiteUtil(color, index + 1))  // if yes then recur for next vertex
				return true;
			color[index] = -1;
		}
		// if not then check for next color ie. 1
	}
	return false;
}
bool Graph::isSafeColor(int color[], int v, int c)
{
	list<int>::iterator it;
	for (it = adj[v].begin(); it != adj[v].end(); it++) // check if any adjacent vertex of v is colored with c. if found return false
	{
		if (color[*it] == c)
			return false;
	}
	return true;
}
int main()
{
	Graph g(4);
	g.addEdge(0, 2);
	g.addEdge(0, 3);
	g.addEdge(1, 2);
	g.addEdge(1, 3);
	if (g.isBipartite())
	{
		cout << "is bipartite\n";
	}
	else
	{
		cout << "is not bipartite\n";
	}
	return 0;
}