/*
Given a set of characters and a positive integer k, print all possible strings of length k that can be formed from the given set.

Examples:

Input:
set[] = {'a', 'b'}, k = 3

Output:
aaa
aab
aba
abb
baa
bab
bba
bbb


Input:
set[] = {'a', 'b', 'c', 'd'}, k = 1
Output:
a
b
c
d
*/
#include<iostream>
using namespace std;
void printAll(char *arr, int k, int n, char *temp, int index)
{
	if (index == n)
	{
		for (int i = 0; i < n; i++)
		{
			cout << temp[i];
		}
		cout << endl;
		return;
	}
	for (int i = 0; i < k; i++)
	{
		temp[index] = arr[i];
		printAll(arr, k, n, temp, index + 1);
	}
}
int main()
{
	char arr[] = { 'a','b' };
	int n = 3;
	char *temp = new char[n];
	printAll(arr, 2, n, temp, 0);
	return 0;
}