#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

char arr[103][103];
bool isVisited[103][103];

int cnt;


queue<pair<int, int>> que;

void bfs(int N) {

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			
			if (isVisited[i][j] == false) {
				que.push(make_pair(i, j));
				char ch = arr[i][j];				
				isVisited[i][j] = true;

				while (!que.empty()) {
					int sx = que.front().first;
					int sy = que.front().second;
					que.pop();
					for (int k = 0; k < 4; k++) {
						int nx = sx + dx[k];
						int ny = sy + dy[k];
						if (nx >= 0 && ny >= 0 && nx < N && ny < N && arr[nx][ny] == ch && isVisited[nx][ny] == false) {
							isVisited[nx][ny] = true;
							que.push(make_pair(nx, ny));
						}
					}
					
				}
				cnt++;
			}


		}
	}
}
void change(int N) {
	cnt = 0;
	for (int i = 0; i < N; i++) {
		memset(isVisited[i], false, sizeof(bool)*N);
		for(int j = 0; j < N; j++) {
			if (arr[i][j] == 'G') {
				arr[i][j] = 'R';
			}
		}
	}


}
int main() {
	int N;
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf(" %c", &arr[i][j]);
		}
	}
	bfs(N);
	cout << cnt << ' ';
	change(N);

	bfs(N);
	cout << cnt << endl;
}