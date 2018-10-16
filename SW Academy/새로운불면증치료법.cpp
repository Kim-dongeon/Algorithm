#include <iostream>
#include <string>
#include <vector>
#include <bitset>
using namespace std;

vector<int> num_cnt(10);
int main()
{
	int T;
	cin >> T;

	for (int t = 0; t < T; t++)
	{
		bitset<10> number;
		int N;
		cin >> N;

		int cnt = 1;
		int idx = 1;
		int cur = N;
		while (true) {			
			string s = to_string(cur);
			
			for (int i = 0; i < s.size(); i++)
			{
				if (number.test(s[i] - '0') == 0)
				{
					number.set(s[i] - '0');
				}
				
			}
			
			if (number.all())
			{
				cout << "#" << t + 1 << ' ' << cur << endl;
				break;
			}
			else {
				cnt++;
				idx++;
				cur = N * idx;
				
			}

		}
		


	}
}