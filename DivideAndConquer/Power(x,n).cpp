/*
Given two integers x and n, write a function to compute xn. We may assume that x and n are small and overflow doesn’t happen.

Input : x = 2, n = 3
Output : 8

Input : x = 7, n = 2
Output : 49
*/
#include<iostream>
using namespace std;

float power(float x, int y)
{
	if (y == 0)
		return 1;
	if (y % 2 == 0)
	{
		float temp = power(x, y / 2);
		return temp*temp;
	}
	else
	{
		if (y > 0)
			return x*power(x, y - 1);
		else
			return power(x, y + 1) / x;
	}
}

int main()
{

	float x = 2;
	int y = -3;
	cout << power(x, y);
	return 0;
}

