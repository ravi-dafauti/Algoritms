#include<iostream>
using namespace std;

void merge(int arr[], int arr1[], int arr2[], int size1, int size2,int low)
{
	int i, j, k;
	i = low;
	j = k = 0;
	while (j < size1 && k < size2)
	{
		if (arr1[j] < arr2[k])
		{
			arr[i] = arr1[j];
			i++;
			j++;
		}
		else
		{
			arr[i] = arr2[k];
			i++;
			k++;
		}
	}
	while (j < size1)
	{
		arr[i] = arr1[j];
		i++;
		j++;
	}
	while (k < size2)
	{
		arr[i] = arr2[k];
		i++;
		k++;
	}
}
void mergeSortUtil(int arr[], int low, int high)
{
	if (low >= high)
		return;
	int mid = (low + high) / 2;
	int *larr = new int[mid - low + 1];
	int *rarr = new int[high - mid];
	int i, j;
	for (i = low, j = 0; i <= mid; i++, j++)
		larr[j] = arr[i];
	for (i = mid + 1, j = 0; i <= high; i++, j++)
		rarr[j] = arr[i];
	mergeSortUtil(larr, 0, mid - low);
	mergeSortUtil(rarr, 0, high - mid - 1);
	merge(arr, larr, rarr, mid - low + 1, high - mid, low);
}

void mergeSort(int arr[], int n)
{
	mergeSortUtil(arr, 0, n - 1);
}
int main()
{
	int arr[] = { 1,5,2,9,2,7 };
	int size = sizeof(arr) / sizeof(arr[0]);
	mergeSort(arr, size);
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	return 0;
}

