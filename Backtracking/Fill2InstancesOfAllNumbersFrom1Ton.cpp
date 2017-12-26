// Fill2InstancesOfAllNumbersFrom1Ton.cpp : Defines the entry point for the console application.
//

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h>

int isPlacementPossible(int arr[], int n, int pos, int number)
{
	if (arr[pos] == 0 && pos + number + 1 < 2 * n && arr[pos + number + 1] == 0)
	{
		return 1;
	}
	return 0;
}
int fillRecur(int arr[], int n, int number)
{
	if (number == n + 1)
	{
		return 1;
	}
	for (int i = 0; i < 2 * n; i++)
	{
		if (isPlacementPossible(arr, n, i, number))
		{
			arr[i] = number;
			arr[i + number + 1] = number;
			if (fillRecur(arr, n, number + 1))
			{
				return 1;
			}
			arr[i] = 0;
			arr[i + number + 1] = 0;
		}
	}
	return 0;
}

void printSol(int arr[], int n)
{
	for (int i = 0; i < 2 * n; i++)
	{
		printf("%d ", arr[i]);
	}
}
void fillInstance(int n)
{
	int *arr = (int*)malloc(sizeof(int)* 2 * n);
	for (int i = 0; i < 2 * n; i++)
	{
		arr[i] = 0;
	}
	if (fillRecur(arr, n, 1))
	{
		printSol(arr, n);
	}
	else
	{
		printf("solution does not exists\n");
	}
}
int main()
{
	fillInstance(7);
	return 0;
}
