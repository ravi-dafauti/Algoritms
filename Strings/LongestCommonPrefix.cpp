/*
Given a set of strings, find the longest common prefix.

Input  : {“geeksforgeeks”, “geeks”, “geek”, “geezer”}
Output : "gee"

Input  : {"apple", "ape", "april"}
Output : "ap"
*/
#include<iostream>
#include<string>
#include<vector>
using namespace std;

#define ALPHABET_SIZE 26

struct TrieNode
{
	TrieNode *children[ALPHABET_SIZE];
	bool isLeaf;
};

class Trie
{
	TrieNode *root;
	TrieNode *newTrieNode();
public:
	Trie();
	TrieNode *getroot();
	void insert(string s);
};

Trie::Trie()
{
	root = newTrieNode();
}
TrieNode * Trie::getroot()
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
void Trie::insert(string s)
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
}

int getChildrenCount(TrieNode *t,int &index)
{
	int count = 0;
	for (int i = 0; i < ALPHABET_SIZE; i++)
	{
		if (t->children[i] != NULL)
		{
			count++;
			index = i;
		}
	}
	return count;
}
void commonPrefixUtil(Trie *&t, string &s)
{
	TrieNode *crawl = t->getroot();
	int index;
	while (getChildrenCount(crawl, index) == 1 && crawl->isLeaf == 0)
	{
		s.push_back(index + 'a');
		crawl = crawl->children[index];
	}
}
string commonPrefix(string arr[], int n)
{
	Trie *t = new Trie();
	string s = "";
	for (int i = 0; i < n; i++)
	{
		t->insert(arr[i]);
	}
	commonPrefixUtil(t, s);
	return s;
}
int main()
{
	string arr[] = { "geeksforgeeks", "geeks",
		"geek", "geezer" };
	int n = sizeof(arr) / sizeof(arr[0]);

	string ans = commonPrefix(arr, n);

	if (ans.length())
		cout << "The longest common prefix is "<< ans;
	else
		cout << "There is no common prefix";
	return (0);
}