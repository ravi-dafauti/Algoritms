/*
Write an efficient program to count number of 1s in binary representation of an integer.

Examples

Input : n = 6
Output : 2
Binary representation of 6 is 110 and has 2 set bits

Input : n = 13
Output : 3
Binary representation of 11 is 1101 and has 3 set bits
*/

#include<iostream>
using namespace std;

int countSetBits(int n)
{
	if (n == 0)
		return 0;
	return 1 + countSetBits(n&(n - 1));
}
int main()
{
	int i = 9;
	cout << countSetBits(i);
    return 0;
}

