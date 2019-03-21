#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

int arr[110][110];
int isVisited[110][110];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int dist[110][110];

/*int main() {
	int T;
	scanf("%d", &T);

	for (int t = 1; t <= T; t++) {
		int N;
		scanf("%d", &N);
		queue<pair<int, int>> que;
		
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				scanf("%1d", &arr[i][j]);
			}
		}

		isVisited[0][0] = 1;
		que.push(make_pair(0, 0));

		while (!que.empty()) {
			int x = que.front().first;
			int y = que.front().second;
			
			que.pop();
			for (int k = 0; k < 4; k++) {
				int nx = x + dx[k];
				int ny = y + dy[k];

				if (nx >= 0 && nx < N&&ny >= 0 && ny < N) {
					if (isVisited[nx][ny] == 0 || isVisited[nx][ny] > isVisited[x][y] + arr[nx][ny]) {
						que.push(make_pair(nx, ny));
						isVisited[nx][ny] = isVisited[x][y] + arr[nx][ny];
					}
				}
			}
		}
		printf("#%d %d\n", t, isVisited[N - 1][N - 1]-1);

		for (int i = 0; i < N; i++) {
			memset(isVisited[i], 0, sizeof(int)*N);
		}
	}
}*/

struct node {
	int x;
	int y;
	int d;
};
bool operator<(node a, node b) {
	return a.d < b.d;
}
int main() {	
	int T;
	cin >> T;

	for (int t = 1; t <= T; t++) {
		int N;
		cin >> N;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				scanf(" %1d", &arr[i][j]);
				dist[i][j] = 987654321;
			}
		}

		priority_queue < node> pq;

		pq.push({ 0,0,0 });
		dist[0][0] = 0;

		/*while (!pq.empty()) {
			int x = pq.top().x;
			int y = pq.top().y;
			int d = -pq.top().d;
			pq.pop();
			if (dist[x][y] < d) {
				continue;
			}
			for (int k = 0; k < 4; k++) {
				int nx = x + dx[k];
				int ny = y + dy[k];

				if (nx >= 0 && nx < N&&ny >= 0 && ny < N) {
					if (dist[nx][ny] > d + arr[nx][ny]) {
						dist[nx][ny] = d + arr[nx][ny];
						pq.push({ nx,ny,-(d + arr[nx][ny]) });
					}
				}
			}
		}*/

		printf("#%d %d\n", t, dist[N - 1][N - 1]);
	}
}