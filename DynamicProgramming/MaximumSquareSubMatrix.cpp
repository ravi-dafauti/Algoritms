/*Given a binary matrix, find out the maximum size square sub-matrix with all 1s.*/
#include<iostream>
using namespace std;

#define R 6
#define C 5

int min(int a, int b, int c)
{
	int min;
	if (a < b)
		min = a;
	else
		min = b;
	if (c < min)
		min = c;
	return min;
}
void printMaxSubSquare(int M[R][C])
{
	int **table = (int **)malloc(sizeof(int)*(R + 1));
	for (int i = 0; i <= R; i++)
		table[i] = (int *)malloc(sizeof(int)*(C + 1));
	for (int i = 0; i <= C; i++)
		table[0][i] = 0;
	for (int i = 0; i <= R; i++)
		table[i][0] = 0;
	int max = 0;
	int x, y;
	for (int i = 1; i <= R; i++)
	{
		for (int j = 1; j <= C; j++)
		{
			if (M[i - 1][j - 1] == 0)
				table[i][j] = 0;
			else
			{
				table[i][j] = min(table[i - 1][j], table[i][j - 1], table[i - 1][j - 1]) + 1;
				if (max < table[i][j])
				{
					max = table[i][j];
					x = i - 1;
					y = j - 1;
				}
					
			}
		}
	}
	cout << "indexs of submatrix start" << x - (max - 1) << "," << y - (max - 1) << "\n";
	cout << "indexs of submatrix end" << x  << "," << y  << "\n";
	for (int i = 0; i < max; i++)
	{
		for (int j = 0; j < max; j++)
		{
			cout << "1" << " ";
		}
		cout << "\n";
	}
}
int main()
{
	int M[R][C] = { { 0, 1, 1, 0, 1 },
	{ 1, 1, 0, 1, 0 },
	{ 0, 1, 1, 1, 0 },
	{ 1, 1, 1, 1, 0 },
	{ 1, 1, 1, 1, 1 },
	{ 0, 0, 0, 0, 0 } };

	printMaxSubSquare(M);
    return 0;
}

