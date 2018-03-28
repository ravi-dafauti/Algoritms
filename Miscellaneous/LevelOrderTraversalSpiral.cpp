#include <iostream>
#include <stack>
using namespace std;

// Binary Tree node
struct node
{
	int data;
	struct node *left, *right;
};

struct node* newNode(int data)
{
	struct node* node = new struct node;
	node->data = data;
	node->left = NULL;
	node->right = NULL;

	return(node);
}

void printSpiral(node *root)
{
	stack<node *> s1;
	stack<node *> s2;
	int rightToLeft = 1;
	s1.push(root);
	while (!s1.empty() || !s2.empty())
	{
		if (rightToLeft)
		{
			while (!s1.empty())
			{
				if (s1.top()->right)
					s2.push(s1.top()->right);
				if (s1.top()->left)
					s2.push(s1.top()->left);
				cout << s1.top()->data << " ";
				s1.pop();
			}
			rightToLeft = 0;
		}
		else
		{
			while (!s2.empty())
			{
				if (s2.top()->left)
					s1.push(s2.top()->left);
				if (s2.top()->right)
					s1.push(s2.top()->right);
				cout << s2.top()->data << " ";
				s2.pop();
			}
			rightToLeft = 1;
		}
	}
}
int main()
{
	struct node *root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(7);
	root->left->right = newNode(6);
	root->right->left = newNode(5);
	root->right->right = newNode(4);
	cout << "Spiral Order traversal of binary tree is \n";
	printSpiral(root);

	return 0;
}