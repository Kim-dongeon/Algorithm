#include <iostream>
#include <vector>
using namespace std;

int num[5] = { 2,3,5,7,11 };
int main()
{
	int T;
	cin >> T;

	for (int t = 0; t < T; t++)
	{
		int n;
		cin >> n;
		vector<int> cnt(5);
		int idx = 0;
		while (n > 1)
		{
			if (n%num[idx] == 0)
			{
				cnt[idx]++;
				n = n / num[idx];
			}
			else {
				idx++;
			}
		}

		cout << "#" << t + 1 << ' ';
		for (int i = 0; i < 5; i++)
		{
			cout << cnt[i] << ' ';
		}
		cout << endl;
	}
}