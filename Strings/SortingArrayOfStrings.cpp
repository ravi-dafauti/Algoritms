/*
Given an array of strings, print them in alphabetical (dictionary) order. If there are duplicates in input array, we need to print them only once.

Examples:

Input : "abc", "xy", "bcd"
Output : abc bcd xy

Input : "geeks", "for", "geeks", "a", "portal",
"to", "learn", "can", "be", "computer",
"science", "zoom", "yup", "fire", "in", "data"
Output : a be can computer data fire for geeks
in learn portal science to yup zoom
*/
#include<iostream>
#include<string>
using namespace std;

#define ALPHABET_SIZE 26

struct TrieNode
{
	TrieNode *children[ALPHABET_SIZE];
	bool isLeaf;
	int index;
};

class Trie
{
	TrieNode *root;
	TrieNode *newTrieNode();
public:
	Trie();
	TrieNode *getroot();
	void insert(string s,int index);
	void preorder(TrieNode *t, string arr[]);
};

Trie::Trie()
{
	root = newTrieNode();
}
TrieNode *Trie::getroot()
{
	return root;
}
TrieNode* Trie::newTrieNode()
{
	TrieNode *temp = new TrieNode();
	temp->isLeaf = 0;
	for (int i = 0; i < ALPHABET_SIZE; i++)
		temp->children[i] = NULL;
	return temp;
}
void Trie::preorder(TrieNode *crawl, string arr[])
{
	if (crawl == NULL)
		return;
	for (int i = 0; i < ALPHABET_SIZE; i++)
	{
		if (crawl->children[i] != NULL)
		{
			if (crawl->children[i]->isLeaf == 1)
			{
				cout << arr[crawl->children[i]->index] << " ";
			}
		}
		preorder(crawl->children[i], arr);
	}
}
void Trie::insert(string s,int index)
{
	TrieNode *crawl = root;
	for (int i = 0; i < s.length(); i++)
	{
		int index = s[i] - 'a';
		if (crawl->children[index] == NULL)
			crawl->children[index] = newTrieNode();
		crawl = crawl->children[index];
	}
	crawl->isLeaf = 1;
	crawl->index = index;
}
void printSorted(string arr[], int n)
{
	Trie *t = new Trie();
	for (int i = 0; i < n; i++)
		t->insert(arr[i], i);
	t->preorder(t->getroot(), arr);
}
int main()
{
	string arr[] = { "abc", "xy", "bcd" };
	int n = sizeof(arr) / sizeof(arr[0]);
	printSorted(arr, n);
	return 0;
}