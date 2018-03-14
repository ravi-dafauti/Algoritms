#include<iostream>
using namespace std;
int binarySearch(int arr[], int low, int high, int data)
{
	if (low > high)
		return -1;
	int mid = (low + high) / 2;
	if (arr[mid] == data)
		return data;
	else if (arr[mid] > data)
	{
		return binarySearch(arr, low, mid - 1, data);
	}
	else if (arr[mid] < data)
		return binarySearch(arr, mid + 1, high, data);
}
int binarySearchRecur(int arr[], int n, int data)
{
	int low = 0;
	int high = n - 1;
	while (low <= high)
	{
		int mid = (low + high) / 2;
		if (arr[mid] == data)
			return data;
		else if (arr[mid] > data)
			high = mid - 1;
		else if (arr[mid] < data)
			low = mid + 1;
	}
	return -1;
}
int main(void)
{
	int arr[] = { 2, 3, 4, 10, 40 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int x = 3;
	int result = binarySearchRecur(arr, n, x);
	if (result == -1)
		cout << "element not found\n";
	else
		cout << "element found\n";
	return 0;
}