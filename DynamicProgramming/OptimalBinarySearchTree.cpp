/*
Given a sorted array keys[0.. n-1] of search keys and an array freq[0.. n-1] of frequency counts, where freq[i] is the number of searches to keys[i]. Construct a binary search tree of all keys such that the total cost of all the searches is as small as possible.

Let us first define the cost of a BST. The cost of a BST node is level of that node multiplied by its frequency. Level of root is 1.

Example 1
Input:  keys[] = {10, 12}, freq[] = {34, 50}
There can be following two possible BSTs
10                       12
\                     /
12                 10
I                     II
Frequency of searches of 10 and 12 are 34 and 50 respectively.
The cost of tree I is 34*1 + 50*2 = 134
The cost of tree II is 50*1 + 34*2 = 118

Example 2
Input:  keys[] = {10, 12, 20}, freq[] = {34, 8, 50}
There can be following possible BSTs
10                12                 20         10              20
\             /    \              /             \            /
12          10     20           12               20         10
\                            /                 /           \
20                        10                12             12
I               II             III             IV             V
Among all possible BSTs, cost of the fifth BST is minimum.
Cost of the fifth BST is 1*50 + 2*34 + 3*8 = 142
*/
#include<iostream>
using namespace std;
int optimalSearchTree(int keys[], int freq[], int n)
{
	int **table = (int **)malloc(sizeof(int)*n);
	for (int i = 0; i < n; i++)
		table[i] = (int *)malloc(sizeof(int)*n);
	for (int i = 0; i < n; i++)
		table[i][i] = freq[i];
	int l;
	for (l = 2; l <= n; l++)
	{
		for (int i = 0; i + l - 1 < n; i++)
		{
			int j = i + l - 1;
			int sum = 0;
			for (int k = i; k <= j; k++)
				sum += freq[k];
			int min = 9999999;
			for (int k = i; k <= j; k++)
			{
				int mincur = 0;
				if (k - 1 >= i)
					mincur += table[i][k - 1];
				if (k + 1 <= j)
					mincur += table[k + 1][j];
				if (mincur < min)
					min = mincur;
			}
			table[i][j] = min + sum;
		}
	}
	return table[0][n - 1];
}
int main()
{
	int keys[] = { 10, 12, 20 };
	int freq[] = { 34, 8, 50 };
	int n = sizeof(keys) / sizeof(keys[0]);
	cout << "Cost of Optimal BST is : " << optimalSearchTree(keys, freq, n);
	return 0;
}