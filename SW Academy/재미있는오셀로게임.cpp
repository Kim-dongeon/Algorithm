#include <iostream>
#include <cstdio>

using namespace std;

int N, M;
int arr[10][10];
int ans_w = 0;//2
int ans_b = 0;//1
void init_map(int n) {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			arr[i][j] = 0;
		}
	}
	n--;
	arr[n / 2][n / 2] = 2;
	arr[n / 2][n / 2 + 1] = 1;
	arr[n / 2 + 1][n / 2] = 1;
	arr[n / 2 + 1][n / 2 + 1] = 2;
}
int main() {
	int T;
	cin >> T;

	for (int t = 1; t <= T; t++) {
		cin >> N >> M;
		init_map(N);
		for (int m = 0; m < M; m++) {
			int x; int y; int color;
			cin >> y >> x >> color;
			x--; y--;
			arr[x][y] = color;
			//상
			for (int i = x - 1; i >= 0; i--) {
				if (arr[i][y] == 0) break;
				if (arr[i][y] == color) {
					for (int j = i + 1; j < x; j++) {
						arr[j][y] = color;
					}
					break;
				}
			}
			//하
			for (int i = x + 1; i < N; i++) {
				if (arr[i][y] == 0) break;
				if (arr[i][y] == color) {
					for (int j = i - 1; j > x; j--) {
						arr[j][y] = color;
					}
					break;
				}
			}
			//좌
			for (int i = y - 1; i >= 0; i--) {
				if (arr[x][i] == 0) break;
				if (arr[x][i] == color) {
					for (int j = i + 1; j < y; j++) {
						arr[x][j] = color;
					}
					break;
				}
			}
			//우
			for (int i = y + 1; i < N; i++) {
				if (arr[x][i] == 0) break;
				if (arr[x][i] == color) {
					for (int j = i - 1; j > y; j--) {
						arr[x][j] = color;
					}
					break;
				}
			}
			//좌상 대각선
			for (int i = x - 1, j = y - 1; i >= 0 && j >= 0; i--, j--) {
				if (arr[i][j] == 0) break;
				if (arr[i][j] == color) {
					for (int a = i + 1, b = j + 1; a < x&&b < y; a++, b++) {
						arr[a][b] = color;
					}
					break;
				}
			}
			//우상 대각선
			for (int i = x - 1, j = y + 1; i >= 0 && j < N; i--, j++) {
				if (arr[i][j] == 0) break;
				if (arr[i][j] == color) {
					for (int a = i + 1, b = j - 1; a < x&&b > y; a++, b--) {
						arr[a][b] = color;
					}
					break;
				}
			}
			//좌하
			for (int i = x + 1, j = y - 1; i<N && j >= 0; i++, j--) {
				if (arr[i][j] == 0) break;
				if (arr[i][j] == color) {
					for (int a = i - 1, b = j + 1; a >x&&b < y; a--, b++) {
						arr[a][b] = color;
					}
					break;
				}
			}
			//우하
			for (int i = x + 1, j = y + 1; i<N && j <N; i++, j++) {
				if (arr[i][j] == 0) break;
				if (arr[i][j] == color) {
					for (int a = i - 1, b = j - 1; a >x&&b>y; a--, b--) {
						arr[a][b] = color;
					}
					break;
				}
			}
		}


		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (arr[i][j] == 1) {
					ans_b++;
				}
				else if (arr[i][j] == 2) {
					ans_w++;
				}
			}
		}
		printf("#%d %d %d\n", t, ans_b, ans_w);
		ans_w = 0;
		ans_b = 0;
	}
}