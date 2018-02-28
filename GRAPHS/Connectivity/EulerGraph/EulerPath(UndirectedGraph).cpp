/*1. Make sure the graph has either 0 or 2 odd vertices.

2. If there are 0 odd vertices, start anywhere. If there are 2 odd vertices, start at one of them.

3. Follow edges one at a time. If you have a choice between a bridge and a non-bridge, always choose the non-bridge.

4. Stop when you run out of edges.


How to find if a given is edge is bridge? We count number of vertices reachable from u. We remove edge u-v and again count number of reachable vertices from u. If number of reachable vertices are reduced, then edge u-v is a bridge. To count reachable vertices, we can either use BFS or DFS, we have used DFS in the above code. The function DFSCount(u) returns number of vertices reachable from u.
Once an edge is processed (included in Euler tour), we remove it from the graph. To remove the edge, we replace the vertex entry with -1 in adjacency list. Note that simply deleting the node may not work as the code is recursive and a parent call may be in middle of adjacency list.*/
#include<iostream>
#include<list>
using namespace std;
class Graph
{
	int V;
	list<int> *adj;
	bool isConnected();
	void DFS_Util(int s, int vis[]);
	void printPathUtil(int);
	void removeEdge(int u, int v);
	bool isValidEdge(int u, int v);
	int DfsCount(int u, int vis[]);
public:
	Graph(int);
	void addEdge(int, int);
	int isEularian();
	void printEulerPath();
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
void Graph::DFS_Util(int s, int vis[])
{
	vis[s] = 1;
	list<int>::iterator it;
	for (it = adj[s].begin(); it != adj[s].end(); it++)
	{
		if (vis[*it] == 0)
			DFS_Util(*it, vis);
	}
}
bool Graph::isConnected()
{
	int *vis = new int[V];
	for (int i = 0; i < V; i++)
	{
		vis[i] = 0;
	}
	int i;
	for (i = 0; i < V; i++)
	{
		if (adj[i].size() > 0)
			break;
	}
	if (i == V)
		return true;
	DFS_Util(i, vis);
	for (int i = 0; i < V; i++)
	{
		if (adj[i].size() > 0 && vis[i] == 0)
			return false;
	}
	return true;
}
int Graph::isEularian()
{
	if (!isConnected())
		return 0;
	int odd = 0;
	for (int i = 0; i < V; i++)
	{
		if (adj[i].size() % 2 != 0)
			odd++;
	}
	if (odd > 2)
		return 0;
	if (odd == 0)
		return 2;
	return 1;
}

void Graph::removeEdge(int u, int v)
{
	list<int>::iterator it = find(adj[u].begin(), adj[u].end(), v);
	*it = -1;
	list<int>::iterator iu = find(adj[v].begin(), adj[v].end(), u);
	*iu = -1;
}

int Graph::DfsCount(int s, int vis[])
{
	int count = 1;
	vis[s] = 1;
	list<int>::iterator it;
	for (it = adj[s].begin(); it != adj[s].end(); it++)
	{
		if (*it != -1 && vis[*it] == 0)
			count += DfsCount(*it, vis);
	}
	return count;
}
bool Graph::isValidEdge(int u, int v)
{
	int count = 0;
	list<int>::iterator it;
	for (it = adj[u].begin(); it != adj[u].end(); it++)
	{
		if (*it != -1)
			count++;
	}
	if (count == 1)
		return true;
	int *vis = new int[V];
	for (int i = 0; i < V; i++)
	{
		vis[i] = 0;
	}
	int count1 = DfsCount(u, vis);
	removeEdge(u, v);
	for (int i = 0; i < V; i++)
	{
		vis[i] = 0;
	}
	int count2 = DfsCount(u, vis);
	addEdge(u, v);
	if (count1 > count2)
		return false;
	return true;
}
void Graph::printPathUtil(int u)
{
	list<int>::iterator it;
	for (it = adj[u].begin(); it != adj[u].end(); it++)
	{
		int v = *it;
		if (v != -1 && isValidEdge(u, v))
		{
			cout << u << "->" << v;
			removeEdge(u, v);
			printPathUtil(v);
		}
	}
}
void Graph::printEulerPath()
{
	if (!isEularian())
	{
		cout << "not eularian\n";
		return;
	}
	int i;
	for (i = 0; i < V; i++)
	{
		if (adj[i].size() % 2 != 0)
			break;
	}
	if (i == V)
		i = 0;
	printPathUtil(i);
	cout << "\n";
}
void test(Graph &g)
{
	int res = g.isEularian();
	if (res == 0)
		cout << "graph is not Eulerian\n";
	else if (res == 1)
		cout << "graph has a Euler path\n";
	else
		cout << "graph has a Euler cycle\n";
}
int main()
{
	Graph g1(4);
	g1.addEdge(0, 1);
	g1.addEdge(0, 2);
	g1.addEdge(1, 2);
	g1.addEdge(2, 3);
	g1.printEulerPath();

	Graph g2(3);
	g2.addEdge(0, 1);
	g2.addEdge(1, 2);
	g2.addEdge(2, 0);
	g2.printEulerPath();

	Graph g3(5);
	g3.addEdge(1, 0);
	g3.addEdge(0, 2);
	g3.addEdge(2, 1);
	g3.addEdge(0, 3);
	g3.addEdge(3, 4);
	g3.addEdge(3, 2);
	g3.addEdge(3, 1);
	g3.addEdge(2, 4);
	g3.printEulerPath();

	return 0;
}