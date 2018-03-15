/*
given a sorted array with duplicates find the first occurance of a number
*/
#include<iostream>
using namespace std;
int firstOccurance(int arr[], int low, int high, int data)
{
	if (low > high)
		return -1;
	if (low + 1 == high)
	{
		if (arr[low] == data)
			return low;
		else if (arr[high] == data)
			return high;
		else
			return -1;
	}
	int mid = (low + high) / 2;
	if (arr[mid] == data && arr[mid] > arr[mid - 1])
		return mid;
	else if (arr[mid] >= data)
		return firstOccurance(arr, low, mid - 1, data);
	else if (arr[mid] < data)
		return firstOccurance(arr, mid + 1, high, data);
	return -1;
}
int main()
{
	int arr[] = { 0, 3, 4, 4, 4, 6, 6, 7, 7, 9 };
	int size = sizeof(arr) / sizeof(arr[0]);
	int pos = firstOccurance(arr, 0, size - 1, 4);
	if (pos != -1)
		cout << "first occurance : " << pos;
	return 0;
}