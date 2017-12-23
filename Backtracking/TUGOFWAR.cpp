// TUGOFWAR.cpp : Defines the entry point for the console application.
#include<stdio.h>

int visited[100] = { 0 };
int solution[100] = { 0 };
int minimum = 999999;
int abs(int a)
{
	if (a < 0)
	{
		return -a;
	}
	return a;
}
void tugOfWarRecur(int arr[], int size, int index, int no_of_selected_elements, int sum, int remaining_sum)
{
	if (index == size)
	{
		if (no_of_selected_elements == size / 2)
		{
			if (minimum > abs(sum - remaining_sum))
			{
				minimum = abs(sum - remaining_sum);
				for (int i = 0; i < size; i++)
				{
					solution[i] = visited[i];
				}
			}

		}
		return;
	}
	visited[index] = 0;
	tugOfWarRecur(arr, size, index + 1, no_of_selected_elements, sum, remaining_sum);
	visited[index] = 1;
	tugOfWarRecur(arr, size, index + 1, no_of_selected_elements + 1, sum + arr[index], remaining_sum - arr[index]);
}
void tugOfWar(int arr[], int size)
{
	int sum = 0;
	for (int i = 0; i < size; i++)
	{
		sum += arr[i];
	}
	tugOfWarRecur(arr, size, 0, 0, 0, sum);
}

void printSol(int arr[],int n)
{
	printf("the two sets are\n");
	for (int i = 0; i < n; i++)
	{
		if (solution[i] == 1)
		{
			printf("%d ", arr[i]);
		}
	}
	printf("\n");
	for (int i = 0; i < n; i++)
	{
		if (solution[i] == 0)
		{
			printf("%d ", arr[i]);
		}
	}
}
int main()
{
	int arr[] = { 23, 45, -34, 12, 0, 98, -99, 4, 189, -1, 4 };
	int n = sizeof(arr) / sizeof(arr[0]);
	tugOfWar(arr, n);
	printSol(arr,n);
	printf("\n");
	printf("%d", minimum);
	return 0;
    return 0;
}

