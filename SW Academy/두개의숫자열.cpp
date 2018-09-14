#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int T = 0;
	cin >> T;

	for (int t = 0; t < T; t++)
	{
		int N, M;
		cin >> N >> M;
		vector<int> A(N), B(M);
		for (int i = 0; i < N; i++)
		{
			cin >> A[i];
		}
		for (int j = 0; j < M; j++)
		{
			cin >> B[j];
		}
		
		if (N > M)
		{
			vector<int> temp(N);
			temp = A;
			A = B;
			B = temp;
			int tmp = 0;
			tmp = N;
			N = M;
			M = tmp;

		}
					
		int round = M - N + 1;
		int sum = -9999;
		for (int i = 0; i < round; i++)
		{
			int temp = 0;
			for (int j = 0; j < N; j++)
			{
				temp += A[j] * B[j+i];
			}
			sum = max(sum, temp);
		}
		printf("#%d %d\n", t + 1, sum);
		
	}
}