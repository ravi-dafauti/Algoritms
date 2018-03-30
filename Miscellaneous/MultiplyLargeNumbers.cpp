/*
Given two numbers as strings. The numbers may be very large (may not fit in long long int), the task is to find sum of these two numbers.

Examples:

Input : num1 = 4154
num2 = 51454
Output : 213779916

Input :  num1 = 654154154151454545415415454
num2 = 63516561563156316545145146514654
Output : 41549622603955309777243716069997997007620439937711509062916
*/

#include<iostream>
#include<vector>
#include<string>
using namespace std;
string multiply(string str1, string str2)
{
	int len1 = str1.length();
	int len2 = str2.length();
	if (len1 == 0 || len2 == 0)
		return "0";
	vector<int> res(len1 + len2, 0);
	int carry;
	int x, y;
	x = y = 0;
	for (int i = len1 - 1; i >= 0; i--)
	{
		int n1 = str1[i] - '0';
		y = 0;
		carry = 0;
		for (int j = len2 - 1; j >= 0; j--)
		{
			int n2 = str2[j] - '0';
			int sum = (n2*n1) + res[x + y] + carry;
			carry = sum / 10;
			res[x + y] = sum % 10;
			y++;
		}
		if (carry > 0)
			res[x + y] += carry;
		x++;
	}
	int i = res.size() - 1;
	while (i >= 0 && res[i] == 0)
		i--;
	if (i == -1)
		return "0";
	string ans = "";
	while (i >= 0)
	{
		ans += to_string(res[i]);
		i--;
	}
	return ans;
}
int main()
{
	string str1 = "1235421415454545454545454544";
	string str2 = "1714546546546545454544548544544545";
	cout << multiply(str1, str2);
    return 0;
}

