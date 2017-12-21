#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<malloc.h>
#define NULL 0
struct Trie
{
	int end;
	struct Trie **store;
};
struct Trie *getNode()
{
	struct Trie *t = (struct Trie *)malloc(sizeof(struct Trie));
	t->end = 0;
	t->store = (struct Trie **)malloc(sizeof(struct Trie *) * 27);
	int i;
	for (i = 0; i < 26; i++)
	{
		t->store[i] = NULL;
	}
	return t;
}
struct Trie * insertToTrie(struct Trie *root, char *word)
{
	if (root == NULL)
	{
		root = getNode();
	}
	struct Trie *t = root;
	int index;
	int i;
	for (i = 0; i < strlen(word); i++)
	{
		index = word[i] - 'a';
		if (t->store[index] == NULL)
		{
			t->store[index] = getNode();
		}
		t = t->store[index];
	}
	t->end = 1;
	return root;
}
int searchInTrie(struct Trie *root, char *word)
{
	if (root == NULL)
	{
		return 0;
	}
	struct Trie *t = root;
	int index;
	int i;
	for (i = 0; i < strlen(word); i++)
	{
		index = word[i] - 'a';
		if (t->store[index] == NULL)
		{
			return 0;
		}
		t = t->store[index];
	}
	return (t&&t->end);
}
struct Trie * deleteFromTrie(struct Trie *root, char *word, struct Trie *parent,int ind)
{
	if (*word == '\0')
	{
		int i;
		int flag = 0;
		for (i = 0; i < 26; i++)
		{
			if (root->store[i] != NULL)
			{
				flag = 1;
				break;
			}
		}
		if (flag)
		{
			root->end = 0;
		}
		else
		{
			free(root);
			parent->store[ind] = NULL;
			return NULL;
		}
	}
	int index = *word - 'a';
	root = deleteFromTrie(root->store[index], word + 1, root, index);
	int flag = 0;
	int i;
	for (i = 0; i < 26; i++)
	{
		if (root->store[i] != NULL)
		{
			flag = 1;
			break;
		}
	}
	if (flag == 0)
	{
		free(root);
		if (parent != NULL)
		{
			parent->store[ind] = NULL;
		}
		else
		{
			return NULL;
		}
	}
	return root;
}
struct Trie * deleteTrie(struct Trie *root, char *word, struct Trie *parent, int parentindex)
{
	if (*word == '\0')
	{
		int i;
		int flag = 0;
		for (i = 0; i < 26; i++)
		{
			if (root->store[i] != NULL)
			{
				flag = 1;
				break;
			}
		}
		if (flag)
		{
			root->end = 0;
		}
		else
		{
			free(root);
			return NULL;
		}
	}
	int index = *word - 'a';
	root->store[index] = deleteTrie(root->store[index], word + 1, root, index);
	int i;
	int flag = 0;
	for (i = 0; i < 26; i++)
	{
		if (root->store[i] != NULL)
		{
			flag = 1;
			break;
		}
	}
	if (flag == 0)
	{
		free(root);
		return NULL;
	}
	return root;
}
int main()
{
	struct Trie *t = NULL;
	t = insertToTrie(t, "abc");
	//t = insertToTrie(t, "abdg");
	//t = insertToTrie(t, "hdf");
	printf("%d\n", (searchInTrie(t, "abc")));
	t = deleteTrie(t, "abc", 0, 0);
	printf("%d\n", (searchInTrie(t, "abc")));
	/*printf("%d\n", (searchInTrie(t, "abdg")));
	printf("%d\n", (searchInTrie(t, "hdf")));
	printf("%d\n", (searchInTrie(t, "abhm")));*/

	return 0;
}