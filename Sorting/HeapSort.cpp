#include<iostream>
using namespace std;

class PriorityQueue
{
	int *arr;
	int size;
	int count;
	int leftChild(int);
	int rightChild(int);
	int parent(int);
	void percolateDown(int i);
	void heapify();

public:
	PriorityQueue(int arr[], int);
	void copy(int carr[]);
	void heapSort();
};

void PriorityQueue::copy(int carr[])
{
	for (int i = 0; i < count; i++)
	{
		carr[i] = arr[i];
	}
}
void PriorityQueue::heapSort()
{
	for (int i = count-1; i >= 0; i--)
	{
		int temp = arr[i];
		arr[i] = arr[0];
		arr[0] = temp;
		count--;
		percolateDown(0);
	}
	count = size;
}

void PriorityQueue::heapify()
{
	for (int i = (count - 1) / 2; i >= 0; i--)
	{
		percolateDown(i);
	}
}

PriorityQueue::PriorityQueue(int array[], int size)
{
	this->size = size;
	arr = (int*)malloc(sizeof(int)*size);
	for (int i = 0; i < size; i++)
	{
		arr[i] = array[i];
	}
	count = size;
	heapify();
}
int PriorityQueue::parent(int i)
{
	if (i == 0)
		return -1;
	if (i < count && (i - 1) / 2 >= 0)
	{
		return (i - 1) / 2;
	}
	return -1;
}
int PriorityQueue::leftChild(int i)
{
	if (i < count && 2 * i + 1 < count)
	{
		return 2 * i + 1;
	}
	return -1;
}
void PriorityQueue::percolateDown(int i)
{
	if (i >= count)
		return;
	int l = leftChild(i);
	int r = rightChild(i);
	int max = i;
	if (l != -1 && arr[l] > arr[max])
	{
		max = l;
	}
	if (r != -1 && arr[r] > arr[max])
	{
		max = r;
	}
	if (max != i)
	{
		int temp = arr[max];
		arr[max] = arr[i];
		arr[i] = temp;
		percolateDown(max);
	}
}
int PriorityQueue::rightChild(int i)
{
	if (i < count && 2 * i + 2 < count)
	{
		return 2 * i + 2;
	}
	return -1;
}

void heapSort(int arr[], int size)
{
	PriorityQueue q(arr, size);
	q.heapSort();
	q.copy(arr);
}
int main()
{
	int arr[] = { 1,5,9,2,3 };
	int size = sizeof(arr) / sizeof(arr[0]);
	heapSort(arr, size);
	for (int i = 0; i < size; i++)
		cout << arr[i] << " ";
	return 0;
}