/*
Given a dictionary of words and an input string, find the longest prefix of the string which is also a word in dictionary.

Examples:

Let the dictionary contains the following words:
{are, area, base, cat, cater, children, basement}

Below are some input/output examples:
--------------------------------------
Input String            Output
--------------------------------------
caterer                 cater
basemexy                base
child                   < Empty >
*/
#include<iostream>
#include<string>
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

int getChildrenCount(TrieNode *t, int &index)
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
void commonPrefixUtil(Trie *&t, string &input,string &s)
{
	TrieNode *crawl = t->getroot();
	string ans;
	for (int i = 0; i < input.length(); i++)
	{
		if (crawl->children[input[i] - 'a'] != NULL)
		{
			s.push_back(input[i]);
			crawl = crawl->children[input[i] - 'a'];
			if (crawl->isLeaf == 1)
			{
				ans = s;
			}
		}
		else
			break;
	}
	s = ans;
}
string commonPrefix(string arr[], int n, string input)
{
	Trie *t = new Trie();
	for (int i = 0; i < n; i++)
	{
		t->insert(arr[i]);
	}
	string s = "";
	commonPrefixUtil(t, input, s);
	return s;
}
int main()
{
	string arr[] = { "geeksforgeeks", "gee",
		"gek", "geezer" };
	int n = sizeof(arr) / sizeof(arr[0]);

	string input = "geeksforhere";
	string ans = commonPrefix(arr, n, input);

	if (ans.length())
		cout << "The longest prefix is " << ans;
	else
		cout << "There is no prefix";
	return (0);
}