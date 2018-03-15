/*
An element in a sorted array can be found in O(log n) time via binary search.
But suppose we rotate an ascending order sorted array at some pivot unknown to you beforehand. 
So for instance, 1 2 3 4 5 might become 3 4 5 1 2. Devise a way to find an element in the rotated array in O(log n) time.

Input  : arr[] = {5, 6, 7, 8, 9, 10, 1, 2, 3};
key = 3
Output : Found at index 8

Input  : arr[] = {5, 6, 7, 8, 9, 10, 1, 2, 3};
key = 30
Output : Not found

Input : arr[] = {30, 40, 50, 10, 20}
key = 10
Output : Found at index 3
*/
#include<iostream>
using namespace std;

int find(int arr[], int low, int high, int data)
{
	if (low > high)
		return -1;
	if (low == high)
	{
		if (arr[low] == data)
			return low;
		else return -1;
	}
	if (low + 1 == high)
	{
		if (arr[low] == data)
			return low;
		else if (arr[high] == data)
			return high;
		else return -1;
	}
	int mid = (low + high) / 2;
	if (arr[mid] == data)
		return mid;
	else if (arr[mid] > arr[low])
	{
		if (data<arr[mid] && data >= arr[low])
			return find(arr, low, mid - 1, data);
		else
			return find(arr, mid + 1, high, data);
	}

	else if (arr[mid] < arr[low])
	{
		if (data>arr[mid] && data <= arr[low])
			return find(arr, mid + 1, high, data);
		else
			return find(arr, low, mid - 1, data);
	}
	return -1;
}
int main()
{
	int arr[] = { 3, 4, 5, 1, 2 };
	int size = sizeof(arr) / sizeof(arr[0]);
	int pos = find(arr, 0, size - 1, 2);
	if (pos != -1)
		cout << "pos is : " << pos;
	return 0;
}