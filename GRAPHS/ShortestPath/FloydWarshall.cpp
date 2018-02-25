#include<iostream>
#include<stack>
#define INF 9999999
using namespace std;
class Graph
{
	int V;
	int **matrix;
	int **path;
	void initPath();
public:
	Graph(int);
	void addEdge(int u, int v, int w);
	void FloydWarshall();
	void printPath(int u, int v);
};
Graph::Graph(int V)
{
	this->V = V;
	matrix = (int**)malloc(sizeof(int)*V);
	for (int i = 0; i < V; i++)
		matrix[i] = (int *)malloc(sizeof(int)*V);
	path = (int**)malloc(sizeof(int)*V);
	for (int i = 0; i < V; i++)
		path[i] = (int *)malloc(sizeof(int)*V);
	for(int i=0;i<V;i++)
		for (int j = 0; j < V; j++)
		{
			if (i == j)
				matrix[i][j] = 0;
			else
				matrix[i][j] = INF;
		}
}
void Graph::addEdge(int u, int v, int w)
{
	matrix[u][v] = w;
}
void Graph::initPath()
{
	for(int i=0;i<V;i++)
		for (int j = 0; j < V; j++)
		{
			if (i != j && matrix[i][j] != INF)
				path[i][j] = i;
			else
				path[i][j] = INF;
		}
}

void Graph::FloydWarshall()
{
	initPath(); // to track path 
	int **distance;
	distance = (int**)malloc(sizeof(int)*V);
	for (int i = 0; i < V; i++)
		distance[i] = (int *)malloc(sizeof(int)*V);
	for (int i = 0; i < V; i++)
		for (int j = 0; j < V; j++)
			distance[i][j] = matrix[i][j];
	for (int k = 0; k < V; k++)    	//take every node as intermediate node
	{
		for (int i = 0; i < V; i++) //for each pair of nodes check if taking k node as intermediate results in a shorter path
		{
			for (int j = 0; j < V; j++)
			{
				if (distance[i][k]!=INF&& distance[k][j]!=INF && distance[i][k] + distance[k][j] < distance[i][j])  //if taking k node as intermediate results in a shorter path update it
				{
					distance[i][j] = distance[i][k] + distance[k][j];
					path[i][j] = path[k][j]; // update the ancestor if taking k node as intermediate results in shorter path
				}
			}
		}
	}

	for (int i = 0; i < V; i++)
	{
		if (distance[i][i] < 0)
		{
			cout << "there is a negative weight cycle\n";
			return;
		}
	}
	for (int i = 0; i < V; i++)
	{
		for (int j = 0; j < V; j++)
		{
			if (distance[i][j] == INF)
				cout << "INF" << " ";
			else
				cout << distance[i][j] << " ";
		}
		cout << "\n";
	}
}
void Graph::printPath(int u, int v)
{
	stack<int> s;
	if (path[u][v] == INF)
	{
		cout << "no Path exists\n";
		return;
	}
	s.push(v);
	int temp = path[u][v];
	while (temp != INF)
	{
		s.push(temp);
		temp = path[u][temp];
	}
	while (!s.empty())
	{
		cout << s.top() << " ";
		s.pop();
	}
}
int main()
{
	Graph g(4);
	g.addEdge(0, 1, 5);
	g.addEdge(0, 3, 10);
	g.addEdge(1, 2, 3);
	g.addEdge(2, 3, 1);

	// calculate all pair shortest path
	g.FloydWarshall();
	cout << "\n";

	//print shortest path from 0 to 3
	g.printPath(0, 3);
	return 0;
}