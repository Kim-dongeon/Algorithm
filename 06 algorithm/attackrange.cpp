/*
예제 입력
8
4 5 3
예제 출력
0 0 0 0 3 0 0 0
0 0 0 3 2 3 0 0
0 0 3 2 1 2 3 0
0 3 2 1 x 1 2 3
0 0 3 2 1 2 3 0
0 0 0 3 2 3 0 0
0 0 0 0 3 0 0 0
0 0 0 0 0 0 0 0


예제 입력
6
2 3 3
예제 출력
3 2 1 2 3 0
2 1 x 1 2 3
3 2 1 2 3 0
0 3 2 3 0 0
0 0 3 0 0 0
0 0 0 0 0 0*/

#include <stdio.h>
#include <iostream>
#include <cstring>
using namespace std;

int main() {

	int N;
	scanf("%d", &N);
	int arr[102][102];
	int X, Y, R;
	scanf("%d %d %d", &X, &Y, &R);
	X--;
	Y--;

	int copy[102][102];
	for (int i = 0; i<102; i++) {
		memset(copy[i], 0, sizeof(int) * 102);
	}

	for (int i = 0; i<R + 1; i++) {
		int val = R;
		int j = 0;
		for (j; j<R - i; j++) {
			copy[i][j] = 0;
		}
		for (int k = j; k<2 * i + 1 + j; k++) {
			copy[i][k] = val;
			if (k <i + j) {
				val--;
			}
			else {
				val++;
			}
		}
	}


	for (int i = 0; i<R; i++) {
		int val = R;
		int j = 0;
		for (j; j<i + 1; j++) {
			copy[i + R + 1][j] = 0;
		}
		for (int k = j; k<(R - i - 1) * 2 + 1 + j; k++) {
			copy[i + R + 1][k] = val;

			if (k<((R - i - 1) * 2 + 1) / 2 + j) {
				val--;
			}
			else {
				val++;
			}
		}
	}

	int m_x = R;
	int m_y = R;

	int move_x = m_x - X;
	int move_y = m_y - Y;

	for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= N; j++) {
			int nx = i - move_x;
			int ny = j - move_y;

			if (nx >= 0 && ny >= 0 && nx<N&&ny<N) {
				arr[nx][ny] = copy[i][j];
			}
		}
	}

	for (int i = 0; i<N; i++) {
		for (int j = 0; j<N; j++) {
			if (i == X && j == Y) {
				cout << 'x' << ' ';
			}
			else {
				cout << arr[i][j] << ' ';
			}
		}
		cout << endl;
	}

	return 0;
}