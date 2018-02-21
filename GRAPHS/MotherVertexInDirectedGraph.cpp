#include<iostream>
#include<vector>
#include<list>
#include<algorithm>
using namespace std;


//graph represented as adjacency list 
class Graph
{
	int V;
	list<int> *adj;
	void DFS(int, vector<bool> &visited);
public:
	Graph(int);
	void addEdge(int, int);
	int motherVertex();
};

Graph::Graph(int V)
{
	this->V = V;
	adj = new list<int>[V];
}

void Graph::addEdge(int u, int v)
{
	adj[u].push_back(v);
}

void Graph::DFS(int u, vector<bool> &visited)
{
	visited[u] = true;
	list<int>::iterator it;
	for (it = adj[u].begin(); it != adj[u].end(); it++)
	{
		if (visited[*it] == false)
			DFS(*it, visited);
	}

}
int Graph::motherVertex()
{
	vector<bool> visited(V, false); //construct vector of size V and initialize visited with false
	int v = 0;
	/* we do dfs and examine the last finished vertex..
	   because the mother vertex is the last finished vertex*/
	for (int i = 0; i < V; i++)
	{
		if (visited[i] == false)
		{
			DFS(i, visited);
			v = i;
		}
	}
	
	// initialise visited with false.
	fill(visited.begin(), visited.end(), false);
	
	// dfs on last finished vertex on DFS
	DFS(v, visited);
	vector<bool>::iterator it;
	bool ismother = true;
	
        //check if the last finished vertex in DFS is the mother vertex
	for (it = visited.begin(); it != visited.end(); it++)
	{
		if (*it == false)
			ismother = false;
	}
	if (ismother)
		return v;
	return -1;
}

int main()
{
	Graph g(7);
	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(1, 3);
	g.addEdge(4, 1);
	g.addEdge(6, 4);
	g.addEdge(5, 6);
	g.addEdge(5, 2);
	g.addEdge(6, 0);

	cout << "A mother vertex is " << g.motherVertex();

	return 0;
}
