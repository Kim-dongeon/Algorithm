#include <iostream>

using namespace std;

int d[11][11];

int main()
{
	int T;
	cin >> T;
	d[1][1] = 1;
	
	for (int t = 0; t < T; t++)
	{
		int N;
		cin >> N;

		for (int i = 2; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				if (i == j || j == 0)
				{
					d[i][j] = 1;
				}
				else
				{
					d[i][j] = d[i - 1][j - 1] + d[i - 1][j];
				}
			}
		}
			printf("#%d\n", t + 1);
			for (int k = 1; k <=N; k++)
			{
				for (int j = 1; j <=k; j++)
				{
					printf("%d ", d[k][j]);
				}
				printf("\n");
			}

		}

}