#include <iostream>
#include <queue>
using namespace std;

int main()
{
	for (int t = 0; t < 10; t++)
	{
		int temp;
		cin >> temp;

		queue<int> que;
		for (int i = 0; i < 8; i++)
		{
			int val;
			cin >> val;
			que.push(val);
		}
		int cycle = 0;
		while (true)
		{
			int fr = que.front()-(cycle%5+1);
			cycle++;
			que.pop();
			
			if (fr <= 0)
			{
				que.push(0);
				cout << "#" << t + 1 << ' ';
				for (int i=0;i<8;i++)
				{
					cout << que.front() << ' ';
					que.pop();
				}
				cout << endl;
				break;
			}
			que.push(fr);			
		}

	}
}