/* this algorithm checks if the given graph is bipartite.
We use BFS 
1. color vertex 0 with RED and push it in Queue;
2.while Queue is not empty pop and element
  2.1 check for all adjacent vertices of poped element
      2.1.1 if not colored then color it with BLUE is present vertex is RED otherwise color it with RED
	  2.1.2 if colored, check if it is colored with same color as present vertex and is true return false;
3. return true if all verices are examined and colored.
*/
#include<iostream>
#include<list>
#include<queue>
using namespace std;
class Graph
{
	int V;
	list<int> *adj;
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
	queue<int> q;
	color[0] = 0; // color vertex 0 with 0
	q.push(0);  //push vertex to queue
	while (!q.empty())
	{
		int current_vertex = q.front();
		q.pop();   // pop front from queue
		list<int>::iterator it;
		for (it = adj[current_vertex].begin(); it != adj[current_vertex].end(); it++)   // check for all adjacent vertices of current vertex
		{
			if (color[*it] == -1)          // if adjacent vertex is not colored then color it with opposite color and push to queue
			{
				color[*it] = 1 - color[current_vertex];
				q.push(*it);
			}
			else
			{
				if (color[*it] == color[current_vertex])  // if adjacent vertex is of same color as current vertex return false
					return false;
			}
		}
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