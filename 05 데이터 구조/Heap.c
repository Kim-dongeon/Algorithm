#include <stdio.h>
int data[20] = { 0,6,3,5,7,10,1,2 };

void printArr(int arr[], int sz)
{
	for (int i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n------------------------\n");
}
void swap(int i, int j)
{
	int temp = data[i];
	data[i] = data[j];
	data[j] = temp;
}
void findLocation(int cur_idx, int lastidx)
{
	int leftidx = cur_idx * 2;
	int rightidx = leftidx + 1;
	int biggest=cur_idx;

	if (leftidx <= lastidx && data[leftidx] > data[cur_idx])
	{
		biggest = leftidx;
	}
	if (rightidx <= lastidx && data[rightidx] > data[biggest])
	{
		biggest = rightidx;
	}

	if (biggest == cur_idx)
	{
		return;
	}
	else
	{
		swap(cur_idx, biggest);
		findLocation(biggest,lastidx);
	}
}
void heapify(int lastidx)
{
	int cur_idx = lastidx / 2;

	while (cur_idx>=1)
	{
		findLocation(cur_idx, lastidx);
		cur_idx--;
	}
}
void addToHeap(int value, int lastIdx)
{
	int cur_idx = lastIdx + 1;
	int parent_idx = cur_idx / 2;

	data[cur_idx] = value;
	while (1)
	{
		if (data[parent_idx] > data[cur_idx])
		{
			return;
		}
		else
		{
			swap(parent_idx, cur_idx);
			cur_idx = parent_idx;
			parent_idx = cur_idx / 2;
			if (parent_idx < 1)
			{
				return;
			}
		}
	}
}
int removeRoot(int lastIdx)
{
	int retVal = data[1];
	data[1] = data[lastIdx];
	data[lastIdx] = 0;
	findLocation(1, lastIdx - 1);
	return retVal;
}
int main()
{
	int k = 0;
	printf("Before heapify : %d\n", data[1]);
	heapify(7);
	printf("After heapify : %d\n", data[1]);
	printArr(data, 8);

	addToHeap(30, 7);
	printf("After adding : %d\n", data[1]);
	printArr(data, 9);


	k = removeRoot(8);
	printf("%d \n", k);
	printArr(data, 10);
	return 0;
}