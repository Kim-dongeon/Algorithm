#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
#include <cmath>
using namespace std;

int K;
vector<int> magnet[4];
int dx[2] = { 1,-1 };
bool isVisited[5];

void right_rotate(vector<int> &v) {		//시계방향
	int tmp = v[7];

	for (int i = 7; i > 0; i--) {
		v[i] = v[i - 1];
	}
	v[0] = tmp;
}
void left_rotate(vector<int> &v) {	//반시계방향
	int tmp = v[0];

	for (int i = 0; i < 7; i++) {
		v[i] = v[i + 1];
	}
	v[7] = tmp;
}
int main() {
	int T;
	scanf("%d", &T);
	
	for (int t = 1; t <= T; t++) {
		int ans = 0;
		scanf("%d", &K);
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 8; j++) {
				int tmp = 0;
				scanf("%d", &tmp);
				magnet[i].push_back(tmp);
			}
		}


		for (int i = 0; i < K; i++) {
			int magnet_idx, d;
			scanf("%d %d", &magnet_idx, &d);

			queue<pair<int, int>> que;
			magnet_idx--;
			que.push(make_pair(magnet_idx, d));
			isVisited[magnet_idx] = true;

			while (!que.empty()) {
				int cur_magnet = que.front().first;
				int cur_d = que.front().second;
				int right = magnet[cur_magnet][2];
				int left = magnet[cur_magnet][6];
				que.pop();
				if (cur_d == 1) {
					right_rotate(magnet[cur_magnet]);
				}
				else {
					left_rotate(magnet[cur_magnet]);
				}

				for (int k = 0; k < 2; k++) {
					int next_num = cur_magnet + dx[k];
					int next_d = 0;
					if (cur_d == 1) {
						next_d = -1;
					}
					else {
						next_d = 1;
					}
					if (next_num >= 0 && next_num < 4 && isVisited[next_num] == false) {
						if (k == 0) {	//오른쪽 애랑 비교
							if (right != magnet[next_num][6]) {
								que.push(make_pair(next_num, next_d));
								isVisited[next_num] = true;
							}
						}
						else {
							if (left != magnet[next_num][2]) {
								que.push(make_pair(next_num, next_d));
								isVisited[next_num] = true;
							}
						}
					}
				}
			}
			memset(isVisited, false, sizeof(bool) * 4);
		}

		for (int i = 0; i < 4; i++) {
			if (magnet[i][0] == 1) {
				ans += pow(2, i);
			}			
		}

		printf("#%d %d\n", t, ans);
		
		for (int i = 0; i < 4; i++) {
			magnet[i].clear();
		}
	}
}