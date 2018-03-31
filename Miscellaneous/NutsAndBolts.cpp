/*
Given a set of N nuts of different sizes and N bolts of different sizes. There is a one-one mapping between nuts and bolts. Match nuts and bolts efficiently.

Comparison of a nut to another nut or a bolt to another bolt is not allowed. It means nut can only be compared with bolt and bolt can only be compared with nut to see which one is bigger/smaller.

Input:

The first line contains 'T' denoting the number of testcases. Then follows description of T testcases:
Each case begins with a single positive integer N denoting the number of nuts/bolts.

Then follows the array of nuts, each element separated by a space.

And finally the bolts array, again, each element is separated by a space here.

Array of Nuts/Bolts can only consist of the following elements:

{'@', '#', '$', '%', '^', '&', '~', '*', '!'}

And no element can be repeated.


Output:

For each test case, output the matched array of nuts and bolts in separate lines, where each element in the array is separated by a space. Print the elements in the following order ! # $ % & * @ ^ ~


Constraints:

1<= T <= 70
1<= N <= 9


Example:

Input:

2
5
@ % $ # ^
% @ # $ ^
9
^ & % @ # * $ ~ !
~ # @ % & * $ ^ !

Output:

# $ % @ ^
# $ % @ ^
! # $ % & * @ ^ ~
​! # $ % & * @ ^ ~
*/

#include<iostream>
using namespace std;

int partition(char nuts[], char bolts[], int l, int h, int pivot)
{
	int part = l - 1;
	int index = -1;
	for (int i = l; i <= h; i++)
	{
		if (bolts[i] < nuts[pivot])
		{
			part++;
			if (index != -1 && pivot == index)
				index = i;
			int temp = bolts[i];
			bolts[i] = bolts[part];
			bolts[part] = temp;
		}
		if (bolts[i] == nuts[pivot])
			index = i;
	}
	part++;
	int temp = bolts[index];
	bolts[index] = bolts[part];
	bolts[part] = temp;
	return part;
}
void sortNB(char nuts[], char bolts[], int l, int h)
{
	if (l < h)
	{
		int partb = partition(bolts, nuts, l, h, h);
		int partn = partition(nuts, bolts, l, h, partb);
		sortNB(nuts, bolts, l, partb - 1);
		sortNB(nuts, bolts, partb + 1, h);
	}
}
int main()
{
	int t;
	cin >> t;
	int n;
	char nuts[12];
	char bolts[12];
	while (t)
	{
		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> nuts[i];
		for (int i = 0; i < n; i++)
			cin >> bolts[i];
		sortNB(nuts, bolts, 0, n - 1);
		for (int i = 0; i < n; i++)
			cout << nuts[i] << " ";
		cout << "\n";
		for (int i = 0; i < n; i++)
			cout << bolts[i] << " ";
		cout << "\n";
		t--;
	}
    return 0;
}

