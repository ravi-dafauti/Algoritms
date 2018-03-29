/*
Given an integer, write a function that returns true if the given number is palindrome, else false. 
For example, 12321 is palindrome, but 1451 is not palindrome.
*/

#include<iostream>
using namespace std;

bool isSingleDigit(int n)
{
	if (n / 10 == 0)
		return true;
	return false;
}
bool isPalUtil(int number, int &duplicate)
{
	if (isSingleDigit(number))
	{
		if (number == duplicate % 10)
			return true;
		else
			return false;
	}
	if (!isPalUtil(number / 10, duplicate))
		return false;
	duplicate /= 10;
	return (number % 10 == duplicate % 10);
}
bool isPal(int n)
{
	int duplicate = n;
	return isPalUtil(n, duplicate);
}
int main()
{
	int n = 12321;
	isPal(n) ? cout << "Yes\n" : cout << "No\n";

	n = 12;
	isPal(n) ? cout << "Yes\n" : cout << "No\n";

	n = 88;
	isPal(n) ? cout << "Yes\n" : cout << "No\n";

	n = 8999;
	isPal(n) ? cout << "Yes\n" : cout << "No\n";
    return 0;
}

