#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	for (int t = 0; t < 10; t++)
	{
		int N;
		cin >> N;
		vector<int> aprtment(N);

		for (int i = 0; i < N; i++)
		{
			cin >> aprtment[i];
		}
		int cnt = 0;
		for (int i = 2; i < N-2; i++)
		{		
			if (aprtment[i] > aprtment[i - 1] && aprtment[i] > aprtment[i - 2] && aprtment[i] > aprtment[i + 1] && aprtment[i] > aprtment[i + 2])
			{
				int MAX = max(aprtment[i - 1],max( aprtment[i - 2],max(aprtment[i+1],aprtment[i+2])));
				cnt += (aprtment[i] - MAX);

			}
		}
		cout << "#" << t + 1 << ' ' << cnt << endl;
	}
}