/*topological sorting using dfs
make usual dfs with modification as instead of printing the vertex push it into a stack after traversal on all its adjacent vertices
and print the stack.. */
#include<iostream>
#include<stack>
#include<list>
#include<vector>
using namespace std;

class Graph
{
	int V;
	list<int> *adj;
	void DFSUtil(int v, vector<bool> &visited, stack<int> &s);
public:
	Graph(int);
	void addEdge(int, int);
	void topologicalOrder();
};

Graph::Graph(int v)
{
	V = v;
	adj = new list<int>[V];
}

void Graph::addEdge(int u, int v)
{
	adj[u].push_back(v);
}

void Graph::DFSUtil(int v, vector<bool> &visited, stack<int> &s)
{
	visited[v] = true;
	list<int>::iterator it;
	for (it = adj[v].begin(); it != adj[v].end(); it++)
	{
		if (visited[*it] == false)
			DFSUtil(*it, visited, s);
	}
	//push element in stack after all its adjacent vertices are processed.
	s.push(v);
}
void Graph::topologicalOrder()
{
	stack<int> s;
	vector<bool> visited(V, false);
	for (int i = 0; i < V; i++)
	{
		if (visited[i] == false)
			DFSUtil(i, visited, s);
	}
	while (!s.empty())
	{
		cout << s.top() << " ";
		s.pop();
	}
}
int main()
{
	Graph g(6);
	g.addEdge(5, 2);
	g.addEdge(5, 0);
	g.addEdge(4, 0);
	g.addEdge(4, 1);
	g.addEdge(2, 3);
	g.addEdge(3, 1);

	cout << "Topological Sort of the given graph n\n";
	
	g.topologicalOrder();
	return 0;
}