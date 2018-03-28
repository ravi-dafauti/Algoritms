#include<iostream>
using namespace std;
struct TrieNode
{
	bool endOfString;
	TrieNode *children[26];
};
class Trie
{
	TrieNode *root;
	TrieNode *getNode();
	bool isFree(TrieNode *);
	bool deleteUtil(TrieNode *t, string key, int level, int len);
public:
	Trie();
	void insert(string);
	void deleteKey(string);
	bool search(string);
};
TrieNode *Trie::getNode()
{
	TrieNode *temp = new TrieNode();
	temp->endOfString = false;
	for (int i = 0; i < 26; i++)
		temp->children[i] = NULL;
	return temp;
}
Trie::Trie()
{
	root = getNode();
}
void Trie::insert(string key)
{
	TrieNode *crawl = root;
	for (int i = 0; i < key.length(); i++)
	{
		int index = key[i] - 'a';
		if (crawl->children[index] == NULL)
		{
			crawl->children[index] = getNode();
		}
		crawl = crawl->children[index];
	}
	crawl->endOfString = true;
}

bool Trie::search(string key)
{
	TrieNode *crawl = root;
	for (int i = 0; i < key.length(); i++)
	{
		int index = key[i] - 'a';
		if (crawl->children[index] == NULL)
		{
			return false;
		}
		crawl = crawl->children[index];
	}
	return (crawl != NULL&&crawl->endOfString);
}
bool Trie::isFree(TrieNode *t)
{
	for (int i = 0; i < 26; i++)
	{
		if (t->children[i] != NULL)
			return false;
	}
	return true;
}
bool Trie::deleteUtil(TrieNode *t, string key, int level, int len)
{
	if (level == len)
	{
		if (t->endOfString)
		{
			t->endOfString = false;
			if (isFree(t))
				return true;
			else
				return false;
		}
	}
	else
	{
		int index = key[level] - 'a';
		if (deleteUtil(t->children[index], key, level + 1, len))
		{
			free(t->children[index]);
			t->children[index] = NULL;
			return (t->endOfString == false && isFree(t));
		}
	}
}
void Trie::deleteKey(string key)
{
	if (key.length() > 0)
		deleteUtil(root, key, 0, key.length());
}
int main()
{
	Trie t;
	t.insert("abc");

	if (t.search("abc"))
	{
		cout << "found key\n";
	}
	else
		cout << "not found";
	t.deleteKey("abc");
	if (t.search("abc"))
	{
		cout << "found key\n";
	}
	else
		cout << "not found";
    return 0;
}

