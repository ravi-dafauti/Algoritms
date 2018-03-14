/*
You are given a bitonic sequence, the task is to find Bitonic Point in it. 
A Bitonic Sequence is a sequence of numbers which is first strictly increasing then after a point strictly decreasing.

A Bitonic Point is a point in bitonic sequence before which elements are strictly increasing and after which elements are strictly decreasing. 
A Bitonic point doesn’t exist if array is only decreasing or only increasing.
*/
#include<iostream>
using namespace std;
int bitonicSearch(int arr[], int low, int high)
{
	if (low > high)
		return -1;
	if (low == high)
		return low;
	int mid = (low + high) / 2;
	if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1])
		return mid;
	else if (arr[mid] > arr[mid - 1] && arr[mid] < arr[mid + 1])
		return bitonicSearch(arr, mid + 1, high);
	else
		return bitonicSearch(arr, low, mid - 1);
	return -1;
}
int main()
{
	int arr[] = { 6, 7, 8, 11, 9, 5, 2, 1 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int index = bitonicSearch(arr, 0, n - 1);
	if (index != -1)
		cout << arr[index];
	return 0;
}