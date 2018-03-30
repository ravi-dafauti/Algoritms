/*
Given an array of numbers, return true if given array can represent preorder traversal of a Binary Search Tree, else return false. Expected time complexity is O(n).

Examples:

Input:  pre[] = {2, 4, 3}
Output: true
Given array can represent preorder traversal
of below tree
    2
     
      4
     /
    3

Input:  pre[] = {2, 4, 1}
Output: false
Given array cannot represent preorder traversal
of a Binary Search Tree.

Input:  pre[] = {40, 30, 35, 80, 100}
Output: true
Given array can represent preorder traversal
of below tree
     40
   /   
 30    80 
        
  35     100 


Input:  pre[] = {40, 30, 35, 20, 80, 100}
Output: false
Given array cannot represent preorder traversal
of a Binary Search Tree.
*/

#include<iostream>
#include<stack>
using namespace std;

#define MIN -999999
bool canRepresentBST(int pre[], int n)
{
	//current root is set to minimum
	int root = MIN;
	stack<int> s;
	for (int i = 0; i < n; i++)
	{
		// If we find a node who is on right side
		// and smaller than root, return false
		if (pre[i] < root)
			return false;
		// If pre[i] is in right subtree of stack top,
		// Keep removing items smaller than pre[i]
		// and make the last removed item as new
		// root.
		while (!s.empty() && s.top() < pre[i])
		{
			root = s.top();
			s.pop();
		}
		s.push(pre[i]);
	}
}
int main()
{
	int pre1[] = { 40, 30, 35, 80, 100 };
	int n = sizeof(pre1) / sizeof(pre1[0]);
	canRepresentBST(pre1, n) ? cout << "true\n" :
		cout << "false\n";

	int pre2[] = { 40, 30, 35, 20, 80, 100 };
	n = sizeof(pre2) / sizeof(pre2[0]);
	canRepresentBST(pre2, n) ? cout << "true\n" :
		cout << "false\n";
    return 0;
}

