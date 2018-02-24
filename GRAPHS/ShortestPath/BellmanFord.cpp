#include<iostream>
#include<vector>
#define INF 9999999
using namespace std;
class Graph
{
	int V;
	vector<pair<pair<int, int>, int>> edges;
public:
	Graph(int V);
	void addEdge(int u, int v, int w);
	void bellmanFord(int s);
};

Graph::Graph(int V)
{
	this->V = V;
}
void Graph::addEdge(int u, int v, int w)
{
	edges.push_back(make_pair(make_pair(u, v), w));
}
void Graph::bellmanFord(int s)
{
	int *dis = new int[V];
	for (int i = 0; i < V; i++)
	{
		dis[i] = INF;
	}
	dis[s] = 0;
	for (int i = 0; i < V - 1; i++)
	{
		vector<pair<pair<int, int>, int>>::iterator it;
		for (it = edges.begin(); it != edges.end(); it++)
		{
			if (dis[(*it).first.first] !=INF && dis[(*it).first.first] + (*it).second < dis[(*it).first.second])
			{
				dis[(*it).first.second] = dis[(*it).first.first] + (*it).second;
			}
		}
	}
	vector<pair<pair<int, int>, int>>::iterator it;
	for (it = edges.begin(); it != edges.end(); it++)
	{
		if (dis[(*it).first.first] != INF && dis[(*it).first.first] + (*it).second < dis[(*it).first.second])
		{
			cout << "there is a negative weight cycle\n";
		}
	}
	for (int i = 0; i < V; i++)
	{
		cout << i << " : " << dis[i] << "\n";
	}
}
int main()
{
	Graph g(5);
	g.addEdge(0, 1, -1);
	g.addEdge(0, 2, 4);
	g.addEdge(1, 2, 3);
	g.addEdge(1, 3, 2);
	g.addEdge(1, 4, 2);
	g.addEdge(3, 2, 5);
	g.addEdge(3, 1, 1);
	g.addEdge(4, 3, -3);
	g.bellmanFord(0);
	return 0;
}