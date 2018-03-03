#include<iostream>
using namespace std;

void swap(int &a, int &b)
{
	a = a + b;
	b = a - b;
	a = a - b;
}
void selectionSort(int arr[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int min = i;
		for (int j = i + 1; j < n; j++)
		{
			if (arr[j] < arr[min])
				min = j;
		}
		if (min != i)
			swap(arr[i], arr[min]);
	}
}
int main()
{
	int arr[] = { 1,5,2,9,2,7 };
	int size = sizeof(arr) / sizeof(arr[0]);
	selectionSort(arr, size);
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	return 0;
}