#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	int N;
	cin >> N;

	int num = 2 * N - 1;
	int w = 0;
	int mid = num / 2;
	int left = 0, right = 0;
	for (int i = 0; i < N; i++)
	{	
		left = mid - w;
		right = mid + w;
		for (int j = 0; j < num; j++)
		{
			if (i == N / 2)
			{
				if (j >= left && j <= right)
				{
					printf("*");
				}
				else
				{
					printf(" ");
				}
			}
			else {
				if (j == left || j == right)
				{
					printf("*");
				}
				else
				{
					printf(" ");
				}
			}
		}
		printf("\n");
		w++;
	}
}