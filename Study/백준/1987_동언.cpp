#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

char arr[22][22];
bool isVisited[22][22];
bool alpha[30];
int maxCnt;
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };

void dfs(int R, int C, int x, int y, int cnt) {
	isVisited[x][y] = true;
	alpha[(arr[x][y] - 'A')] = true;
	for (int k = 0; k < 4; k++) {
		int nx = x + dx[k];
		int ny = y + dy[k];
		if (nx >= 0 && nx < R && ny >= 0 && ny < C && isVisited[nx][ny] == false) {
			if (alpha[(arr[nx][ny] - 'A')] == false){
				dfs(R, C, nx, ny, cnt + 1);
				isVisited[nx][ny] = false;
				alpha[(arr[nx][ny] - 'A')] = false;
			}
		}
	}
	maxCnt = max(maxCnt, cnt);
}
int main() {
	int R, C;
	scanf("%d %d", &R, &C);
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			scanf(" %c", &arr[i][j]);
		}
	}
	dfs(R, C, 0, 0, 1);
	printf("%d", maxCnt);
}