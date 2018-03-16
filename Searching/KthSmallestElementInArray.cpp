/*
Given an array and a number k where k is smaller than size of array, we need to find the k’th smallest element in the given array. It is given that ll array elements are distinct.

Examples:

Input: arr[] = {7, 10, 4, 3, 20, 15}
k = 3
Output: 7

Input: arr[] = {7, 10, 4, 3, 20, 15}
k = 4
Output: 10
*/
#include<iostream>
using namespace std;
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
int partition(int arr[], int low, int high)
{
	if (low == high)
		return low;
	int i = low;
	int part = low - 1;
	while (i < high)
	{
		if (arr[i] <= arr[high])
		{
			part++;
			swap(&arr[part], &arr[i]);
			i++;
		}
		else
			i++;
	}
	if (part != low-1)
	{
		part++;
		swap(&arr[part], &arr[high]);
	}
	return part;
}
int kthSmallest(int arr[], int low, int high, int k)
{
	if (low <= high)
	{
		int part = partition(arr, low, high);
		if (part == k - 1)
			return arr[part];
		else if (part  < k - 1)
			return kthSmallest(arr, part + 1, high, k);
		else if (part  > k - 1)
			return kthSmallest(arr, low, part - 1, k);
	}
	return -1;
}
int main()
{
	int arr[] = { 12, 3, 5, 7, 4, 19, 26 };
	
	int n = sizeof(arr) / sizeof(arr[0]), k = 3;
	cout << "K'th smallest element is " << kthSmallest(arr, 0, n - 1, k);
	return 0;
}