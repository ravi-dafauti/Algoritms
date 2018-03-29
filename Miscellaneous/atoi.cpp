/*
The atoi() function takes a string (which represents an integer) as an argument and returns its value.
*/

#include<iostream>
using namespace std;

int myAtoi(char *str)
{
	int n = 0;
	if (str[0] == '-')
		n = 1;
	int number = 0;
	int base = 1;
	for (int i = strlen(str) - 1; i >= n; i--)
	{
		number += base*(str[i] - '0');
		base *= 10;
	}
	if (n == 1)
		return -1 * number;
	return number;
}
int main()
{
	char str[] = "-123";
	int val = myAtoi(str);
	cout << val;
	return 0;
}

