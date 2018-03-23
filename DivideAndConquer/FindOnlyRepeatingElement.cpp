/*
Given a sorted array of n elements containing elements in range from 1 to n-1 i.e. one element occurs twice, the task is to find the repeating element in an array.

Examples:

Input :  arr[] = { 1, 2 , 3 , 4 , 4}
Output :  4

Input :  arr[] = { 1 , 1 , 2 , 3 , 4}
Output :  1
*/

#include<iostream>
using namespace std;

int findRepeatingElement(int arr[], int low, int high)
{
	while (low <= high)
	{
		if (low + 1 == high)
		{
			if (arr[low] == arr[high])
				return low;
		}
		int mid = (low + high) / 2;
		if (arr[mid] != mid + 1)
		{
			if (arr[mid] == arr[mid - 1] || arr[mid] == arr[mid + 1])
				return mid;
			else
				high = mid - 1;
		}
		else
			low = mid + 1;
	}
	return -1;
}
int main()
{
	int  arr[] = { 1,2,3,4,4,5,6};
	int n = sizeof(arr) / sizeof(arr[0]);
	int index = findRepeatingElement(arr, 0, n - 1);
	if (index != -1)
		cout << arr[index];
    return 0;
}

