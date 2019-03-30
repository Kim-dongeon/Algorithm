#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;
int ans;
int N;
int K;
int arr[10][10];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int isVisited[10][10];

void dfs(int x,int y,int d, int dist) {
	isVisited[x][y] = true;

	for (int k = 0; k < 4; k++) {
		int nx = x + dx[k];
		int ny = y + dy[k];

		if (nx >= 0 && nx < N && ny >= 0 && ny < N && isVisited[nx][ny] == false) {
			if (arr[nx][ny] < arr[x][y]) {
				dfs(nx, ny, d,dist+1);
			}
			else {
				//높거나 같은 경우
				if (d == 0) {
					//깎는게 가능하다면
					int next = arr[nx][ny] - (arr[x][y] - 1);					
					if (K >= next) {
						arr[nx][ny] -= next;
						dfs(nx, ny, 1, dist + 1);
						arr[nx][ny] += next;
					}
				}
			}
		}
	}

	ans = max(ans, dist);
	isVisited[x][y] = false;
}
int main() {
	int T;
	scanf("%d", &T);

	for (int t = 0; t < T; t++) {
		scanf("%d %d", &N, &K);
		int max_val = 0;//가장 높은 봉우리
		vector<pair<int, int> > start;//봉우리 좌표 값
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				scanf("%d", &arr[i][j]);
				max_val = max(max_val, arr[i][j]);
			}
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (arr[i][j] == max_val) {
					start.push_back(make_pair(i, j));
				}
			}
		}

		for (int i = 0; i < start.size(); i++) {
			int x = start[i].first;
			int y = start[i].second;
			dfs(x, y, 0,1);

		}

		printf("#%d %d\n", t + 1, ans);
		ans = 0;
	}


}