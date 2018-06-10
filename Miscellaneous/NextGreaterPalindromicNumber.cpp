/*
Given a number, find the next smallest palindrome larger than this number. For example, if the input number is “2 3 5 4 5”, the output should be “2 3 6 3 2”. And if the input number is “9 9 9”, the output should be “1 0 0 1”.

The input is assumed to be an array. Every entry in array represents a digit in input number. Let the array be ‘num[]’ and size of array be ‘n’

There can be three different types of inputs that need to be handled separately.
1) The input number is palindrome and has all 9s. For example “9 9 9”. Output should be “1 0 0 1”
2) The input number is not palindrome. For example “1 2 3 4”. Output should be “1 3 3 1”
3) The input number is palindrome and doesn’t have all 9s. For example “1 2 2 1”. Output should be “1 3 3 1”.
*/
#include<iostream>
using namespace std;

void printArray(int arr[], int n);

void generateNextPalindromeUtil(int num[], int n)
{
	int mid = n / 2;
	int i, j;
	bool addition_required = false;
	i = mid - 1;
	if (n % 2 == 0)
		j = mid;
	else
		j = mid + 1;
	
	while (i >= 0 && num[i] == num[j])
	{
		i--;
		j++;
	}
	if (i < 0 || num[i] < num[j])
		addition_required = true;

	while (i >= 0)
	{
		num[j] = num[i];
		j++;
		i--;
	}

	if (addition_required)
	{
		i = mid - 1;
		int carry = 1;
		if (n % 2 == 1)
		{
			num[mid] += carry;
			carry = num[mid] / 10;
			num[mid] = num[mid] % 10;
			j = mid + 1;
		}
		else
			j = mid;
		while (i >= 0)
		{
			num[i] += carry;
			carry = num[i] / 10;
			num[i] = num[i] % 10;
			num[j++] = num[i--];
		}
	}
}

// A utility function to check if num has all 9s
int AreAll9s(int* num, int n)
{
	int i;
	for (i = 0; i < n; ++i)
		if (num[i] != 9)
			return 0;
	return 1;
}
// The function that prints next palindrome of a given number num[]
// with n digits.
void generateNextPalindrome(int num[], int n)
{
	int i;

	printf("nNext palindrome is:n");

	// Input type 1: All the digits are 9, simply o/p 1
	// followed by n-1 0's followed by 1.
	if (AreAll9s(num, n))
	{
		printf("1 ");
		for (i = 1; i < n; i++)
			printf("0 ");
		printf("1");
	}

	// Input type 2 and 3
	else
	{
		generateNextPalindromeUtil(num, n);

		// print the result
		printArray(num, n);
	}
}



/* Utility that prints out an array on a line */
void printArray(int arr[], int n)
{
	int i;
	for (i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("n");
}

// Driver Program to test above function
int main()
{
	int num[] = { 9, 4, 1, 8, 7, 9, 7, 8, 3, 2, 2 };

	int n = sizeof(num) / sizeof(num[0]);

	generateNextPalindrome(num, n);

	return 0;
}

