#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
using namespace std;

int main()
{
	int T;
	cin >> T;

	for (int t = 0; t < T; t++)
	{
		long long N, A, B;
		cin >> N >> A >> B;
		long long R = 0, C = 0;
		long long MIN = 1000000000;
		for (int i = 1; i < N; i++)
		{
			int j_max = N / i;
			for (int j = 1; j <= j_max; j++)
			{
				R = i;
				C = j;
				long long temp = A*abs(R - C) + B*(N - R*C);
				MIN = min(MIN, temp);				
				
			}
		}			
		cout << "#" << t + 1 << ' ' << MIN << endl;
		
	}
}