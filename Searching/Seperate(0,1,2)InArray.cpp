/*
given an array of 0,1,2
Sort the array in one scan in O(1) space complexity
*/
#include<iostream>
using namespace std;
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
void sort(int arr[], int n)
{
	int low, mid, high;
	low = mid = 0;
	high = n - 1;
	while (mid <= high)
	{
		if (arr[mid] == 1)
			mid++;
		else if (arr[mid] == 0)
		{
			swap(&arr[low], &arr[mid]);
			low++;
			mid++;
		}
		else if (arr[mid] == 2)
		{
			swap(&arr[high], &arr[mid]);
			high--;
		}
	}
}
int main()
{
	int arr[] = { 1,0,0,1,1,1,2,0,1,2,0,1 };
	int size = sizeof(arr) / sizeof(arr[0]);
	sort(arr, size);
	cout << "sorted array\n";
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	return 0;
}