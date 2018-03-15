/*
Write a program that, given an array A[] of n numbers find two numbers whose sum is closest to zero
eg. 1,20,-10,70,-80,85
output: -80 and 85 
*/
#include<iostream>
using namespace std;

#define MAX 999999
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

int abs(int a)
{
	if (a < 0)
		return -a;
	return a;
}
void findTwoNumbersSumCloseToZero(int arr[], int n)
{
	quickSort(arr, 0, n - 1);
	int close = MAX;
	int i, j;
	int curr_close;
	int closei, closej;
	for (i = 0, j = n - 1; i < j;)
	{
		if (arr[i] + arr[j] > 0)
		{
			if (arr[i] + arr[j] < close)
			{
				close = arr[i] + arr[j];
				closei = i;
				closej = j;
			}
			j--;
		}
		else if (arr[i] + arr[j] < 0)
		{
			if (abs(arr[i] + arr[j]) < close)
			{
				close = abs(arr[i] + arr[j]);
				closei = i;
				closej = j;
			}
			i++;
		}
		else if(arr[i] + arr[j] == 0)
		{
			closei = i;
			closej = j;
			break;
		}
	}
	cout << arr[closei] << " " << arr[closej];
}
int main()
{
	int A[] = { 1,20,-10,70,-80,85 };
	int arr_size = 6;
	findTwoNumbersSumCloseToZero(A, arr_size);
	return 0;
}