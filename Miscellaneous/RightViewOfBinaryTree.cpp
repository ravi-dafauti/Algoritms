/*
Given a Binary Tree, print Right view of it. Right view of a Binary Tree is set of nodes visible when tree is visited from Right side.

Right view of following tree is 1 3 7 8

          1
       /     \
     2        3
   /   \     /  \
  4     5   6    7
                  \
                   8
*/

#include<iostream>
using namespace std;
struct Node
{
	int data;
	struct Node *left, *right;
};

// A utility function to create a new Binary Tree Node
struct Node *newNode(int item)
{
	struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
	temp->data = item;
	temp->left = temp->right = NULL;
	return temp;
}

void rightViewUtil(Node *root, int level, int &maxlevel)
{
	if (root == NULL)
		return;
	if (maxlevel < level)
	{
		cout << root->data << " ";
		maxlevel++;
	}
	rightViewUtil(root->right, level + 1, maxlevel);
	rightViewUtil(root->left, level + 1, maxlevel);
}
void rightView(Node *root)
{
	int maxlevel = 0;
	rightViewUtil(root, 1, maxlevel);
}
int main()
{
	struct Node *root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->right->left = newNode(6);
	root->right->right = newNode(7);
	root->right->left->right = newNode(8);

	rightView(root);

	return 0;
}

