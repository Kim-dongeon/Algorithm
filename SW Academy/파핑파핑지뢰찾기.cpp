#include <iostream>
#include <cstdio>
#include <set>
#include <queue>
#include <cstring>
using namespace std;
int N;
char arr[320][320];
int ans = 0;

int dx[] = { 0,0,1,-1,1,1,-1,-1 };
int dy[] = { 1,-1,0,0,1,-1,1,-1 };
int isVisited[320][320];
int area = 1;
queue<pair<int, int>> que;
set<int> s;
int chk(int x, int y) {
	int cnt = 0;
	for (int i = 0; i < 8; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && nx < N&&ny >= 0 && ny < N&&arr[nx][ny] == '*') {
			cnt++;
		}
	}

	return cnt;
}
int main() {
	int T;
	cin >> T;

	for (int t = 1; t <= T; t++) {
		cin >> N;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				scanf(" %c", &arr[i][j]);
			}
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (isVisited[i][j] == false && arr[i][j] == '.') {
					if (chk(i, j) == 0) {
						isVisited[i][j] = area;
						que.push(make_pair(i, j));

						while (!que.empty()) {
							int x = que.front().first;
							int y = que.front().second;
							
							que.pop();
							for (int k = 0; k < 8; k++) {
								int nx = x + dx[k];
								int ny = y + dy[k];
								if (nx >= 0 && nx < N&&ny >= 0 && ny < N&&arr[nx][ny] == '.'&&isVisited[nx][ny] != area) {
									if (chk(nx, ny) == 0) {
										isVisited[nx][ny] = area;
										que.push(make_pair(nx, ny));
									}
									else {
										isVisited[nx][ny] = area;
									}
								}
							}
						}
					}
					else {
						isVisited[i][j] = area;
					}
					area++;
				}
			}
		}

	
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (isVisited[i][j] > 0) {
					s.insert(isVisited[i][j]);
				}
			}
		}
		ans = s.size();
		printf("#%d %d\n",t, ans);
		ans = 0;
		s.clear();
		for (int i = 0; i < N; i++) {
			memset(isVisited[i], 0, sizeof(int)*N);
		}
	}


}