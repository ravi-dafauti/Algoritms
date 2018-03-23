/*
Consider an array of distinct numbers sorted in increasing order. The array has been rotated (anti-clockwise) k number of times. Given such an array, find the value of k.

Examples:

Input : arr[] = {15, 18, 2, 3, 6, 12}
Output: 2
Explanation : Initial array must be {2, 3,
6, 12, 15. 18}. We get the given array after
rotating the initial array twice.

Input : arr[] = {7, 9, 11, 12, 5}
Output: 4

Input: arr[] = {7, 9, 11, 12, 15};
Output: 0

*/
#include<iostream>
using namespace std;

int countRotations(int arr[], int low, int high)
{
	int pos;
	int l = low;
	while (low <= high)
	{
		int mid = (low + high) / 2;
			
		if (low == high)
		{
			pos = low;
			break;
		}
		if (low + 1 == high)
		{
			if (arr[low] < arr[high])
			{
				pos = low;
				break;
			}
			else
			{
				pos = high;
				break;
			}
		}
		if (arr[mid] < arr[mid + 1] && arr[mid - 1]>arr[mid])
		{
			pos = mid;
			break;
		}
		if (arr[mid] < arr[high])
			high = mid - 1;
		else
			low = mid + 1;
	}
	return pos;
}
int main()
{
	int arr[] = {7,6,5,1,2,3,4 };
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << countRotations(arr, 0, n - 1);
    return 0;
}

