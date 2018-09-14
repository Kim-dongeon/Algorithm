#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> map(16,vector<int>(16));
int main()
{
	int T;
	cin >> T;

	for (int t = 0; t < T; t++)
	{
		int N, K;
		int ans =0;
		cin >> N >> K;
		for (int i = 0; i < N; i++)
		{			
			for (int j = 0; j < N; j++)
			{
				scanf("%d", &map[i][j]);				
			}			
		}

		for (int i = 0; i < N; i++)
		{
			int cnt = 0;
			for (int j = 0; j < N; j++)
			{
				if (map[i][j] == 1)
				{
					cnt++;
				}
				if (map[i][j] == 0 || j == N - 1)
				{
					if (cnt == K)
					{
						ans++;
						cnt = 0;
					}
					else
					{
						cnt = 0;
					}
				}

			}
		}

		for (int j = 0; j < N; j++)
		{
			int cnt = 0;
			for (int i = 0; i < N; i++)
			{
				if (map[i][j] == 1)
				{
					cnt++;
				}
				if (map[i][j] == 0 || i == N - 1)
				{
					if (cnt == K)
					{
						ans++;
						cnt = 0;
					}
					else
					{
						cnt = 0;
					}
				}

			}
		}
		printf("#%d %d\n", t + 1, ans);

	}
}