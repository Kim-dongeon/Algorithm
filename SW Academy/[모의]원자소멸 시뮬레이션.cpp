#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;


int N;
int ans;
int dy[] = {0, 1,-1,0,0 };
int dx[] = {0, 0,0,-1,1 };
int atom[1002][4];
int visit[4002][4002];
bool collision[4002][4002];
//0 상 하 좌 우

int main() {
	int T;
	scanf("%d", &T);

	for (int t = 0; t < T; t++) {
		scanf("%d", &N);

		for (int i = 0; i < N; i++) {
			int x, y, d, K;
			scanf("%d %d %d %d", &x, &y, &d, &K);
			atom[i][0] = 2*(x + 1000);
			atom[i][1] = 2*(y + 1000);
			atom[i][2] = d + 1;
			atom[i][3] = K;
			visit[atom[i][0]][atom[i][1]]++;
		}
		int num = N;	//살아있는 원자 개수
		while (num > 0) {
			for (int i = 0; i < N; i++) {
				if (atom[i][3] > 0) {
					//원자 살아있는 경우
					int x = atom[i][0];
					int y = atom[i][1];
					int d = atom[i][2];
					

					int nx = x + dx[d];
					int ny = y + dy[d];
					if (nx < 0 || nx>4000 || ny > 4000 || ny < 0) {
						//범위밖으로 나간경우
						visit[x][y]--;
						num--;
						atom[i][0] = 0;
						atom[i][1] = 0;
						atom[i][2] = 0;
						atom[i][3] = 0;
					}
					else {
						atom[i][0] = nx;
						atom[i][1] = ny;
						visit[x][y]--;
						visit[nx][ny]++;
						if (visit[nx][ny] > 1) {
							collision[nx][ny] = true;
						}
					}
				}
			}
			for (int i = 0; i < N; i++) {
				int x = atom[i][0];
				int y = atom[i][1];

				if (collision[x][y]) {
					atom[i][0] = 0;
					atom[i][1] = 0;
					atom[i][2] = 0;
					ans += atom[i][3];
					atom[i][3] = 0;
					num--;
					visit[x][y]--;
					if (visit[x][y] == 0) {
						collision[x][y] = false;
					}
				}
			}
		}

		printf("#%d %d\n", t + 1, ans);
		ans = 0;
		


	}
}
