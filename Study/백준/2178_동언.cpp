#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
queue<pair<int,int>> q;
bool visited[101][101];
int dist[101][101];
int map[101][101];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int main()
{
	int N, M;
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			scanf("%1d", &map[i][j]);
		}
	}

	dist[0][0] = 1;
	visited[0][0] = true;
	q.push(make_pair(0, 0));

	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && ny >= 0 && nx < N && ny < M)
			{
				if (map[nx][ny] == 1 && visited[nx][ny]==false)
				{
					dist[nx][ny] = dist[x][y] + 1;
					visited[nx][ny] = true;
					q.push(make_pair(nx, ny));
				}
			}
		}
	}


	printf("%d\n", dist[N-1][M-1]);
}