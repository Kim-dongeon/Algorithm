#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

bool isVisited[4][16][22][22]; //방향, 메모리,x,y;
							   //방향 우 좌 하 상 0 1 2 3
int N, M;
char arr[22][22];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

bool go(int x, int y, int val, int d) {
	
	if (arr[x][y] >= '0' && arr[x][y] <= '9') {
		val = (arr[x][y] - '0');
	}
	else if (arr[x][y] == '<') {
		d = 1;
	}
	else if (arr[x][y] == '>') {
		d = 0;
	}
	else if (arr[x][y] == '^') {
		d = 3;
	}
	else if (arr[x][y] == 'v') {
		d = 2;
	}
	else if (arr[x][y] == '_') {
		(val == 0) ? d = 0 : d = 1;
	}
	else if (arr[x][y] == '|') {
		(val == 0) ? d = 2 : d = 3;
	}
	else if (arr[x][y] == '@') {
		return true;
	}
	else if (arr[x][y] == '+') {
		val = (val + 1) % 16;
	}
	else if (arr[x][y] == '-') {
		val--;
		if (val == -1) {
			val = 15;
		}
	}

	if (isVisited[d][val][x][y]) {
		return false;
	}

	isVisited[d][val][x][y] = true;

	if (arr[x][y] == '?') {
		for (int k = 0; k < 4; k++) {
			int nx = (x + dx[k] +N) % N;
			int ny = (y + dy[k]+M) % M;	
			
			if (go(nx, ny, val, k)) {
				return true;
			}			
		}
	}
	else {
		int nx = (x + dx[d]+N) % N;
		int ny = (y + dy[d]+M) % M;
		
		if (go(nx, ny, val, d)) {
			return true;
		}
		
	}

	return false;
}
int main() {
	int T;
	scanf("%d", &T);

	for (int t = 1; t <= T; t++) {
		cin >> N >> M;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				scanf(" %c", &arr[i][j]);
			}
		}

		printf("#%d ", t);
		if (go(0, 0, 0, 0)) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}


		for (int a = 0; a < 4; a++) {
			for (int b = 0; b < 16; b++) {
				for (int c = 0; c < 22; c++) {
					for (int d = 0; d < 22; d++) {
						isVisited[a][b][c][d] = 0;
					}
				}
			}
		}

	}
}