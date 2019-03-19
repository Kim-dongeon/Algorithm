#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int N, M;
int arr[22][22];
int T;
int ans = -1; //손해보지않고 서비스 가능한 최대 집 수
int run_fee[22];//운영비용

int check(int K) {
	int ret = 0;

	for (int i = 0; i < N; i++) {		
		for (int j = 0; j < N; j++) {
			int tmp = 0;
			
			for (int k = 1; k <= K - 1; k++) {//위 아래 검사
				int u_x = i - K + k;
				int d_x = i + K - k;

				int y_c = 2 * k - 1;
				int s_y = j - (2 * k - 1) / 2;

				for (int y = 0; y < y_c; y++) {
					int ny = s_y + y;
					if (u_x >= 0 && u_x < N && ny < N&&ny >= 0 && arr[u_x][ny]==1) {
						tmp++;
					}
					if (d_x >= 0 && d_x < N && ny < N&&ny >= 0 && arr[d_x][ny] == 1) {
						tmp++;
					}
				}
			}

			int s_y = j - (2 * K - 1) / 2;
			for (int y = 0; y < 2 * K - 1; y++) {
				int ny = s_y + y;
				if (ny < N&&ny >= 0 && arr[i][ny] == 1) {
					tmp++;
				}
			}
			
			cout << K << ' ' << tmp << endl;
			ret = max(ret, tmp);
		}
		
	}


	//cout <<K<<' '<< ret << endl;
	return ret;
}
int main() {

	for (int i = 1; i <= 21; i++) {
		run_fee[i] = i*i + (i - 1)*(i - 1);
	}

	int T;
	cin >> T;

	for (int t = 1; t <= T; t++) {
		scanf("%d %d", &N, &M);
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				scanf("%d", &arr[i][j]);
			}
		}

		int cur_house = 0; //현재 범위에 있는 집 수
		for (int i = 1; i < 22; i++) {
			cur_house = check(i);
			if (cur_house*M - run_fee[i] >= 0) {
				ans = max(ans, cur_house);
			}
		}


		printf("#%d %d\n", t, ans);
		ans = -1;
	}
}