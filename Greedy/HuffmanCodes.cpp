/*
Huffman coding is a lossless data compression algorithm. The idea is to assign variable-length codes to input characters, lengths of the assigned codes are based on the frequencies of corresponding characters.
The most frequent character gets the smallest code and the least frequent character gets the largest code.
The variable-length codes assigned to input characters are Prefix Codes, means the codes (bit sequences) are assigned in such a way that the code assigned to one character is not prefix of code assigned to any other character.
This is how Huffman Coding makes sure that there is no ambiguity when decoding the generated bit stream.
Let us understand prefix codes with a counter example. Let there be four characters a, b, c and d, and their corresponding variable length codes be 00, 01, 0 and 1. 
This coding leads to ambiguity because code assigned to c is prefix of codes assigned to a and b. If the compressed bit stream is 0001, the de-compressed output may be “cccd” or “ccb” or “acd” or “ab”.

character   Frequency
a            5
b           9
c           12
d           13
e           16
f           45

character   code-word
f          0
c          100
d          101
a          1100
b          1101
e          111

Steps to build Huffman Tree
Input is array of unique characters along with their frequency of occurrences and output is Huffman Tree.

1. Create a leaf node for each unique character and build a min heap of all leaf nodes (Min Heap is used as a priority queue. 
   The value of frequency field is used to compare two nodes in min heap. Initially, the least frequent character is at root)

2. Extract two nodes with the minimum frequency from the min heap.

3. Create a new internal node with frequency equal to the sum of the two nodes frequencies. Make the first extracted node as its left child and the other extracted node as its right child. Add this node to the min heap.

4. Repeat steps#2 and #3 until the heap contains only one node. The remaining node is the root node and the tree is complete
*/
#include<iostream>
#include<vector>
using namespace std;

struct Node
{
	char node;
	int frequency;
	Node *left;
	Node *right;
};

class PriorityQueue
{
	Node **arr;
	int count;
	int size;
	void percolatedown(int);
	int leftChild(int);
	int rightChild(int);
	int parent(int);
public:
	PriorityQueue(int);
	void insert(Node *);
	Node *min();
	bool empty();
	void deleteMin();
	int sizeOfPQ();
};
PriorityQueue::PriorityQueue(int size)
{
	arr = (Node **)malloc(sizeof(int)*size);
	this->size = size;
	this->count = 0;
}
int PriorityQueue::leftChild(int i)
{
	if (i < count && 2 * i + 1 < count)
		return 2 * i + 1;
	return -1;
}
int PriorityQueue::rightChild(int i)
{
	if (i < count && 2 * i + 2 < count)
		return 2 * i + 2;
	return -1;
}
int PriorityQueue::parent(int i)
{
	if (i == 0)
		return -1;
	if (i < count && (i - 1) / 2 >= 0)
		return (i - 1) / 2;
	return -1;
}
void PriorityQueue::percolatedown(int i)
{
	int l = leftChild(i);
	int r = rightChild(i);
	int min = i;
	if (l != -1 && arr[min]->frequency > arr[l]->frequency)
		min = l;
	if (r != -1 && arr[min]->frequency > arr[r]->frequency)
		min = r;
	if (min != i)
	{
		Node *temp = arr[min];
		arr[min] = arr[i];
		arr[i] = temp;
		percolatedown(min);
	}
}
void PriorityQueue::insert(Node *n)
{
	count++;
	int i = count - 1;
	while (i >= 0 && parent(i) != -1 && arr[parent(i)]->frequency > n->frequency)
	{
		arr[i] = arr[parent(i)];
		i = parent(i);
	}
	arr[i] = n;
}
bool PriorityQueue::empty()
{
	if (count <= 0)
		return true;
	return false;
}
Node *PriorityQueue::min()
{
	if (count > 0)
		return arr[0];
}
void PriorityQueue::deleteMin()
{
	arr[0] = arr[count - 1];
	count--;
	percolatedown(0);
}

int PriorityQueue::sizeOfPQ()
{
	return count;
}
Node *createNode(char a, int f)
{
	Node *temp = (Node *)malloc(sizeof(Node));
	temp->node = a;
	temp->frequency = f;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}
vector<int> v;
void traverse(Node *root)
{

	if (root != NULL)
	{
		if (root->left == NULL && root->right == NULL)
		{
			if (v.size() != 0)
			{
				cout << root->node << " : ";
				vector<int>::iterator it;
				for (it = v.begin(); it != v.end(); it++)
					cout << *it;
				cout << "\n";
			}
		}
		v.push_back(0);
		traverse(root->left);
		v.pop_back();
		v.push_back(1);
		traverse(root->right);
		v.pop_back();
	}

}
void HuffmanCodes(char arr[], int freq[], int size)
{
	PriorityQueue pq(size);
	for (int i = 0; i < size; i++)
	{
		Node *x = createNode(arr[i], freq[i]);
		pq.insert(x);
	}
	while (pq.sizeOfPQ() > 1)
	{
		Node *x1 = pq.min();
		pq.deleteMin();
		Node *x2 = pq.min();
		pq.deleteMin();
		Node *temp = createNode('#', x1->frequency + x2->frequency);
		temp->left = x1;
		temp->right = x2;
		pq.insert(temp);
	}
	Node *root = pq.min();
	traverse(root);
}
int main()
{
	char arr[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
	int freq[] = { 5, 9, 12, 13, 16, 45 };

	int size = sizeof(arr) / sizeof(arr[0]);

	HuffmanCodes(arr, freq, size);
    return 0;
}

