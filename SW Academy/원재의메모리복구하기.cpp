#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	int T;
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		string target;
		cin >> target;

		int target_sz = target.size();
		vector<int> init(target_sz);

		bool flag = 1;
		int cnt = 0;
		for (int i = 0; i < target_sz; i++)
		{
			if (target[i] == flag +'0')
			{				
				for (int j = i; j < target_sz; j++)
				{
					init[j] = flag;
				}
				flag = !flag;
				cnt++;
			}
		}
		cout << "#" << t + 1 << ' ' << cnt << endl;
	}
}