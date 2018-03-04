#include<iostream>
using namespace std;

void countingSort(int arr[], int n, int k)
{
	int *count = new int[k];
	int *temp = new int[n];
	for (int i = 0; i < k; i++)
		count[i] = 0;
	for (int i = 0; i < n; i++)
		count[arr[i]]++;
	for (int i = 1; i < k; i++)
		count[i] += count[i - 1];
	for (int i = n - 1; i >= 0; i--)
	{
		temp[count[arr[i]] - 1] = arr[i];
		count[arr[i]]--;
	}
	for (int i = 0; i < n; i++)
		arr[i] = temp[i];
	delete[] temp;
}
int main()
{
	int arr[] = { 1,5,2,9,2,7 };
	int b[100];
	int size = sizeof(arr) / sizeof(arr[0]);
	countingSort(arr, size, 10);
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	return 0;
}