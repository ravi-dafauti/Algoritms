/*
Given heights of n towers and a value k. We need to either increase or decrease height of every tower by k (only once) where k > 0. 
The task is to minimize the difference between the heights of the longest and the shortest tower after modifications, and output this difference.

Examples:

Input  : arr[] = {1, 15, 10}, k = 6
Output :  Maximum difference is 5.
Explanation : We change 1 to 6, 15 to
9 and 10 to 4. Maximum difference is 5
(between 4 and 9). We can't get a lower
difference.

Input : arr[] = {1, 5, 15, 10}
k = 3
Output : Maximum difference is 8
arr[] = {4, 8, 12, 7}

Input : arr[] = {4, 6}
k = 10
Output : Maximum difference is 2
arr[] = {14, 16} OR {-6, -4}

Input : arr[] = {6, 10}
k = 3
Output : Maximum difference is 2
arr[] = {9, 7}

Input : arr[] = {1, 10, 14, 14, 14, 15}
k = 6
Output: Maximum difference is 5
arr[] = {7, 4, 8, 8, 8, 9}

Input : arr[] = {1, 2, 3}
k = 2
Output: Maximum difference is 2
arr[] = {3, 4, 5}
*/
#include <iostream>
#include <algorithm>
using namespace std;

int min(int a, int b)
{
	if (a < b)
		return a;
	return b;
}
int getMinDiff(int arr[], int n, int k)
{
	if (n == 1)
		return 0;

	sort(arr, arr + n);

	// Initialize result
	int ans = arr[n - 1] - arr[0];

	// Handle corner elements
	int small = arr[0] + k;
	int big = arr[n - 1] - k;
	if (small > big)
		swap(small, big);

	// Traverse middle elements
	for (int i = 1; i < n - 1; i++)
	{
		int subtract = arr[i] - k;
		int add = arr[i] + k;

		// If both subtraction and addition
		// do not change diff
		if (subtract >= small || add <= big)
			continue;

		if (subtract < small && add > big)
		{
			if (big - subtract <= add - small)
				small = subtract;
			else
				big = add;
		}
		else if (subtract > small)
		{
			if (big - subtract < big - small)
				small = subtract;
		}
		else
		{
			if (add - small < big - small)
				big = add;
		}

	}

	return  min(ans, big - small);
}

int main()
{
	int arr[] = { 1, 2, 3 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int k = 2;
	cout << "\nMaximum difference is "<< getMinDiff(arr, n, k);
	return 0;
}
