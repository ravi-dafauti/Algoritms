/*
Given preorder traversal of a binary search tree, construct the BST.

For example, if the given traversal is {10, 5, 1, 7, 40, 50}, then the output should be root of following tree.

     10
   /   \
  5     40
 /  \      \
1    7      50  
We have discussed O(n^2) and O(n) recursive solutions in the previous post. Following is a stack based iterative solution that works in O(n) time.

1. Create an empty stack.

2. Make the first value as root. Push it to the stack.

3. Keep on popping while the stack is not empty and the next value is greater than stack’s top value. Make this value as the right child of the last popped node. Push the new node to the stack.

4. If the next value is less than the stack’s top value, make this value as the left child of the stack’s top node. Push the new node to the stack.

5. Repeat steps 2 and 3 until there are items remaining in pre[].


*/

#include<iostream>
#include<stack>
using namespace std;

struct Node
{
	int data;
	Node *left, *right;
};
void printInorder(Node* node)
{
	if (node == NULL)
		return;
	printInorder(node->left);
	cout << node->data << " ";
	printInorder(node->right);
}

Node* newNode(int data)
{
	Node* temp = (Node *)malloc(sizeof(Node));
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;
}

Node *constructTree(int pre[], int size)
{
	stack<Node *> mStack;
	Node *root = newNode(pre[0]);
	mStack.push(root);
	for (int i = 1; i < size; i++)
	{
		if (pre[i] < mStack.top()->data)
		{
			Node *temp = newNode(pre[i]);
			mStack.top()->left = temp;
			mStack.push(temp);
		}
		else
		{
			Node *temp;
			while (!mStack.empty() && mStack.top()->data <= pre[i])
			{
				temp = mStack.top();
				mStack.pop();
			}
			Node *temp1 = newNode(pre[i]);
			temp->right = temp1;
			mStack.push(temp1);
		}
	}
	return root;
}
int main()
{
	int pre[] = { 10, 5, 1, 7, 40, 50 };
	int size = sizeof(pre) / sizeof(pre[0]);

	Node *root = constructTree(pre, size);

	cout << "Inorder traversal of the constructed tree: \n";
	printInorder(root);
    return 0;
}

