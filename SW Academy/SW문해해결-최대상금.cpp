#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
using namespace std;

int max_val = -999;
set<int> memo;
void go(string s, int num,int cur_num)
{
	cout << s << ' ' << cur_num << endl;

	if (num == cur_num)
	{
		int val = stoi(s);
		max_val = max(max_val, val);
		return;
	}
	if (memo.find(stoi(s))!= memo.end())
	{
		return;
	}

	memo.insert(stoi(s));
	int str_len = s.size();

	for (int i = 0; i < str_len; i++)
	{
		for (int j = i + 1; j < str_len; j++)
		{			
			char tmp = s[i];
			s[i] = s[j];
			s[j] = tmp;

			go(s, num, cur_num + 1);

			tmp = s[i];
			s[i] = s[j];
			s[j] = tmp;			
		}
	}


}
int main()
{
	int T;
	cin >> T;

	for (int t = 0; t < T; t++)
	{
		string str;
		cin >> str;

		int num;
		cin >> num;
		go(str, num,0);
		cout << "#" << t + 1 << ' ' << max_val << endl;
		max_val = 0;
		memo.clear();
	}
}