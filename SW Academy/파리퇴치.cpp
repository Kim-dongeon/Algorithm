#include <iostream>
#include <algorithm>
using namespace std;

int map[16][16];


int main()
{
	int T;
	cin >> T;

	for (int t = 0; t < T; t++)
	{
		int N, M;
		cin >> N >> M;
		int _max = 0;
		int sum = 0;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				scanf("%d", &map[i][j]);
			}
		}

		for (int x = 0; x < N - M + 1; x++)
		{
			for (int y = 0; y < N - M + 1; y++)
			{
				for (int i = 0; i < M; i++)
				{
					for (int j = 0; j < M; j++)
					{
						sum += map[i+x][j+y];
					}
				}
				_max = max(_max, sum);
				sum = 0;
			}
		}
			
		printf("#%d %d\n", t + 1, _max);

	}
}