#include <iostream>
#include <cstdio>

using namespace std;

int dx[] = { 0,-1,1,0,0 };
int dy[] = { 0,0,0,-1,1 };
//상하좌우 0123
struct node {
	int num;
	int d;
	int change;
};

node arr[103][103];
int ans = 0;
int N, M, K;
int main() {
	int T;
	scanf("%d", &T);

	for (int t = 0; t < T; t++) {
		for (int i = 0; i < 103; i++) {
			for (int j = 0; j < 103; j++) {
				arr[i][j] = { 0,0,0 };
			}
		}
		scanf("%d %d %d", &N, &M, &K);

		for (int i = 0; i < K; i++) {
			int x, y, num, d;
			scanf("%d %d %d %d", &x, &y, &num, &d);
			arr[x][y] = { num,d,num };
		}

		for (int m = 0; m < M; m++) {
			node cpy[103][103] = { 0, };
			
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					if (arr[i][j].num != 0) {
						//군집이 있는 경우
						int nx = i + dx[arr[i][j].d];
						int ny = j + dy[arr[i][j].d];
						if (cpy[nx][ny].num == 0) {
							//빈 곳인 경우
							if (nx == 0 || nx == N - 1 || ny == 0 || ny == N - 1) {
								//가장자리인 경우
								int nd = arr[i][j].d;
								if (nd == 1) {
									nd = 2;
								}
								else if (nd == 2) {
									nd = 1;
								}
								else if (nd == 3) {
									nd = 4;
								}
								else if (nd == 4) {
									nd = 3;
								}

								cpy[nx][ny] = { arr[i][j].num / 2,nd, arr[i][j].num / 2 };
							}
							else {
								cpy[nx][ny] = { arr[i][j].num,arr[i][j].d,arr[i][j].num };
							}
						}
						else {
							//빈곳이 아닌경우							
							if (cpy[nx][ny].change < arr[i][j].num) {								
								cpy[nx][ny].num += arr[i][j].num;
								cpy[nx][ny].d = arr[i][j].d;
								cpy[nx][ny].change = arr[i][j].change;
							}
							else {
								cpy[nx][ny].num += arr[i][j].num;
							}
						}
					}
				}
			}

			//이동이 끝났으면 다시 복사
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					if (cpy[i][j].change != cpy[i][j].num) {
						cpy[i][j].change = cpy[i][j].num;
					}					
					arr[i][j] = cpy[i][j];									
				}
			}

			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					cout<< arr[i][j].num << ' ';
				}
				cout << endl;
			}
			cout << endl;
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (arr[i][j].num > 0) {
					ans += arr[i][j].num;
				}
			}
		}
		printf("#%d %d\n", t + 1, ans);
		ans = 0;
	}

}