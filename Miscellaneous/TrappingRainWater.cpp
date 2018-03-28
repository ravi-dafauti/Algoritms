/*
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.

Examples:

Input: arr[]   = {2, 0, 2}
Output: 2
Structure is like below
| |
|_|
We can trap 2 units of water in the middle gap.

Input: arr[]   = {3, 0, 0, 2, 0, 4}
Output: 10
Structure is like below
|
|    |
|  | |
|__|_|
We can trap "3*2 units" of water between 3 an 2,
"1 unit" on top of bar 2 and "3 units" between 2
and 4.  See below diagram also.

Input: arr[] = [0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1]
Output: 6
|
|   || |
_|_||_||||||
Trap "1 unit" between first 1 and 2, "4 units" between
first 2 and 3 and "1 unit" between second last 1 and last 2

*/
#include<iostream>
using namespace std;

int max(int a, int b)
{
	if (a > b)
		return a;
	return b;
}
int min(int a, int b)
{
	if (a < b)
		return a;
	return b;
}
int findWater(int arr[], int n)
{
	int *leftGreater = new int[n];
	int *rightGreater = new int[n];
	int trapwater = 0;
	for (int i = 0; i < n; i++)
	{
		if (i == 0)
			leftGreater[i] = -1;
		else
			leftGreater[i] = max(leftGreater[i - 1], arr[i]);
	}
	for (int i = n - 1; i >= 0; i--)
	{
		if (i == n - 1)
			rightGreater[i] = -1;
		else
			rightGreater[i] = max(rightGreater[i + 1], arr[i]);
	}
	for (int i = 0; i < n; i++)
	{
		if (rightGreater[i] == -1 || leftGreater[i] == -1)
			continue;
		trapwater += min(rightGreater[i], leftGreater[i]) - arr[i];
	}
	return trapwater;
}
int main()
{
	int arr[] = { 0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1 };
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << "Maximum water that can be accumulated is " << findWater(arr, n);
}