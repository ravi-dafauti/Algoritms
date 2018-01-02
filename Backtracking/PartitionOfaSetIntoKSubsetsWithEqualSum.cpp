// PartitionOfaSetIntoKSubsetsWithEqualSum.cpp : Defines the entry point for the console application.
//
/*Given an integer array of N elements, the task is to divide this array into K non-empty subsets such that the sum of elements in every subset is same. All elements of this array should be part of exactly one partition.*/

#include<iostream>
using namespace std;

bool recur(int arr[], int partarr[], int vis[], int N, int K, int index, int subsetsum, int size)
{
	if (subsetsum == partarr[index])
	{
		if (index == K-2 )
			return true;
		else
			return recur(arr, partarr, vis, size - 1, K, index + 1, subsetsum, size);
	}

	for (int i = N; i >= 0; i--)
	{
		if (vis[i])
			continue;

		if (subsetsum - (partarr[index]+arr[i]) >= 0)
		{
			vis[i] = 1;
			partarr[index] = partarr[index] + arr[i];
			if (recur(arr, partarr, vis, i - 1, K, index, subsetsum, size))
			{
				return true;
			}
			vis[i] = 0;
			partarr[index] = partarr[index] - arr[i];
		}
	}
	return false;
}
bool isKPartitionPossible(int arr[], int size, int totalSubset)
{

	if (totalSubset == 1)
		return true;
	if (totalSubset > size)
		return false;

	int sum = 0;
	for (int i = 0; i < size; i++)
	{
		sum += arr[i];
	}

	if (sum%totalSubset != 0)
	{
		return false;
	}
	int *subsetarr = (int *)malloc(sizeof(int)*totalSubset);
	int *visited = (int *)malloc(sizeof(int)*size);
	for (int i = 0; i < totalSubset; i++)
		subsetarr[i] = 0;
	for (int i = 0; i < size; i++)
		visited[i] = 0;
	visited[size - 1] = 1;
	subsetarr[0] = arr[size - 1];
	return recur(arr, subsetarr, visited, size - 1, totalSubset, 0, sum / totalSubset, size);
}

int main()
{
	int arr[] = { 2, 1, 4, 5, 3, 3 };
	int N = sizeof(arr) / sizeof(arr[0]);
	int K = 3;

	if (isKPartitionPossible(arr, N, K))
		cout << "Partitions into equal sum is possible.\n";
	else
		cout << "Partitions into equal sum is not possible.\n";
	return 0;
}

