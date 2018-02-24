#include<iostream>
#include<list>
#define INF 99999999
using namespace std;
class PriorityQueue
{
	pair<int,int> *arr;
	int count;
	int size;
	int leftChild(int i);
	int rightChild(int i);
	int parent(int);
	void percolateDown(int i);
public:
	PriorityQueue(int);
	void insert(pair<int, int>);
	pair<int,int> top();
	bool empty();
	void deleteMin();
	int search(int, int);
	void decreasekey(int, int);
	int valueAt(int);
};
PriorityQueue::PriorityQueue(int size)
{
	arr = new pair<int, int>[size];
	this->size = size;
	count = 0;
}
int PriorityQueue::leftChild(int i)
{
	if (2 * i + 1 >= count)
		return -1;
	return 2 * i + 1;
}
int PriorityQueue::rightChild(int i)
{
	if (2 * i + 2 >= count)
		return -1;
	return 2 * i + 2;
}
int PriorityQueue::parent(int i)
{
	if (i == 0)
		return -1;
	if ((i - 1) / 2 >= 0)
		return (i - 1) / 2;
	return -1;
}
void PriorityQueue::percolateDown(int i)
{
	int l = leftChild(i);
	int r = rightChild(i);
	int min = i;
	if (l != -1 && arr[l].second < arr[min].second)
		min = l;
	if (r != -1 && arr[r].second < arr[min].second)
		min = r;
	if (min != i)
	{
		pair<int, int> temp;
		temp = arr[i];
		arr[i] = arr[min];
		arr[min] = temp;
		percolateDown(min);
	}
}

pair<int, int> PriorityQueue::top()
{
	if (count != 0)
		return arr[0];
}
bool PriorityQueue::empty()
{
	if (count == 0)
		return true;
	return false;
}
void PriorityQueue::deleteMin()
{
	if (empty())
	{
		return;
	}
	arr[0] = arr[count - 1];
	count--;
	percolateDown(0);
}
int PriorityQueue::valueAt(int index)
{
	return arr[index].second;
}
void PriorityQueue::insert(pair<int, int> data)
{
	count++;
	int i;
	for (i = count - 1; i >= 0 && arr[parent(i)].second > data.second;)
	{
		arr[i] = arr[parent(i)];
		i = parent(i);
	}
	arr[i] = data;
}
int PriorityQueue::search(int root, int i)
{
	if (arr[root].first == i)
		return root;
	int l = leftChild(root);
	if (l != -1)
	{
		int temp;
		temp = search(l, i);
		if (temp != -1)
			return temp;
	}
	if (rightChild(root) != -1)
		return search(rightChild(root), i);
	return -1;
}
void PriorityQueue::decreasekey(int u, int new_dis)
{
	int i = search(0, u);
	if (i != -1)
	{
		arr[i].second = new_dis;
		pair<int, int> temp = arr[i];
		int j;
		for (j = i; j >= 0 && arr[parent(j)].second > temp.second;)
		{
			arr[j] = arr[parent(j)];
			j = parent(j);
		}
		arr[j] = temp;
	}
}
class Graph
{
	int V;
	list<pair<int, int>> *adj;
public:
	Graph(int);
	void addEdge(int, int, int);
	void dijkstra();
};
Graph::Graph(int V)
{
	this->V = V;
	adj = new list<pair<int, int>>[V];
}

void Graph::addEdge(int u, int v, int dis)
{
	adj[u].push_back(make_pair(v, dis));
	adj[v].push_back(make_pair(u, dis));
}
void Graph::dijkstra()
{
	int *distance = new int[V];
	PriorityQueue pq(V);
	pq.insert(make_pair(0, 0));
	distance[0] = 0;
	for (int i = 1; i < V; i++)
	{
		pq.insert(make_pair(i, INF));
		distance[i] = INF;
	}
	pair<int, int> temp;
	while (!pq.empty())
	{
		temp = pq.top();
		pq.deleteMin();
		list<pair<int, int>>::iterator it;
		for (it = adj[temp.first].begin(); it != adj[temp.first].end(); it++)
		{
			int index = pq.search(0, (*it).first);
			if (index != -1)
			{
				if (temp.second+(*it).second < pq.valueAt(index))
				{
					pq.decreasekey((*it).first,temp.second+(*it).second);
					distance[(*it).first] = temp.second + (*it).second;
				}
			}
		}
	}
	for (int i = 0; i < V; i++)
	{
		cout << i << " : " << distance[i] << "\n";
	}
}
int main()
{
	Graph g(9);
	g.addEdge(0, 1, 4);
	g.addEdge(0, 7, 8);
	g.addEdge(1, 2, 8);
	g.addEdge(1, 7, 11);
	g.addEdge(2, 3, 7);
	g.addEdge(2, 8, 2);
	g.addEdge(2, 5, 4);
	g.addEdge(3, 4, 9);
	g.addEdge(3, 5, 14);
	g.addEdge(4, 5, 10);
	g.addEdge(5, 6, 2);
	g.addEdge(6, 7, 1);
	g.addEdge(6, 8, 6);
	g.addEdge(7, 8, 7);
	g.dijkstra();
	return 0;
}
