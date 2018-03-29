/*
Write a function that returns true if the given Binary Tree is SumTree else false. A SumTree is a Binary Tree where the value of a node is equal to sum of
the nodes present in its left subtree and right subtree. An empty tree is SumTree and sum of an empty tree can be considered as 0.
A leaf node is also considered as SumTree.

Following is an example of SumTree.

          26
        /   \
      10     3
    /    \     \
  4      6      3
*/

#include<iostream>
using namespace std;
struct node
{
	int data;
	struct node* left;
	struct node* right;
};
struct node* newNode(int data)
{
	struct node* node =
		(struct node*)malloc(sizeof(struct node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	return(node);
}
bool isLeafNode(node *root)
{
	return root->left == NULL && root->right == NULL;
}

bool isSumTree(node *root)
{
	if (root == NULL || isLeafNode(root))
	{
		return true;
	}
	if (isSumTree(root->left) && isSumTree(root->right))
	{
		int ls, rs;
		if (root->left == NULL)
			ls = 0;
		else if (isLeafNode(root->left))
			ls = root->left->data;
		else
			ls = root->left->data * 2;
		if (root->right == NULL)
			rs = 0;
		else if (isLeafNode(root->right))
			rs = root->right->data;
		else
			rs = root->right->data * 2;
		return root->data == (ls + rs);
	}
	return false;
}
/* Driver program to test above function */
int main()
{
	node *root = newNode(26);
	root->left = newNode(10);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(6);
	root->right->right = newNode(3);
	if (isSumTree(root))
		cout << "The given tree is a SumTree ";
	else
		cout << "The given tree is not a SumTree ";
	return 0;
}

