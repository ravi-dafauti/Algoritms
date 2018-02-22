#include<iostream>
#include<stack>
#include<list>
#include<vector>
using namespace std;

class Graph
{
	int V;
	list<pair<int,int>> *adj; // graph as adjency list with weight
	void TopologicalSortUtil(int v, vector<bool> &visited, stack<int> &s); // method for topological sorting
public:
	Graph(int); //constructor
	void addEdge(int, int, int); //method to add edge u,v and distance from u to v
	void longestPath(int);// method to find and print longest path from source to all vertices
};

Graph::Graph(int v)
{
	V = v;
	adj = new list<pair<int,int>>[V];
}

void Graph::addEdge(int u, int v, int dis)
{
	adj[u].push_back(make_pair(v, dis));
}

void Graph::TopologicalSortUtil(int v, vector<bool> &visited, stack<int> &s)
{
	visited[v] = true;
	list<pair<int,int>>::iterator it;
	for (it = adj[v].begin(); it != adj[v].end(); it++)
	{
		if (visited[(*it).first] == false)
			TopologicalSortUtil((*it).first, visited, s);
	}
	//push element in stack after all its adjacent vertices are processed.
	s.push(v);
}
void Graph::longestPath(int source)
{
	stack<int> s;
	//build an array for storing longest path lenght from source and initilaize them with -infinity
	int *longestPathArr = new int[V];
	for (int i = 0; i < V; i++)
		longestPathArr[i] = INT_MIN;
	longestPathArr[source] = 0; // initialize source lenght as 0

	vector<bool> visited(V, false);
	for (int i = 0; i < V; i++)
	{
		if (visited[i] == false)
			TopologicalSortUtil(i, visited, s);
	}
	while (!s.empty())
	{
		int i = s.top();
		s.pop(); // pop in topological order.
		if (longestPathArr[i] != INT_MIN)
		{
			list<pair<int,int>>::iterator it;
			for (it = adj[i].begin(); it != adj[i].end(); it++)
			{
				// if lenght from current vertex + lenght of path to ajacent vertex is more than the present path lenght of adjacent vertex then update it.
				if (longestPathArr[i] + (*it).second > longestPathArr[(*it).first])
				{
					longestPathArr[(*it).first] = longestPathArr[i] + (*it).second;
				}
			}
		}
	}

	//print longest path lenghts
	for (int i = 0; i < V; i++)
	{
		if (longestPathArr[i] == INT_MIN)
		{
			cout << "INF" << " ";
		}
		else
			cout << longestPathArr[i] << " ";
	}
}
int main()
{
	Graph g(6);
	g.addEdge(0, 1, 5);
	g.addEdge(0, 2, 3);
	g.addEdge(1, 3, 6);
	g.addEdge(1, 2, 2);
	g.addEdge(2, 4, 4);
	g.addEdge(2, 5, 2);
	g.addEdge(2, 3, 7);
	g.addEdge(3, 5, 1);
	g.addEdge(3, 4, -1);
	g.addEdge(4, 5, -2);

	int s = 1;
	cout << "Following are longest distances from "
		"source vertex " << s << " \n";
	g.longestPath(s);
	return 0;
}