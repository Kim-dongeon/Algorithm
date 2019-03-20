#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;

int N, W, H;
int ans = 987654321;
int arr[20][20];
int arr2[20][20];
int order[15]; //폭파순서
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
bool flag = false;	//중간에 끝났는지확인용

void init_map() {
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			arr2[i][j] = arr[i][j];
		}
	}
}
void down() {
	for (int j=0; j < W; j++) {
		for (int i = H-1; i > 0; i--) {
			if (arr2[i][j] == 0) {
				for (int k = i - 1; k >= 0; k--) {
					if (arr2[k][j]>0) {
						arr2[i][j] = arr2[k][j];
						arr2[k][j] = 0;
						break;
					}
				}
			}
		}
	}
}
struct node {
	int x;
	int y;
	int bomb;
};
int bomb_cnt() {
	int cnt = 0;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			if (arr2[i][j] > 0) {
				cnt++;
			}
		}
	}
	return cnt;
}
void print() {
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			cout << arr2[i][j] << ' ';
		}
		cout << endl;
	}
	cout << endl;
}
bool order_go(int order[], int sz, int n, int k) {

	if (k == 0) {
		init_map();
		//순서대로 파괴
		queue<node> que;
		
		cout << "###########" << ' ';
		for (int i = 0; i < sz; i++) {
		cout << order[i] << ' ';
		}
		cout << endl;


		for (int i = 0; i < sz; i++) {		
			if (bomb_cnt() == 0) {
				flag = true;
				ans = 0;			
				return true;
			}
			int bomb_col = order[i];
			int bomb_row = -1;
			//맨위 벽돌 찾기
			for (int row = 0; row < H; row++) {
				if (arr2[row][bomb_col]) {
					bomb_row = row;
					break;
				}
			}

			if (bomb_row == -1) {
				break;
			}

			int bomb = arr2[bomb_row][bomb_col];
			if (bomb == 1) {
				arr2[bomb_row][bomb_col] = 0;
			}
			else {
				que.push({ bomb_row,bomb_col,bomb });

				while (!que.empty()) {
					int x = que.front().x;
					int y = que.front().y;
					int B = que.front().bomb;
					arr2[x][y] = 0;
					que.pop();

					for (int k = 0; k < 4; k++) {
						for (int b = 0; b < B; b++) {
							int nx = x + dx[k]*b;
							int ny = y + dy[k] * b;

							if (nx >= 0 && nx < H&&ny >= 0 && ny < W) {
								if (arr2[nx][ny] == 1) {
									arr2[nx][ny] = 0;
								}
								else if (arr2[nx][ny] > 1) {
									que.push({ nx,ny,arr2[nx][ny] });
								}
							}
							else {
								break;
							}
						}
					}
				}
			}
			down();
			//print();
		}
		
		int tmp = bomb_cnt();
		
		//cout << tmp << endl;
		ans = min(ans, tmp);
		
		return false;
	}

	for (int i = 0; i < n; i++) {
		order[sz] = i;
		if (order_go(order, sz + 1, n, k - 1)) {
			//cout << "aa" << endl;
			return true;
		}		
	}
	return false;
}
int main() {
	int T;
	cin >> T;

	for (int t = 1; t <= T; t++) {
		scanf("%d %d %d", &N, &W, &H);

		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				scanf("%d", &arr[i][j]);				
			}
		}

		//순서를 정한다.
		if (order_go(order, 0, W, N)) {
			flag = false;
		}

		printf("#%d %d\n", t, ans);
		ans = 987654321;
	}
}