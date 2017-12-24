// SubsetSum.cpp : Defines the entry point for the console application.
//

#include<stdio.h>
#include<stdlib.h>

int visited[100] = { 0 };
// qsort compare function
int comparator(const void *pLhs, const void *pRhs)
{
	int *lhs = (int *)pLhs;
	int *rhs = (int *)pRhs;

	return *lhs > *rhs;
}

void printSol(int s[], int size)
{
	for (int i = 0; i < size; i++)
	{
		if (visited[i] == 1)
		{
			printf("%d ", s[i]);
		}
	}
	printf("\n");
}
void subsetRecur(int s[], int size, int index, int curr_sum, int target)
{
	if (index == size)
	{
		return;
	}
	if (curr_sum == target)
	{
		printSol(s, size);
		return;
	}

		if (curr_sum +s[index] <= target)
		{
			visited[index] = 1;
			subsetRecur(s, size, index + 1, curr_sum + s[index], target);
		}
		visited[index] = 0;
		subsetRecur(s, size, index + 1, curr_sum, target);
}
void generateSubsets(int s[], int size, int target_sum)
{
	int total = 0;

	// sort the set
	qsort(s, size, sizeof(int), &comparator);

	for (int i = 0; i < size; i++)
	{
		total += s[i];
	}

	subsetRecur(s, size, 0, 0, target_sum);
}
int main()
{
	int weights[] = { 15, 22, 14, 26, 32, 9, 16, 8 };
	int target = 53;

	int size = sizeof(weights) / sizeof(int);

	generateSubsets(weights, size, target);

    return 0;
}

