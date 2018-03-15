/*
Given an array arr[], find the maximum j – i such that arr[j] > arr[i].

Examples:

Input: {34, 8, 10, 3, 2, 80, 30, 33, 1}
Output: 6  (j = 7, i = 1)

Input: {9, 2, 3, 4, 5, 6, 7, 8, 18, 0}
Output: 8 ( j = 8, i = 0)

Input:  {1, 2, 3, 4, 5, 6}
Output: 5  (j = 5, i = 0)

Input:  {6, 5, 4, 3, 2, 1}
Output: -1
*/
#include<iostream>
using namespace std;
int maxIndexDiff(int arr[], int n)
{
	int *less = new int[n];
	int *more = new int[n];
	/* Construct less[] such that less[i] stores the minimum value
	from (arr[0], arr[1], ... arr[i]) */
	for (int i = 0; i < n; i++)
	{
		if (i == 0 || arr[i] < less[i - 1])
			less[i] = arr[i];
		else
			less[i] = less[i - 1];
	}
	/* Construct more[] such that more[j] stores the maximum value
	from (arr[j], arr[j+1], ..arr[n-1]) */
	for (int i = n - 1; i >= 0; i--)
	{
		if (i == n - 1 || arr[i] > more[i + 1])
			more[i] = arr[i];
		else
			more[i] = more[i + 1];
	}
	int i, j;
	i = j = 0;
	int curr_max = -1;
	int max = -1;
	//traverse both to get max j-i
	while (i < n &&j < n)
	{
		if (less[i] <= more[j])
		{
			curr_max = j - i;
			j++;
		}
		else if (less[i] > more[j])
		{
			i++;
		}
		if (max < curr_max)
			max = curr_max;
	}
	return max;
}
int main()
{
	int arr[] = { 9, 2, 3, 4, 5, 6, 7, 8, 18, 0 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int maxDiff = maxIndexDiff(arr, n);
	cout << maxDiff;
	return 0;
}