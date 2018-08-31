#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

int main()
{
	int N;
	cin >>N;
	for (int k = 0; k < N;k++)
	{
		int x = 0;
		cin >> x;
		long long  sum = 0;
		vector<int> v;
		for (int i = 0; i < x; i++)
		{
			int t;
			cin >> t;
			v.push_back(t);
		}
		int max = v.back();
		for(int i=v.size()-2;i>=0 ;i--)
		{
			if (max < v[i])
			{
				max = v[i];
			}
			else {
				sum += max - v[i];
			}
		}
		printf("#%d %lld\n", k + 1, sum);
	}
}