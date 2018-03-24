/*
Inversion Count for an array indicates – how far (or close) the array is from being sorted. If array is already sorted then inversion count is 0. If array is sorted in reverse order that inversion count is the maximum.
Formally speaking, two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j

Example:
The sequence 2, 4, 1, 3, 5 has three inversions (2, 1), (4, 1), (4, 3).
*/

#include<iostream>
using namespace std;

int mergeSort(int arr[], int low, int high)
{
	if (low == high)
		return 0;
	int inversions = 0;
	int mid = (low + high) / 2;
	int *left = new int[mid - low + 1];
	int *right = new int[high - mid];
	int i, j, k;
	for (i = low, j = 0; i <= mid; i++, j++)
		left[j] = arr[i];
	for (i = mid + 1, j = 0; i <= high; i++, j++)
		right[j] = arr[i];
	inversions += mergeSort(left, 0, mid - low);
	inversions += mergeSort(right, 0, high - mid - 1);
	i = j = 0;
	k = low;
	while (i <= mid - low && j < high - mid)
	{
		if (left[i] <= right[j])
		{
			arr[k] = left[i];
			i++;
			k++;
		}
		else
		{
			arr[k] = right[j];
			j++;
			k++;
			inversions += (mid - i + 1);
		}
	}
	while (i <= mid - low)
	{
		arr[k] = left[i];
		i++; k++;
	}
	while (j < high - mid)
	{
		arr[k] = right[j];
		j++;
		k++;
	}
	return inversions;
}
int countInversions(int arr[], int n)
{
	return mergeSort(arr, 0, n - 1);
}
int main()
{
	int arr[] = { 1, 20, 6, 4, 5 };
	cout << " Number of inversions are : " << countInversions(arr, 5);
    return 0;
}

