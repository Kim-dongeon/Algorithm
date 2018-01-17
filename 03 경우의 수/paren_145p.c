#include <stdio.h>

#define L 0
#define R 1

void print_paren(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		if (arr[i] == L)
		{
			printf("(");
		}
		else
		{
			printf(")");
		}
	}
	printf("\n");
}
void paren(int to_open, int to_close, int arr[], int size)
{
	if (to_open == 0 && to_close == 0)
	{
		print_paren(arr, size);
		return;
	}
	if (to_open > 0)
	{
		arr[size] = L;
		paren(to_open - 1, to_close + 1, arr, size + 1);
	}

	if (to_close > 0)
	{
		arr[size] = R;
		paren(to_open, to_close - 1, arr, size + 1);
	}
}

int main()
{
	int arr[100], n;
	scanf("%d", &n);
	paren(n,0,arr,0);
	return 0;
}