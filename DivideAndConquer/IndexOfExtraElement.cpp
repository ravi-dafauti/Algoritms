/*
Given two sorted arrays. There is only 1 difference between the arrays. First array has one element extra added in between. Find the index of the extra element.

Examples:

Input : {2, 4, 6, 8, 9, 10, 12};
{2, 4, 6, 8, 10, 12};
Output : 4
The first array has an extra element 9.
The extra element is present at index 4.

Input :  {3, 5, 7, 9, 11, 13}
{3, 5, 7, 11, 13}
Output :  3
*/


#include<iostream>
using namespace std;

int findExtra(int arr1[], int arr2[], int n)
{
	int low = 0;
	int high = n - 1;
	int index = n;
	while (low <= high)
	{
		int mid = (low + high) / 2;
		if (arr2[mid] == arr1[mid])
			low = mid + 1;
		else
		{
			index = mid;
			high = mid - 1;
		}
	}
	return index;
}
int main()
{
	int arr1[] = { 2, 4, 6, 8, 10, 12, 13 };
	int arr2[] = { 2, 4, 6, 8, 10, 12 };
	int n = sizeof(arr2) / sizeof(arr2[0]);

	// Solve is passed both arrays
	cout << findExtra(arr1, arr2, n);
    return 0;
}

