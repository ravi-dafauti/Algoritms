#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h>
#include<stack>
using namespace std;
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
void Dfs(struct graph *G, int v[], int s, int *c)
{
	v[s] = 1;
	int i;
	for (i = 0; i < G->V; i++)
	{
		if (G->g[s][i] && v[i] == 0)
		{
			*c = *c + 1;
			Dfs(G, v, i, c);
		}
	}
}
void countDegree(struct graph *G, int deg[])
{
	
	int i, j;
	for (i = 0; i < G->V; i++)
	{
		for (j = 0; j < G->V; j++)
		{
			if (G->g[i][j] == 1)
			{
				deg[i]++;
			}
		}
	}
}
void removeEdge(struct graph *G, int u, int v)
{
	G->g[u][v] = 0;
	G->g[v][u] = 0;
}
int isSafe(struct graph *G, int u, int v)
{
	int *vis = (int *)malloc(sizeof(int)*G->V);
	int i;
	int cc = 0;
	for (i = 0; i < G->V; i++)
	{
		vis[i] = 0;
		if (G->g[u][i])
		{
			cc++;
		}
	}
	if (cc == 1)
	{
		return 1;
	}
	int count1 = 0;
	Dfs(G, vis, u, &count1);
	removeEdge(G, u, v);
	int count2 = 0;
	for (i = 0; i < G->V; i++)
	{
		vis[i] = 0;
	}
	Dfs(G, vis, u, &count2);
	addEdge(G, u, v);
	if (count1 > count2)
	{
		return 0;
	}
	return 1;

}
void feuryUtil(struct graph *G, int u)
{
	int i;
	for (i = 0; i < G->V; i++)
	{
		if (G->g[u][i] && isSafe(G, u, i))
		{
			removeEdge(G, u, i);
			printf("%d -> %d ", u, i);
			feuryUtil(G, i);
		}
	}
}
void feury(struct graph *G)
{
	int *deg = (int *)malloc(sizeof(int)*G->V);
	int i;
	for (i = 0; i < G->V; i++)
	{
		deg[i] = 0;
	}
	countDegree(G, deg);
	int u = 0;
	for (i = 0; i < G->V; i++)
	{
		if (deg[i] % 2 != 0)
		{
			u = i;
			break;
		}
	}
	feuryUtil(G, u);
}
int main()
{
	struct graph *G = createGraph(4);
	addEdge(G, 0, 1);
	addEdge(G, 0, 2);
	addEdge(G, 1, 2);
	addEdge(G, 2, 3);
	feury(G);
	return 0;
}