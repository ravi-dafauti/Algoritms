#include<iostream>
#include<queue>
#include<list>
#define INF 999999
using namespace std;

class Graph
{
	int V;    // No. of vertices
			  // Pointer to an array containing adjacency list
	list<int> *adj;
public:
	Graph(int V);   // Constructor
	void addEdge(int v, int w); // function to add an edge to graph
	void shortestPath(int);
};

//  Constructor of graph
Graph::Graph(int V)
{
	this->V = V;
	adj = new list<int>[V];
}

//  Utility function to add edge
void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w); // Add w to v's list.
}

void Graph::shortestPath(int s)
{
	int *dis = new int[V];
	int *parent = new int[V];
	for (int i = 0; i < V; i++)
	{
		dis[i] = INF;
		parent[i] = -1;
	}
	dis[s] = 0;
	queue<int> q;
	q.push(s);
	while (!q.empty())
	{
		int temp = q.front();
		q.pop();
		list<int>::iterator it;
		for (it = adj[temp].begin(); it != adj[temp].end(); it++)
		{
			if (dis[*it]==INF)
			{
				dis[*it] = dis[temp] + 1;
				q.push(*it);
				parent[*it] = temp;
			}
		}
	}
	for (int i = 0; i < V; i++)
	{
		cout << i << " : " << dis[i] << " : " << parent[i] << "\n";
	}
}
int main()
{
	Graph g(4);
	g.addEdge(0, 1);
	g.addEdge(1, 2);
	g.addEdge(0, 2);
	g.addEdge(2, 3);
	g.shortestPath(0);
	return 0;
}