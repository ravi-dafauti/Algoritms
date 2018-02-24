#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//comparator for sorting a vector of pair in ascending order with second element as key
bool sortbysec(const pair<pair<int,int>, int> &a,	const pair<pair<int,int>, int> &b)
{
	return (a.second < b.second);
}
class Graph
{
	int V; // no of vertices
	vector<pair<pair<int, int>, int>> adj; // list of edges ((u,v),distance_btw_them)
	bool find(int set[], int u, int v);// find method of Disjoint set
	int root(int set[], int u); //method to return root of Disjoint set
	void union_func(int set[], int u, int v); // method to merge two values into a set
	void sortEdges(); // sort edges in ascending order in terms of their length
public:
	Graph(int); //constructor
	void addEdge(int, int, int);  //method to add edge
	void spanningTree(); //method to find and print MST using kruskals Algo
};
Graph::Graph(int V)
{
	this->V = V;
}
void Graph::addEdge(int u, int v, int dis)
{
	adj.push_back(make_pair(make_pair(u, v), dis));
}

int Graph::root(int set[], int u)
{
	while (u != set[u])
	{
		set[u] = set[set[u]];
		u = set[u];
	}
	return u;
}
bool Graph::find(int set[], int u, int v)
{
	if (root(set, u) == root(set, v))
		return true;
	return false;
}
void Graph::union_func(int set[], int u, int v)
{
	int root1 = root(set, u);
	int root2 = root(set, v);
	if (root1 == root2)
		return;
	set[root1] = root2;
}
void Graph::sortEdges()
{
	sort(adj.begin(), adj.end(), sortbysec);
}
void Graph::spanningTree()
{
	int *set = new int[V];
	int *visited = new int[V];
	int e = 0;
	vector<pair<pair<int, int>, int>> mst;
	for (int i = 0; i < V; i++)
	{
		set[i] = i;
		visited[i] = 0;
	}
	sortEdges(); // first sort the edges in ascending order of lenght
	vector<pair<pair<int, int>, int>>::iterator it;  // iterate through edges list will we add V-1 Edges To MST
	for (it = adj.begin(); e < V - 1 && it != adj.end(); it++)
	{
		int u = (*it).first.first;
		int v = (*it).first.second;
		if (find(set, u, v)) // if this edge results in cycle ignore it
			continue;
		mst.push_back(*it);  /* if edges doesnt result in cycle add it to MST  
		                       and add the two vertices in same set*/
	    union_func(set, u, v);
	}
	//print MST
	for (it = mst.begin(); it != mst.end(); it++)
	{
		cout << (*it).first.first << " -> " << (*it).first.second << " : " << (*it).second << "\n";
	}
}
int main()
{
	Graph g(4);
	g.addEdge(0, 1, 10);
	g.addEdge(0, 2, 6);
	g.addEdge(0, 3, 5);
	g.addEdge(1, 3, 15);
	g.addEdge(2, 3, 4);

	g.spanningTree();
	return 0;
}