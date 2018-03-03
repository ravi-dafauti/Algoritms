#include<iostream>
using namespace std;

void insertionSort(int arr[], int n)
{
	for (int i = 1; i < n; i++)
	{
		int temp = arr[i];
		int j;
		for (j = i - 1; j >= 0 && temp < arr[j]; j--)
		{
			arr[j + 1] = arr[j];
		}
		arr[j + 1] = temp;
	}
}
int main()
{
	int arr[] = { 1,5,2,9,2,7 };
	int size = sizeof(arr) / sizeof(arr[0]);
	insertionSort(arr, size);
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	return 0;
}