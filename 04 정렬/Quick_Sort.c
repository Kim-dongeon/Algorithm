#include <stdio.h>

void printArr(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}
void swap(int arr[], int s, int t)
{
	int temp = arr[t];
	arr[t] = arr[s];
	arr[s] = temp;
}
void quick(int arr[], int pivot,int left_idx, int right_idx)
{
	int left = left_idx;
	int right = right_idx;

	while (left < right)
	{
		while (arr[pivot] > arr[left] && left<=right_idx)
		{
			left++;
		}
		while (arr[pivot] < arr[right] && right >= left_idx)
		{
			right--;
		}
		if (right < left)
		{
			swap(arr, pivot, right);
			quick(arr, pivot, pivot + 1, right - 1);
			quick(arr, right + 1, right + 2, right_idx);
		}
		else
		{
			swap(arr, left, right);
		}
	}


}
int main()
{
	int data[10] = {31,24,56,1,4,10,6,76,87,30 };

	printf("-----------------------------------------------\n");
	printf("Before being sorted\n");
	printArr(data, 10);
	printf("-----------------------------------------------\n");

	quick(data, 0,1,9);
	printArr(data, 10);

}