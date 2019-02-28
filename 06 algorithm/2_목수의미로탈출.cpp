/*
����
�Ʒ��� ���� �̵��� �� �ִ� ��, �׸��� �̵��� �� ���� ������ �̷���� ũ�� N x M �� ������ �־�����. �� ��, (N-1, 0) ���� ����Ͽ� (0, M-1) ���� �����ϴ� �ִܰŸ��� ã���� �Ѵ�. �׷��� ����� ���� �ϳ��� ���� ������, �� ������ �̿��Ͽ� ���� ���μ� �� �ִ�. ������ �� ������ �������� �׷��� ���� �ʱ� ������, ���� �ִ� 1���ۿ� �� �� ����. ����� ��������� ���������� �̵��ϱ� ���� �ִܰŸ��� ����ϴ� ���α׷��� �ۼ��Ͻÿ�. ����, ���� �ִ� 1������ �� �� �ִ�. �Ʒ� ������ ��� ��X�� �� ǥ�õ� ���� �� ��� �Ÿ� 18���� ��������� ���������� �̵��� �� �ִ�.

ec-20
�Է�
ù° �ٿ� ������ ���� ���� N�� ������ ���� ���� M�� �־�����. ( 1 �� N, M �� 1,000 ) ��° �ٺ��� ������ ������ �־�����. 0�� �̵��� �� �ִ� �κ�, 1�� �̵��� �� ���� �κ��� ��Ÿ����.

���
����� (N-1, 0) ���� ����Ͽ� (0, M-1) ���� �̵��ϴ� �� �ʿ��� �ִܰŸ��� ����Ѵ�. ����� �̷θ� �׻� Ż���� �� �ִٰ� �����Ѵ�.

���� �Է�
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
���� ���
18
���� �Է�
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
���� ���
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