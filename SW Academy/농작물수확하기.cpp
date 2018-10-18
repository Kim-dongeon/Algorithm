#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

int main()
{
	int T;
	cin >> T;

	for (int t = 0; t < T; t++)
	{
		int N;
		cin >> N;
		vector<vector<int>> farm(N, vector<int>(N));

		for (int i = 0; i < N; i++)
		{
			for (int j = 0;j < N; j++)
			{
				scanf("%1d", &farm[i][j]);
			}
		}
		int sum = 0;
		int start_idx = N / 2;
		int possible = 1;
		int flag = 1;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < possible; j++)
			{
				sum += farm[i][start_idx + j];
			}
			start_idx = start_idx - flag;
			possible = possible + 2 * flag;
			
			if (possible == N)
			{
				flag = -1;
			}
		}
		cout << "#" << t + 1 << ' ' << sum << endl;
	}
}