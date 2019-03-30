#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;
int ans;
int N, M;
int R, C;
int L;//╪р©Д╫ц╟ё

int arr[52][52];
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
//©Л аб ╩С го
int main() {
	int T;
	scanf("%d", &T);

	for (int t = 0; t < T; t++) {
		scanf("%d %d %d %d %d", &N, &M,&R,&C,&L);

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				scanf("%d", &arr[i][j]);
			}
		}

		queue<pair<int, int>> que;
		int isVisited[52][52] = { 0, };
		que.push(make_pair(R, C));
		isVisited[R][C] = true;

		while (!que.empty()) {
			int x = que.front().first;
			int y = que.front().second;
			que.pop();
			if (arr[x][y] == 1) {
				for (int k = 0; k < 4; k++) {
					//©Л аб ╩С го
					int nx = x + dx[k];
					int ny = y + dy[k];

					if (nx >= 0 && nx < N&&ny >= 0 && ny < M&&isVisited[nx][ny] == 0 && arr[nx][ny] !=0) {
						if (k == 0) {
							if (arr[nx][ny] == 2 || arr[nx][ny] == 5 || arr[nx][ny] == 4) {
								continue;
							}
						}
						else if (k == 1) {
							if (arr[nx][ny] == 2 || arr[nx][ny] == 6 || arr[nx][ny] == 7) {
								continue;
							}
						}
						else if (k == 2) {
							if (arr[nx][ny] == 3 || arr[nx][ny] == 4 || arr[nx][ny] == 7) {
								continue;
							}
						}
						else if (k == 3) {
							if (arr[nx][ny] == 3 || arr[nx][ny] == 5 || arr[nx][ny] == 6) {
								continue;
							}
						}
						que.push(make_pair(nx, ny));
						isVisited[nx][ny] = isVisited[x][y] + 1;
					}
				}
			}
			else if (arr[x][y] == 2) {
				//©Л аб ╩С го
				for (int k = 2; k < 4; k++) {
					int nx = x + dx[k];
					int ny = y + dy[k];

					if (nx >= 0 && nx < N&&ny >= 0 && ny < M&&isVisited[nx][ny] == 0 && arr[nx][ny] != 0) {
						if (k == 2) {
							if (arr[nx][ny] == 3 || arr[nx][ny] == 4 || arr[nx][ny] == 7) {
								continue;
							}
						}
						else if (k == 3) {
							if (arr[nx][ny] == 3 || arr[nx][ny] == 5 || arr[nx][ny] == 6) {
								continue;
							}
						}
						que.push(make_pair(nx, ny));
						isVisited[nx][ny] = isVisited[x][y] + 1;
					}
				}
			}
			else if (arr[x][y] == 3) {
				//©Л аб ╩С го
				for (int k = 0; k < 2; k++) {
					int nx = x + dx[k];
					int ny = y + dy[k];

					if (nx >= 0 && nx < N&&ny >= 0 && ny < M&&isVisited[nx][ny] == 0 && arr[nx][ny] != 0) {
						if (k == 0) {
							if (arr[nx][ny] == 2 || arr[nx][ny] == 5 || arr[nx][ny] == 4) {
								continue;
							}
						}
						else if (k == 1) {
							if (arr[nx][ny] == 2 || arr[nx][ny] == 6 || arr[nx][ny] == 7) {
								continue;
							}
						}
						que.push(make_pair(nx, ny));
						isVisited[nx][ny] = isVisited[x][y] + 1;
					}
				}
			}
			else if (arr[x][y] == 4) {
				//©Л аб ╩С го
				for (int k = 0; k < 4; k++) {
					if (k == 1 || k == 3) continue;

					int nx = x + dx[k];
					int ny = y + dy[k];

					if (nx >= 0 && nx < N&&ny >= 0 && ny < M&&isVisited[nx][ny] == 0 && arr[nx][ny] != 0) {
						if (k == 0) {
							if (arr[nx][ny] == 2 || arr[nx][ny] == 5 || arr[nx][ny] == 4) {
								continue;
							}
						}
						else if (k == 2) {
							if (arr[nx][ny] == 3 || arr[nx][ny] == 4 || arr[nx][ny] == 7) {
								continue;
							}
						}
						que.push(make_pair(nx, ny));
						isVisited[nx][ny] = isVisited[x][y] + 1;
					}
				}

			}
			else if (arr[x][y] == 5) {
				for (int k = 0; k < 4; k++) {
					//©Лаб╩Сго
					if (k == 1 || k == 2) continue;

					int nx = x + dx[k];
					int ny = y + dy[k];

					if (nx >= 0 && nx < N&&ny >= 0 && ny < M&&isVisited[nx][ny] == 0 && arr[nx][ny] != 0) {
						if (k == 0) {
							if (arr[nx][ny] == 2 || arr[nx][ny] == 5 || arr[nx][ny] == 4) {
								continue;
							}
						}
						else if (k == 3) {
							if (arr[nx][ny] == 3 || arr[nx][ny] == 5 || arr[nx][ny] == 6) {
								continue;
							}
						}
						que.push(make_pair(nx, ny));
						isVisited[nx][ny] = isVisited[x][y] + 1;
					}
				}
			}
			else if (arr[x][y] == 6) {
				for (int k = 0; k < 4; k++) {
					if (k == 0 || k == 2) continue;

					int nx = x + dx[k];
					int ny = y + dy[k];

					if (nx >= 0 && nx < N&&ny >= 0 && ny < M&&isVisited[nx][ny] == 0 && arr[nx][ny] != 0) {
						if (k == 1) {
							if (arr[nx][ny] == 2 || arr[nx][ny] == 6 || arr[nx][ny] == 7) {
								continue;
							}
						}
						else if (k == 3) {
							if (arr[nx][ny] == 3 || arr[nx][ny] == 5 || arr[nx][ny] == 6) {
								continue;
							}
						}
						que.push(make_pair(nx, ny));
						isVisited[nx][ny] = isVisited[x][y] + 1;
					}
				}
			}
			else if (arr[x][y] == 7) {
				for (int k = 1; k < 3; k++) {					

					int nx = x + dx[k];
					int ny = y + dy[k];

					if (nx >= 0 && nx < N&&ny >= 0 && ny < M&&isVisited[nx][ny] == 0 && arr[nx][ny] != 0) {
						if (k == 1) {
							if (arr[nx][ny] == 2 || arr[nx][ny] == 6 || arr[nx][ny] == 7) {
								continue;
							}
						}
						else if (k == 2) {
							if (arr[nx][ny] == 3 || arr[nx][ny] == 4 || arr[nx][ny] == 7) {
								continue;
							}
						}
						que.push(make_pair(nx, ny));
						isVisited[nx][ny] = isVisited[x][y] + 1;
					}
				}
			}
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				cout << isVisited[i][j] << ' ';
				if (isVisited[i][j] <= L && isVisited[i][j]>=1) {
					ans++;
				}
			}
			cout << endl;
		}
		printf("#%d %d\n", t + 1, ans);
		ans = 0;
	}
}