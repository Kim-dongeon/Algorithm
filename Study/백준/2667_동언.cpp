#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;
int N;
int arr[27][27];
bool isVisited[27][27];
vector<int> apart;

int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			scanf("%1d", &arr[i][j]);
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			queue<pair<int,int>> que;
			if (arr[i][j] == 1 && isVisited[i][j] == false)
			{
				que.push(make_pair(i, j));
				isVisited[i][j] = true;
				int apart_cnt = 0;
				while (!que.empty())
				{
					int x = que.front().first;
					int y = que.front().second;
					que.pop();
					for (int k = 0; k < 4; k++)
					{
						int nx = x + dx[k];
						int ny = y + dy[k];

						if (nx >= 0 && nx < N&&ny >= 0 && ny < N&&arr[nx][ny] == 1 && isVisited[nx][ny] == false)
						{
							que.push(make_pair(nx, ny));
							isVisited[nx][ny] = true;
							apart_cnt++;
						}
					}
				}
				apart.push_back(apart_cnt);
			}
		}
	}
	cout << apart.size()<<endl;
	sort(apart.begin(), apart.end());
	for (int i = 0; i < apart.size(); i++)
	{
		cout << apart[i]+1 << endl;
	}
}