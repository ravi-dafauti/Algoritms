/*
A program to check if a binary tree is BST or not
A binary search tree (BST) is a node based binary tree data structure which has the following properties.
• The left subtree of a node contains only nodes with keys less than the node’s key.
• The right subtree of a node contains only nodes with keys greater than the node’s key.
• Both the left and right subtrees must also be binary search trees.
*/
#include <iostream>
using namespace std;

struct Node
{
	int data;
	struct Node* left, *right;
};

struct Node* newNode(int data)
{
	struct Node* node = new Node;
	node->data = data;
	node->left = node->right = NULL;
	return (node);
}

bool isBSTUtil(Node *root, int &prev)
{
	if (root == NULL)
		return true;
	if (!isBSTUtil(root->left, prev))
		return false;
	if (prev != -1 && root->data <= prev)
		return false;
	prev = root->data;
	return isBSTUtil(root->right, prev);
}
bool isBST(Node *root)
{
	int prev = -1;
	return isBSTUtil(root, prev);
}
int main()
{
	struct Node *root = newNode(3);
	root->left = newNode(2);
	root->right = newNode(5);
	root->left->left = newNode(1);
	root->left->right = newNode(4);

	if (isBST(root))
		cout << "Is BST";
	else
		cout << "Not a BST";

	return 0;
}