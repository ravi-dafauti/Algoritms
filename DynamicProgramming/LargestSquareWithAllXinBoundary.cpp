/* given a matrix of O and 1 find the largest Square with all X in boundary*/

/*
Find maximum subsquare in a matrix made up of 1s and Os such that all four sides of subsquare are 1s. It does not matter what is inside
* the subsquare. All 4 sides should be made up entirely of 1s
*
* e.g
* 0 0 0 0 0 1         0,0  0,0  0,0  0,0  0,0  1,1
* 0 1 0 1 1 1         0,0  1,1  0,0  1,1  1,2  2,3
* 0 1 0 1 0 1         0,0  2,1  0,0  2,1  0,0  3,1
* 0 1 1 1 1 1         0,0  3,1  1,2  3,3  1,4  4,5
* 0 0 0 0 0 0         0,0  0,0  0,0  0,0  0,0  0,0
*
* Output of above program should be 3
*
* Solution
* Have another matrix which is capable of holding 2 values hori and ver.
* Ver stores how far vertically you can see 1s. Hori stores how far horizontally you can see 1s.
* Once this matrix is build look for biggest subsquare by getting min of hori and ver at each point and checking
* if subsquare can be formed from value min to 1.
*
* Test cases:
* Matrix entirely made up of 1s
* Matrix entirely made up of Os
* Matrix with Xs and Os but maximum subsquare is length 1
*/
#include<iostream>
using namespace std;
#define R 5
#define C 5
int min(int a, int b)
{
	if (a < b)
		return a;
	return b;
}
int maximumSquare(int arr[R][C])
{
	pair<int,int> **table = (pair<int,int> **)malloc(sizeof(int)*(R));
	for (int i = 0; i < R; i++)
		table[i] = (pair<int,int> *)malloc(sizeof(pair<int,int>)*C);
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			if (arr[i][j] == 0)
			{
				table[i][j].first = 0;
				table[i][j].second = 0;
			}
			else
			{
				if (i - 1 >= 0)
					table[i][j].second = table[i - 1][j].second + 1;
				else
					table[i][j].second = 1;
				if (j - 1 >= 0)
					table[i][j].first = table[i][j - 1].first + 1;
				else
					table[i][j].first = 1;
			}
		}
	}
	int max = 0;

	//start iterating from bottom right corner and find min of hori or ver at every cell.
	//If this is greater than 1 then see if you can find a number between this min and 1
	//such that on left's ver and top's hori is greater greater than or equal to k.
	for (int i = R - 1; i >= 0; i--)
	{
		for (int j = C - 1; j >= 0; j--)
		{
			int temp = min(table[i][j].first, table[i][j].second);
			int curr_max = 0;
			for (int k = temp; k > 1; k--)
			{
				int x = i - k + 1;
				int y = j - k + 1;
				if (table[x][j].first >= k && table[i][y].second >= k)
				{
					curr_max = k;
					break;
				}
			}
			if (curr_max > max)
				max = curr_max;
		}
	}
	return max;
}
int main()
{
	int A[R][C] = {{0,0,0,0,1},
	{1,1,1,1,1},
	{1,1,0,0,1},
	{1,1,0,0,1},
	{0,1,1,1,1}
	};
	cout << "maximum size square with all 1's in boundary is : " << maximumSquare(A);
	return 0;
}