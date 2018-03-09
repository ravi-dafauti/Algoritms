/*
Given an array arr[0 … n-1] containing n positive integers, a subsequence of arr[] is called Bitonic if it is first increasing, then decreasing. Write a function that takes an array as argument and returns the length of the longest bitonic subsequence.
A sequence, sorted in increasing order is considered Bitonic with the decreasing part as empty. Similarly, decreasing order sequence is considered Bitonic with the increasing part as empty.

Examples:

Input arr[] = {1, 11, 2, 10, 4, 5, 2, 1};
Output: 6 (A Longest Bitonic Subsequence of length 6 is 1, 2, 10, 4, 2, 1)

Input arr[] = {12, 11, 40, 5, 3, 1}
Output: 5 (A Longest Bitonic Subsequence of length 5 is 12, 11, 5, 3, 1)

Input arr[] = {80, 60, 30, 40, 20, 10}
Output: 5 (A Longest Bitonic Subsequence of length 5 is 80, 60, 30, 20, 10)
*/
#include<iostream>
using namespace std;

int max(int a, int b)
{
	if (a > b)
		return a;
	else
		return b;
}
int lbs(int arr[], int n)
{
	int *LISL = new int[n]; // stores Longest increasing subsequence from Left to right
	int *LISR = new int[n]; // stores Longest increasing subsequence from rigth to left
	for (int i = 0; i < n; i++)
	{
		LISL[i] = 1;
		LISR[i] = 1;
	}
	//compute LIS from left to right
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (arr[i] > arr[j])
			{
				LISL[i] = max(LISL[i], LISL[j] + 1);
			}
		}
	}
	// compute LIS from right to left
	for (int i = n - 2; i >= 0; i--)
	{
		for (int j = n - 1; j > i; j--)
		{
			if (arr[i] > arr[j])
			{
				LISR[i] = max(LISR[i], LISR[j] + 1);
			}
		}
	}
	// add both and check maximum
	int max_sub = 0;
	for (int i = 0; i < n; i++)
	{
		if (LISL[i] + LISR[i] - 1 > max_sub)
			max_sub = LISL[i] + LISR[i] - 1;
	}
	return max_sub;
}
int main()
{
	int arr[] = { 0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5,
		13, 3, 11, 7, 15 };
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << "Length of LBS is : " << lbs(arr, n);
	return 0;
}