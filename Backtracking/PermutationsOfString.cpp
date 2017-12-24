// PermutationsOfString.cpp : Defines the entry point for the console application.
//

#include<stdio.h>
#include<string.h>

int visited[100] = { 0 };
char sol[100];
void permutation(char *str, int index, int n)
{
	if (index == n)
	{
		for (int i = 0; i < n; i++)
		{
			printf("%c", sol[i]);
		}
		printf("\n");
		return;
	}
	for (int i = 0; i < n; i++)
	{
		if (visited[i] == 1)
			continue;
		visited[i] = 1;
		sol[index] = str[i];
		permutation(str, index + 1, n);
		visited[i] = 0;
	}
}
int main()
{
	char str[] = "ABC";
	int n = strlen(str);
	permutation(str, 0, n);
    return 0;
}

