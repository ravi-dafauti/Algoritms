/* program to check if a Directed Graph is strongly connected
1.strongly connected graph is a graph in which there is a path b/w every pair of vertices
2.for undirected graph check if graph is connected and dfs/bfs from a node visits all nodes
3.for directed
   3.1 first make a dfs from one node.
   3.2 if some nodes are not visited return false;
   3.3 else ,now we need to check if we can reach this node from other node, as if we are able to reach this node from all other nodes
       and we were able to reach all other nodes from this node then this implies that we can reach all nodes from each node.
   3.4 to check if we can reach this node from other node, just reverse the graph and check if we can reach all other nodes from this node in reverse
       graph.
   3.5 if some nodes not visited return false else return true.*/

#include<iostream>
#include<list>
using namespace std;
class Graph
{
	int V;
	list<int> *adj;
	Graph transpose();
public:
	Graph(int);
	void addEdge(int, int);
	void DFS_Util(int s, int vis[]);
	bool isStronglyConnected();
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
Graph Graph::transpose()
{
	Graph revg(V);
	list<int>::iterator it;
	for (int i = 0; i < V; i++)
	{
		for (it = adj[i].begin(); it != adj[i].end(); it++)
			revg.addEdge(*it, i);
	}
	return revg;
}
void Graph::DFS_Util(int s, int visited[])
{
	visited[s] = 1;
	list<int>::iterator it;
	for (it = adj[s].begin(); it != adj[s].end(); it++)
	{
		if (visited[*it] == 0)
		{
			DFS_Util(*it, visited);
		}
	}
}
bool Graph::isStronglyConnected()
{
	int *visited = new int[V];
	for (int i = 0; i < V; i++)
		visited[i] = 0;
	DFS_Util(0, visited);  // first dfs call
	for (int i = 0; i < V; i++)   
	{
		if (visited[i] == 0)  // if some nodes not visited return false
			return false;
	}
	for (int i = 0; i < V; i++)
		visited[i] = 0;
	Graph rev(V);     
	rev = transpose();   // reverse the graph
	rev.DFS_Util(0, visited);   // run DFS on this graph from the node we made first DFS call
	for (int i = 0; i < V; i++)
	{
		if (visited[i] == 0)    // if some nodes can't be reached that means we cant reach to the node from other node in original graph,return false
			return false;
	}
	return true; // if all conditions satisfied return true;
}
int main()
{

	Graph g1(5);
	g1.addEdge(0, 1);
	g1.addEdge(1, 2);
	g1.addEdge(2, 3);
	g1.addEdge(3, 0);
	g1.addEdge(2, 4);
	g1.addEdge(4, 2);
	g1.isStronglyConnected() ? cout << "Yes\n" : cout << "No\n";

	Graph g2(4);
	g2.addEdge(0, 1);
	g2.addEdge(1, 2);
	g2.addEdge(2, 3);
	g2.isStronglyConnected() ? cout << "Yes\n" : cout << "No\n";
	return 0;
}