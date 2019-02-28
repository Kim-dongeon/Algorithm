/*
문제
아래와 같이 이동할 수 있는 길, 그리고 이동할 수 없는 벽으로 이루어진 크기 N x M 의 지도가 주어진다. 이 때, (N-1, 0) 에서 출발하여 (0, M-1) 까지 도착하는 최단거리를 찾으려 한다. 그런데 목수는 도끼 하나를 갖고 있으며, 이 도끼를 이용하여 벽을 깨부술 수 있다. 하지만 이 도끼는 내구성이 그렇게 좋지 않기 때문에, 벽을 최대 1개밖에 깰 수 없다. 목수가 출발점에서 도착점까지 이동하기 위한 최단거리를 출력하는 프로그램을 작성하시오. 물론, 벽은 최대 1개까지 깰 수 있다. 아래 예제의 경우 ‘X’ 로 표시된 벽을 깰 경우 거리 18만에 출발점에서 도착점으로 이동할 수 있다.

ec-20
입력
첫째 줄에 지도의 세로 길이 N과 지도의 가로 길이 M이 주어진다. ( 1 ≤ N, M ≤ 1,000 ) 둘째 줄부터 지도의 정보가 주어진다. 0은 이동할 수 있는 부분, 1은 이동할 수 없는 부분을 나타낸다.

출력
목수가 (N-1, 0) 에서 출발하여 (0, M-1) 까지 이동하는 데 필요한 최단거리를 출력한다. 목수는 미로를 항상 탈출할 수 있다고 가정한다.

예제 입력
10 10
0 0 0 0 0 0 1 1 0 0
0 1 1 1 0 0 1 0 1 0
0 1 1 1 0 0 1 0 1 0
0 0 0 0 0 0 0 0 1 0
0 0 1 1 1 1 0 0 1 0
0 0 0 0 0 0 1 1 0 0
0 0 1 1 1 0 1 1 0 0
0 0 1 1 1 0 0 0 0 0
0 0 0 0 0 1 1 1 0 0
0 0 0 0 0 0 0 1 0 0
예제 출력
18
예제 입력
10 10
0 0 0 0 0 0 1 1 0 0
0 1 1 1 0 0 1 1 1 0
0 1 1 1 0 0 1 1 1 0
0 0 0 0 0 0 0 1 1 0
0 0 1 1 1 1 0 1 1 0
0 0 0 0 0 0 1 1 0 0
0 0 1 1 1 0 1 1 0 0
0 0 1 1 1 0 0 1 0 0
0 0 0 0 0 1 1 1 1 1
0 0 0 0 0 0 0 1 0 0
예제 출력
22*/
#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

int N, M;
int arr[1002][1002];
bool isVisited[1002][1002];
int dist[1002][1002];
int wall[1002][1002];
queue<pair<int, int>> que;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

int main() {

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &arr[i][j]);
		}
	}

	que.push(make_pair(N - 1, 0));
	isVisited[N - 1][0] = 1;
	int ans = 987654321;
	while (!que.empty()) {
		int x = que.front().first;
		int y = que.front().second;
		que.pop();

		for (int k = 0; k<4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];

			if (nx >= 0 && ny >= 0 && nx<N&&ny<M&&isVisited[nx][ny] == false && arr[nx][ny] == 0) {
				isVisited[nx][ny] = true;
				dist[nx][ny] = dist[x][y] + 1;
				que.push(make_pair(nx, ny));
			}
			else if (nx >= 0 && ny >= 0 && nx<N&&ny<M&&isVisited[nx][ny] == false && arr[nx][ny] == 1) {
				if (wall[nx][ny] == 0) {
					wall[nx][ny] = dist[x][y] + 1;
				}
				else {
					wall[nx][ny] = min(wall[nx][ny], dist[x][y] + 1);
				}
			}
		}
	}
	if (dist[0][M - 1] != 0) {
		ans = dist[0][M - 1];
	}
	for (int i = 0; i<N; i++) {
		memset(isVisited[i], false, sizeof(bool)*M);
		memset(dist[i], 0, sizeof(int)*M);
	}


	que.push(make_pair(0, M - 1));
	isVisited[0][M - 1] = 1;

	while (!que.empty()) {
		int x = que.front().first;
		int y = que.front().second;
		que.pop();

		for (int k = 0; k<4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];

			if (nx >= 0 && ny >= 0 && nx<N&&ny<M&&isVisited[nx][ny] == false && arr[nx][ny] == 0) {
				isVisited[nx][ny] = true;
				dist[nx][ny] = dist[x][y] + 1;
				que.push(make_pair(nx, ny));
			}if (nx >= 0 && ny >= 0 && nx<N&&ny<M&&isVisited[nx][ny] == false && arr[nx][ny] == 1) {
				if (wall[nx][ny] != 0) {
					ans = min(ans, (wall[nx][ny] + dist[x][y] + 1));
				}
			}
		}
	}
	cout << ans;
	return 0;
}