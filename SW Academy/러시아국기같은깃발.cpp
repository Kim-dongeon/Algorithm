#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int N, M;
char arr[52][52];
int ans = 987654321;
int set[10];

void comb(int set[], int sz, int n, int k, int index) {
	if (k == 0) {//³ª´©±â
		int L1 = set[0];
		int L2 = set[1];

		int cnt = 0;
		//Èò
		for (int i = 0; i <= L1; i++) {
			for (int j = 0; j < M; j++) {
				if (arr[i][j] != 'W') {
					cnt++;
				}
			}
		}
		//ÆÄ
		for (int i = L1 + 1; i <= L2; i++) {
			for (int j = 0; j < M; j++) {
				if (arr[i][j] != 'B') {
					cnt++;
				}
			}
		}
		//»¡
		for (int i = L2 + 1; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (arr[i][j] != 'R') {
					cnt++;
				}
			}
		}
		ans = min(ans, cnt);
		return;
	}
	else if (n == index) {
		return;
	}

	set[sz] = index;
	comb(set, sz + 1, n, k - 1, index + 1);
	comb(set, sz, n, k, index + 1);
}
int main() {
	int T;
	
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> N >> M;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				scanf(" %c", &arr[i][j]);
			}
		}

		comb(set, 0, N - 1, 2, 0);


		printf("#%d %d\n", t, ans);
		ans = 987654321;
		memset(set, 0, sizeof(int)*N);
	}
}