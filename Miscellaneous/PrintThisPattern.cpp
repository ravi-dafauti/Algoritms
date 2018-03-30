/*
Given an integer n, you need to print the following pattern pattern.

n=4
Output :
4444444
4333334
4322234
4321234
4322234
4333334
4444444

n=3
Output :
33333
32223
32123
32223
33333


Input:
The first line of the input contains a single integer T, denoting the number of test cases. Then T test cases follow. Each test case contains one lines of input denoting the value of n.

Output:
For each test case, Print the mentioned pattern.

Constraints:
1<=T<=100
1<=N<=9

Example:

Input:
2
3
4

Output:
33333
32223
32123
33333
4444444
4333334
4322234
4321234
4322234
4333334
4444444
*/

#include<iostream>
using namespace std;
void printUtil(int arr[], int n, int i)
{
	if (i <= (2 * n - 1) / 2)
	{
		if (i == 0)
		{
			for (int j = 0; j < n * 2 - 1; j++)
				cout << arr[j];
			cout << "\n";
		}
		else
		{
			for (int j = 0; j < 2 * n - 1; j++)
			{
				if (j >= i&&j <= (2 * n - 2) - i)
				{
					arr[j] -= 1;
					cout << arr[j];
				}
				else
					cout << arr[j];
			}
			cout << "\n";
		}
		if (i == (n * 2 - 1) / 2)
			return;
		printUtil(arr, n, i + 1);
		for (int j = 0; j < 2 * n - 1; j++)
		{
			if (j >= (i + 1) && j <= (2 * n - 2) - (i + 1))
			{
				arr[j] += 1;
				cout << arr[j];
			}
			else
				cout << arr[j];
		}
		cout << "\n";
	}

}
void printPattern(int n)
{
	int *arr = new int[n * 2 - 1];
	for (int i = 0; i < n * 2 - 1; i++)
		arr[i] = n;
	printUtil(arr, n, 0);
}
int main()
{
	int TestCase;
	cin >> TestCase;
	int n;
	while (TestCase)
	{
		cin >> n;
		printPattern(n);
		TestCase--;
	}
    return 0;
}

