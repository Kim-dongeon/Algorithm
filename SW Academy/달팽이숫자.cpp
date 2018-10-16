#include <iostream>

using namespace std;

int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
int arr[12][12];
int main()
{
	int T;
	cin >> T;

	for (int t = 0; t < T; t++)
	{
		int N;
		cin >> N;

		int right_edge = N-1;
		int left_edge = 0;
		int direction = 0;
		int move = N;
		int val = 1;
		int nx = 0;
		int ny = 0;
		for (int i = 0; i < N*N; i++)
		{
			for (int j = 0; j < move; j++)
			{				
				arr[nx][ny] = val++;
				if (ny == right_edge && direction == 0)
				{
					move--;
					direction = (direction + 1) % 4;
				}
				else if (nx == right_edge && direction == 1)
				{
					right_edge--;
					direction = (direction + 1) % 4;
				}
				else if (direction == 2 && ny == left_edge)
				{
					move--;
					left_edge++;
					direction = (direction + 1) % 4;
				}
				else if (direction == 3 && nx == left_edge)
				{
					direction = (direction + 1) % 4;
				}

				nx += dx[direction];
				ny += dy[direction];
			}					
		}

		cout << "#" << t + 1 << endl;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cout << arr[i][j] << ' ';
			}
			cout << endl;
		}
	}
}