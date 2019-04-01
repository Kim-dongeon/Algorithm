#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

int N;
int arr[120][120];
int ans = 0;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
//우 좌 하 상
struct node {
	int x;
	int y;
	int num;
};
vector<node> wormhole;
int main() {
	int T;
	scanf("%d", &T);

	for (int t = 0; t < T; t++) {
		scanf("%d", &N);

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				scanf("%d", &arr[i][j]);
				if (arr[i][j] > 5) {
					wormhole.push_back({ i,j,arr[i][j] });
				}
			}
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (arr[i][j] != 0) {
					continue;
				}
				//cout << "@@@@@@ " << i << ' ' << j << endl;
				for (int k = 0; k < 4; k++) {
					int cnt = 0;
					int sx = i;
					int sy = j;
					int d = k;

					//cout <<"##### "<< k << endl;
					while (true) {
						sx += dx[d];
						sy += dy[d];
						//cout << sx << ' ' << sy<<' ' << endl;
						if (sx == i && sy == j) {
							//같은 지점으로 돌아옴
							break;
						}
						if (sx>=0 && sx <N && sy>=0 && sy<N) {
							if (arr[sx][sy] == -1) {
								//블랙홀
								break;
							}
							//우좌하상 0123
							if (arr[sx][sy] == 1) {
								cnt++;
								if (d == 0) {
									d = 1;
								}
								else if (d == 1) {
									d = 3;
								}
								else if (d == 2) {
									d = 0;
								}
								else if (d == 3) {
									d = 2;
								}
							}
							else if (arr[sx][sy] == 2) {
								cnt++;
								if (d == 0) {
									d = 1;
								}
								else if (d == 1) {
									d = 2;
								}
								else if (d == 2) {
									d = 3;
								}
								else if (d == 3) {
									d = 0;
								}
							}
							else if (arr[sx][sy] == 3) {
								cnt++;
								if (d == 0) {
									d = 2;
								}
								else if (d == 1) {
									d = 0;
								}
								else if (d == 2) {
									d = 3;
								}
								else if (d == 3) {
									d = 1;
								}
							}
							else if (arr[sx][sy] == 4) {
								cnt++;
								if (d == 0) {
									d = 3;
								}
								else if (d == 1) {
									d =0 ;
								}
								else if (d == 2) {
									d = 1;
								}
								else if (d == 3) {
									d = 2;
								}
							}
							else if (arr[sx][sy] == 5) {
								cnt++;
								if (d == 0) {
									d = 1;
								}
								else if (d == 1) {
									d = 0;
								}
								else if (d == 2) {
									d = 3;
								}
								else if (d == 3) {
									d = 2;
								}
							}
							else if (arr[sx][sy] > 5) {
								for (int a = 0; a < wormhole.size(); a++) {
									if (wormhole[a].num == arr[sx][sy]) {
										if (sx != wormhole[a].x || sy != wormhole[a].y) {
											sx = wormhole[a].x;
											sy = wormhole[a].y;
				
											break;
										}
									}
								}
							}
							
						}
						else {
							//밖으로 나간경우
							//우좌하상
							if (d == 0) {
								d = 1;
							}
							else if (d == 1) {
								d = 0;
							}
							else if (d == 2) {
								d = 3;
							}
							else if (d == 3) {
								d = 2;
							}
							cnt++;
						}
					}
					
					ans = max(ans, cnt);
				}
			}
		}

		printf("#%d %d\n", t + 1, ans);
		ans = 0;
		wormhole.clear();
	}
}