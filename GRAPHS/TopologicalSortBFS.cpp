/* find the indegree of all verices and push all vertices with 0 indegree to queue,
then pop from queue until not empty and push the poped vertex to output array and 
for every popped vertex find if there are any adjacent vertex with 0 indegree 
after removing this vertex and is found push them into queue*/

#include<iostream>
#include<queue>
#include<list>
#include<vector>
using namespace std;

class Graph
{
	int V;
	list<int> *adj;
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

void Graph::topologicalOrder()
{
	//to store indegree of vertices
	vector<int> indegree(V, 0);
	//to store the topological sort order
	vector<int> sort_order;
	//calculate indegree for all vertices
	for (int i = 0; i < V; i++)
	{
		list<int>::iterator it;
		for (it = adj[i].begin(); it != adj[i].end(); it++)
		{
			indegree[*it]++;
		}
	}
	queue<int> q;
	int no_of_visited_vertices = 0;
	//push all vertices with zero indegree to queue
	for (int i = 0; i < V; i++)
		if (indegree[i] == 0)
			q.push(i);
	while (!q.empty())
	{
		int temp = q.front();
		q.pop();
		sort_order.push_back(temp);
		list<int>::iterator it;
		//check if adjacent vertex has indegree 0 after removing current vertex..if found push it into queue
		for (it = adj[temp].begin(); it != adj[temp].end(); it++)
		{
			if (--indegree[*it] == 0)
				q.push(*it);
		}
		no_of_visited_vertices++;
	}
	//if no of vertices processed is not equal to total no of vertices then there is cycle.
	if (no_of_visited_vertices != V)
	{
		cout << "there is a cycle\n";
	}
	else
	{
		vector<int>::iterator it;
		for (it = sort_order.begin(); it != sort_order.end(); it++)
		{
			cout << *it << " ";
		}
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
