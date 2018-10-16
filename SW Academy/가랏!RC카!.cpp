#include <iostream>

using namespace std;

int main()
{
	int T;
	cin >> T;

	for (int t = 0; t < T; t++)
	{
		int N;
		cin >> N;

		int distance = 0;
		int cur_speed = 0;

		for (int n = 0; n < N; n++)
		{
			int cmd;
			cin >> cmd;

			if (cmd == 0)
			{
				distance += cur_speed;
			}
			else if (cmd == 1)
			{
				int accel = 0;
				cin >> accel;
				cur_speed += accel;
				distance += cur_speed;
			}
			else if (cmd == 2)
			{
				int decel = 0;
				cin >> decel;
				cur_speed -= decel;
				if (cur_speed < 0)
				{
					cur_speed = 0;
				}
				distance += cur_speed;
			}
		}
		cout << "#" << t + 1 << ' ' << distance << endl;
	}
}