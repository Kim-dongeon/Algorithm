#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int N;
int arr[22][22];
int ans = 0;
int dx[] = { 1,1,-1,-1 };
int dy[] = { 1,-1,-1,1 };
//오른쪽 아래, 왼쪽 아래, 왼쪽 위, 오른쪽 위
int isVisited[22][22];
int D[102];//디저트 체크

void dfs(int x, int y , int sx, int sy, int d) {
	
	isVisited[x][y] = true;
	D[arr[x][y]] = true;

	for (int k = 0; k < 2; k++) {
		int nd = d + k;
		
		if (nd == 4) {
			if (x+dx[0] == sx && y+dy[0] == sy) {
				//다시 돌아론경우
				int cnt = 0;
				cout << sx << ' ' << sy << ' ' << endl;
				for (int i = 0; i < 101; i++) {
					if (D[i]) {
						cout << i << ' ';
						cnt++;
					}
				}
				cout << endl;
				ans = max(ans, cnt);
			}
			break;
		}
		int nx = x + dx[nd];
		int ny = y + dy[nd];

	
		if (nx >= 0 && nx < N&& ny >= 0 && ny < N && D[arr[nx][ny]] == false && isVisited[nx][ny] == false) {
			dfs(nx, ny, sx, sy, nd);
		}
	}


	isVisited[x][y] = false;
	D[arr[x][y]] = false;
}
int main() {
	int T;
	scanf("%d", &T);
	for (int t = 0; t < T; t++) {
		scanf("%d", &N);
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				scanf("%d", &arr[i][j]);
			}
		}


		for (int i = 1; i < N; i++) {
			for (int j = 0; j < N; j++) {				
				dfs(i, j,i,j,0);				
			}
		}

		if (ans == 0) {
			ans = -1;
		}
		printf("#%d %d\n", t + 1, ans);
		ans = 0;
	}
}

