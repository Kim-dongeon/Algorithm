#include <iostream>
#include <vector>
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
			cin >> val;
			v.push_back(val);			
		}
		int cmd_num;
		cin >> cmd_num;
		for (int i = 0; i < cmd_num; i++)
		{
			char cmd;
			cin >> cmd;

			if (cmd == 'I')
			{
				int x, y;
				cin >> x >> y;
				vector<int> add;
				for (int j = 0; j < y; j++)
				{
					int temp;
					cin >> temp;
					add.push_back(temp);
				}

				auto it = v.begin();
				v.insert(it + x, add.begin(), add.end());

			}
			else if (cmd == 'D')
			{
				int x, y;
				cin >> x >> y;
				auto it = v.begin();
				it = v.erase(it + x, it+x+y);
			}
			else
			{
				int y;
				cin >> y;
				for (int a = 0; a < y; a++)
				{
					int temp;
					cin >> temp;
					v.push_back(temp);
				}
			}
		}
		cout << "#" << t + 1 << ' ';
		for (int i = 0; i < 10; i++)
		{
			cout << v[i] << ' ';
		}
		cout << endl;
	}
}