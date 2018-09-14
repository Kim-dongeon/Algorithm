#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int T;
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		int N;
		cin >> N;
		vector<vector<int>> map(N,vector<int>(N));
		vector<vector<int>> map90(N, vector<int>(N));
		vector<vector<int>> map180(N, vector<int>(N));
		vector<vector<int>> map270(N, vector<int>(N));
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				scanf("%d", &map[i][j]);
			}
		}

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				map90[i][j] = map[N - 1 - j][i];
				map180[i][j] = map[N-1-i][N-1-j];
				map270[i][j] = map[j][N - 1 - i];
			}		
		}

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				printf("%d", map90[i][j]);
			}
			printf(" ");
			for (int j = 0; j < N; j++)
			{
				printf("%d", map180[i][j]);
			}
			printf(" ");
			for (int j = 0; j < N; j++)
			{
				printf("%d", map270[i][j]);
			}

			printf("\n");
		}
	}
}