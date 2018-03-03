#include<iostream>
using namespace std;

void swap(int &a, int &b)
{
	a = a + b;
	b = a - b;
	a = a - b;
}
void bubbleSort(int arr[], int n)
{
	int flag = 1;
	for (int i = 0;flag && i < n-1; i++)
	{
		flag = 0;
		for (int j = 0; j < n - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				flag = 1;
				swap(arr[j], arr[j + 1]);
			}
		}
	}
}
int main()
{
	int arr[] = { 1,5,2,9,2,7 };
	int size = sizeof(arr) / sizeof(arr[0]);
	bubbleSort(arr, size);
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	return 0;
}