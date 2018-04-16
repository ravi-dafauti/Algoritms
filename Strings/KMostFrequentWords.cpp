#include<iostream>
#include<string>
using namespace std;

struct TrieNode
{
	int isleaf;
	int minHeapIndex;
	int frequency;
	TrieNode *children[26];
};

struct MinHeapNode
{
	int frequency;
	TrieNode *node;
	string word;
};

class MinHeap
{
public:
	int count;
	int size;
	MinHeapNode *arr;
	int leftChild(int i)
	{
		if (i < count && 2 * i + 1 < count)
			return 2 * i + 1;
		return -1;
	}
	int rightChild(int i)
	{
		if (i < count && 2 * i + 2 < count)
			return 2 * i + 2;
return -1;
	}
	int parent(int i)
	{
		if (i == 0)
			return -1;
		if (i < count && (i - 1) / 2 >= 0)
			return (i - 1) / 2;
		return -1;
	}
	void percolateDown(int i)
	{
		int l = leftChild(i);
		int r = rightChild(i);
		int min = i;
		if (l != -1 && arr[min].frequency > arr[l].frequency)
			min = l;
		if (r != -1 && arr[r].frequency < arr[min].frequency)
			min = r;
		if (i != min)
		{
			MinHeapNode temp;
			arr[min].node->minHeapIndex = i;
			arr[i].node->minHeapIndex = min;
			temp = arr[min];
			arr[min] = arr[i];
			arr[i] = temp;
			percolateDown(min);
		}
	}
	MinHeap(int size)
	{
		count = 0;
		this->size = size;
		arr = new MinHeapNode[size];
	}
	void insert(string word, int freq, TrieNode *node)
	{
		if (node->minHeapIndex != -1)
		{
			arr[node->minHeapIndex].frequency;
			percolateDown(node->minHeapIndex);

		}
		else if (count < size)
		{
			count++;
			int n = count - 1;
			while (parent(n) != -1 && arr[parent(n)].frequency > freq)
			{
				arr[n] = arr[parent(n)];
				arr[n].node->minHeapIndex = n;
				n = parent(n);
			}
			MinHeapNode m;
			m.frequency = freq;
			m.word = word;
			m.node = node;
			node->minHeapIndex = n;
			arr[n] = m;
		}
		else if (node->frequency > arr[0].frequency)
		{
			MinHeapNode temp;
			temp.frequency = node->frequency;
			temp.node = node;
			temp.word = word;
			arr[0] = temp;
			arr[0].node->minHeapIndex = 0;
			percolateDown(0);
		}
	}
};

class Trie
{
	TrieNode *root;
	MinHeap *minHeap;
	TrieNode *newTrieNode()
	{
		TrieNode *temp = new TrieNode();
		temp->isleaf = 0;
		temp->minHeapIndex = -1;
		temp->frequency = 0;
		for (int i = 0; i < 26; i++)
			temp->children[i] = NULL;
		return temp;
	}
public:
	Trie(int size)
	{
		root = newTrieNode();
		minHeap = new MinHeap(size);
	}
	void insert(string s)
	{
		TrieNode *crawl = root;
		for (int i = 0; i < s.length(); i++)
		{
			if (crawl->children[s[i] - 'a'] == NULL)
			{
				crawl->children[s[i] - 'a'] = newTrieNode();
			}
			crawl = crawl->children[s[i] - 'a'];
		}
		if (crawl->isleaf == 1)
		{
			crawl->frequency++;
		}
		else
		{
			crawl->isleaf = 1;
			crawl->frequency = 1;
		}
		minHeap->insert(s, crawl->frequency, crawl);
	}
	void printFrequent()
	{
		for (int i = 0; i < minHeap->count; i++)
		{
			cout << minHeap->arr[i].word << " ";
		}
	}
};
void print(string arr[], int n,int k)
{
	Trie t(k);
	for (int i = 0; i < n; i++)
		t.insert(arr[i]);
	t.printFrequent();
}
int main()
{
	string arr[] = {
		"abc","def","alka","alka","alka","alka","abc","def","xyz","klm","ravinder","ravinder","ravinder"
	};
	int n = sizeof(arr) / sizeof(arr[0]);
	print(arr, n, 2);
	return 0;
}