#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#include <cmath>
using namespace std;

struct node {
	int cur_life;
	int life;
	node(int x,int y):cur_life(x),life(y){}
	node(){}
};
struct info {
	int x;
	int y;
	int life;
};
int N, M;
node arr[53][53];
node map[400][400];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int K;
int ans = 0;
void init_map() {
	for (int i = 0; i < 400; i++) {
		for (int j = 0; j < 400; j++) {
			map[i][j].cur_life = 0;
			map[i][j].life = 0;			
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			map[i + 200][j + 200] = arr[i][j];						
		}
	}

}
int main() {
	int T;
	scanf("%d", &T);
	for (int t = 0; t < T; t++) {
		//줄기세포 초기화
		for (int i = 0; i < 51; i++) {
			for (int j = 0; j < 51; j++) {
				arr[i][j].cur_life = 0;
				arr[i][j].life = 0;
			}
		}

		scanf("%d %d %d", &N, &M, &K);
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				int val;
				scanf("%d", &val);
				arr[i][j] = node(val, val);				
			}
		}
		init_map();
	
		queue<info> que;
		for (int time = 1; time <= K; time++) {
			
			for (int i = 0; i < 400; i++) {
				for (int j = 0; j < 400; j++) {
					if (map[i][j].cur_life > -map[i][j].life && map[i][j].life>0) {
						map[i][j].cur_life--;

						if (map[i][j].cur_life < 0) {
							for (int k = 0; k < 4; k++) {
								int nx = i + dx[k];
								int ny = j + dy[k];

								if (map[nx][ny].life == 0) {
									que.push({ nx,ny,map[i][j].life });
								}
							}
						}
					}

				}
			}

			while (!que.empty()) {				
				int x = que.front().x;
				int y = que.front().y;
				int li = que.front().life;
				que.pop();
				if (map[x][y].life == 0) {
					map[x][y] = node(li, li);
				}
				else {
					if (map[x][y].life < li) {
						map[x][y] = node(li, li);
					}
				}
			}

			/*cout << "##########  "<<time << endl;
			for (int i = 490; i < 510; i++) {
				for (int j = 490; j < 510; j++) {
					printf("%2d ", map[i][j].life);
				}
				cout << endl;
			}
			cout << endl;*/
		}

		for (int i = 0; i < 400; i++) {
			for (int j = 0; j < 400; j++) {
				if (map[i][j].life>0&&map[i][j].cur_life > -map[i][j].life  && ) {
					ans++;
				}
			}
		}
		printf("#%d %d\n", t+1, ans);
		ans = 0;
	}
}