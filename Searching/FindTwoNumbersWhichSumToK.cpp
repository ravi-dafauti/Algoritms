/*
Write a program that, given an array A[] of n numbers and another number x, 
determines whether or not there exist two elements in S whose sum is exactly x.
*/
#include<iostream>
using namespace std;

void exchange(int *a, int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

int partition(int A[], int si, int ei)
{
	int x = A[ei];
	int i = (si - 1);
	int j;

	for (j = si; j <= ei - 1; j++)
	{
		if (A[j] <= x)
		{
			i++;
			exchange(&A[i], &A[j]);
		}
	}
	exchange(&A[i + 1], &A[ei]);
	return (i + 1);
}

void quickSort(int A[], int si, int ei)
{
	int pi;    /* Partitioning index */
	if (si < ei)
	{
		pi = partition(A, si, ei);
		quickSort(A, si, pi - 1);
		quickSort(A, pi + 1, ei);
	}
}
bool hasArrayTwoCandidates(int arr[], int n, int sum)
{
	quickSort(arr, 0, n - 1);
	int i, j;
	for (i = 0, j = n - 1; i < j;)
	{
		if (arr[i] + arr[j] == sum)
			return true;
		else if (arr[i] + arr[j] < sum)
			i++;
		else
			j--;
	}
	return false;
}
int main()
{
	int A[] = { 1, 4, 45, 6, 10, -8 };
	int n = 16;
	int arr_size = 6;

	if (hasArrayTwoCandidates(A, arr_size, n))
		cout << "Array has two elements with given sum";
	else
		cout << "Array doesn't have two elements with given sum";

	return 0;
}