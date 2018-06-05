/*
Median of two sorted arrays of different sizes

*/
#include<iostream>
using namespace std;

int min(int a, int b)
{
	if (a < b)
		return a;
	return b;
}

int max(int a, int b)
{
	if (a > b)
		return a;
	return b;
}
int findMedian(int A[], int N, int B[], int M)
{
	if (N > M)
		return findMedian(B, M, A, N);
	int low = 0;
	int high = N;
	int partX;
	int partY;
	while (low <= high)
	{
		partX = (low + high) / 2;
		partY = (N + M + 1) / 2 - partX;

		int minpartx = (partX == 0 ? INT_MIN : A[partX - 1]);
		int maxpartx = (partX == N ? INT_MAX : A[partX]);

		int minparty = (partY == 0 ? INT_MIN : B[partY - 1]);
		int maxparty = (partY == M ? INT_MAX : B[partY]);

		if (minpartx <= maxparty&&minparty <= maxpartx)
		{
			if ((N + M) % 2 == 0)
			{
				return (max(minpartx, minparty) + min(maxpartx, maxparty)) / 2;
			}
			else
				return max(minpartx, minparty);
		}
		else if (minpartx > maxparty)
		{
			high = partX - 1;
		}
		else
		{
			low = partX + 1;
		}
	}
}
int main()
{
	int A[] = { 4,6,7,10,11,13 };
	int B[] = { 1,3,20,31 };

	int N = sizeof(A) / sizeof(A[0]);
	int M = sizeof(B) / sizeof(B[0]);

	cout << findMedian(A, N, B, M);
    return 0;
}

