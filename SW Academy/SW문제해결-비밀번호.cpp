#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

int main()
{
	for (int t = 0; t < 10; t++)
	{
		int N;
		cin >> N;
		vector<int> v;
		for (int i = 0; i < N; i++)
		{
			int val;
			scanf("%1d", &val);
			v.push_back(val);
		}

		for (int i = 0; i < v.size() - 1;)
		{
			if (v[i] - v[i + 1] == 0)
			{
				v.erase(v.begin() + i);
				v.erase(v.begin() + i);
				if (i != 0)
				{
					i--;
				}
			}
			else
			{
				i++;
			}
		}

		cout << "#" << t + 1 << ' ';
		for (int i = 0; i < v.size(); i++)
		{
			cout << v[i];
		}
		cout << endl;
	}
}