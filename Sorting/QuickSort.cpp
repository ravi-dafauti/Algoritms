#include<iostream>
using namespace std;

void swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}
int randGenerator(int low, int high)
{
	int n = high - low + 1;
	int number = rand();
	return number%n;
}

int partition(int arr[], int low, int high)
{
	int index = randGenerator(low, high);
	int part = arr[index];
	swap(arr[index], arr[high]);
	int pos = low;
	for (int i = low; i <= high - 1; i++)
	{
		if (arr[i] <= part)
		{
			swap(arr[i], arr[pos]);
			pos++;
		}
	}
	swap(arr[pos], arr[high]);
	return pos;
}
void quickSortUtil(int arr[], int low, int high)
{
	if (low < high)
	{
		int part = partition(arr, low, high);
		quickSortUtil(arr, low, part - 1);
		quickSortUtil(arr, part + 1, high);
	}
}
void quickSort(int arr[], int n)
{
	quickSortUtil(arr, 0, n - 1);
}
int main()
{
	int arr[] = { 1,5,2,9,2,7 };
	int size = sizeof(arr) / sizeof(arr[0]);
	quickSort(arr, size);
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	return 0;
}

