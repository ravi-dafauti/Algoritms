/*
Given a binary number as input, we need to write a program to convert the given binary number into equivalent decimal number.

Examples:

Input : 111
Output : 7

Input : 1010
Output : 10

Input: 100001
Output: 33
*/

#include<iostream>
using namespace std;

int binaryToDecimal(int number)
{
	static int base = 1;
	if (number == 0)
		return 0;
	int ans = number % 10 * base;
	number /= 10;
	base *= 2;
	return ans + binaryToDecimal(number);
}
int main()
{
	int num = 10101001;
	cout << binaryToDecimal(num);
    return 0;
}