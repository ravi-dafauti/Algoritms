/*
Given Postorder and Inorder traversals, construct the tree.

Examples:

Input : 
in[]   = {2, 1, 3}
post[] = {2, 3, 1}

Output : Root of below tree
      1
    /   \
   2     3 


Input : 
in[]   = {4, 8, 2, 5, 1, 6, 3, 7}
post[] = {8, 4, 5, 2, 6, 7, 3, 1} 

Output : Root of below tree
          1
       /     \
     2        3
   /    \   /   \
  4     5   6    7
    \
      8
*/

#include<iostream>
using namespace std;

struct Node
{
	int data;
	Node* left, *right;
};
Node* newNode(int data)
{
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = data;
	node->left = node->right = NULL;
	return (node);
}

/* This funtcion is here just to test  */
void preOrder(Node* node)
{
	if (node == NULL) return;
	printf("%d ", node->data);
	preOrder(node->left);
	preOrder(node->right);
}
int search(int arr[], int l, int h, int data)
{
	for (int i = l; i <= h; i++)
	{
		if (arr[i] == data)
			return i;
	}
	return -1;
}
Node *buildTreeUtil(int in[], int post[], int l, int h)
{
	int static index = h;
	Node *root = newNode(post[index]);
	if (l > h)
		return NULL;
	if (l == h)
	{
		return root;
	}
	int mid = search(in, l, h, post[index]);
	index--;
	root->right = buildTreeUtil(in, post, mid + 1, h);
	index--;
	root->left = buildTreeUtil(in, post, l, mid - 1);
	return root;
}
Node *buildTree(int in[], int post[], int n)
{
	return buildTreeUtil(in, post, 0, n - 1);
}

int main()
{
	int in[] = { 4, 8, 2, 5, 1, 6, 3, 7 };
	int post[] = { 8, 4, 5, 2, 6, 7, 3, 1 };
	int n = sizeof(in) / sizeof(in[0]);

	Node *root = buildTree(in, post, n);

	cout << "Preorder of the constructed tree : \n";
	preOrder(root);
    return 0;
}

