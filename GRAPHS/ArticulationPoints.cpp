#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h>
struct graph
{
	int V;
	int **g;
};
struct graph* createGraph(int V)
{
	struct graph *G = (struct graph *)malloc(sizeof(struct graph));
	G->V = V;
	G->g = (int **)malloc(sizeof(int)*V);
	int i, j;
	for (i = 0; i < V; i++)
	{
		G->g[i] = (int *)malloc(sizeof(int)*V);
	}
	for (i = 0; i < V; i++)
	{
		for (j = 0; j < V; j++)
		{
			G->g[i][j] = 0;
		}
	}
	return G;
}
void addEdge(struct graph *G, int u, int v)
{
	G->g[u][v] = 1;
	G->g[v][u] = 1;
}
void Dfs(struct graph *G, int v[], int s)
{
	v[s] = 1;
	int i;
	for (i = 0; i < G->V; i++)
	{
		if (G->g[s][i] && v[i] == 0)
		{
			Dfs(G, v, i);
		}
	}
}
int count = 0;
int mini(int a, int b)
{
	if (a < b)
	{
		return a;
	}
	return b;
}
void articulationPoints(struct graph *G, int points[], int s, int low[], int dfsnum[], int vis[], int parent[])
{
	vis[s] = 1;
	dfsnum[s] = low[s] = count;
	count++;
	int i;
	int children = 0;
	for (i = 0; i < G->V; i++)
	{
		if (G->g[s][i] && vis[i] == 0)
		{
			children++;
			parent[i] = s;
			articulationPoints(G, points, i, low, dfsnum, vis, parent);
			if (parent[s]!=-1 && low[i] >= dfsnum[s])
			{
				points[s] = 1;
			}
			if (parent[s] == -1 && children > 1)
			{
				points[s] = 1;
			}
			low[s] = mini(low[s], low[i]);
		}
		else if (G->g[s][i]&& i != s&&parent[s] != i&&vis[i])
		{
			low[s] = mini(low[s], dfsnum[i]);
		}
		
	}
}
int main()
{
	struct graph *G = createGraph(5);
	addEdge(G, 1, 0);
	addEdge(G, 0, 2);
	addEdge(G, 2, 1);
	addEdge(G, 0, 3);
	addEdge(G, 3, 4);
	int points[5] = { 0 };
	int low[5] = { 0 };
	int dfsnum[5] = { 0 };
	int vis[5] = { 0 };
	int parent[5] = { -1 };
	articulationPoints(G, points, 0, low, dfsnum, vis, parent);
	int i;
	for (i = 0; i < 5; i++)
	{
		printf("%d ",points[i]);
	}
	return 0;
}