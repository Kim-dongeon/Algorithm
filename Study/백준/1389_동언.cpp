#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;

int arr[102][102];
int isVisited[102];
int cnt[102][102];


int bfs(int start, int end,int N) {
	queue<int> que;
	memset(isVisited, 0, sizeof(int)*(N+1));
	
	que.push(start);
	isVisited[start] = 1;

	while (!que.empty()) {
		int x = que.front();		
		if (x == end) {		
			return isVisited[x]-1;
		}
		que.pop();
		for (int i = 1; i <= N; i++) {
			if (arr[x][i] == 1 && isVisited[i] == 0) {
				que.push(i);
				isVisited[i] = isVisited[x] + 1;
			}
		}
	}
}
int main() {
	int N, M;

	scanf("%d %d", &N, &M);
	for (int i = 0; i < M; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		arr[a][b] = 1;
		arr[b][a] = 1;
	}

	for (int i = 1; i <= N; i++) {
		for (int j = i + 1; j <= N; j++) {
			int k = bfs(i,j,N);
			cnt[i][j] = k;
			cnt[j][i] = k;
		}
	}

	int _min = 99999999;
	int minIdx = -1;
	for (int i = 1; i <= N; i++) {
		int temp = 0;
		for (int j = 1; j <= N; j++) {
			temp += cnt[i][j];
		}
		if (_min > temp) {
			minIdx = i;
			_min = temp;
		}
	}

	printf("%d\n", minIdx);

}