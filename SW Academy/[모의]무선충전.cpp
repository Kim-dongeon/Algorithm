#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;


vector<pair<int,int>> arr[12][12];
int dx[] = { 0,-1,0,1,0 };//0 상하좌우
int dy[] = { 0,0,1,0,-1 };
int ans;
int N = 10;
int main() {
	int T;
	scanf("%d", &T);

	for (int t = 0; t < T; t++) {
		int M; //총 이동시간
		int A;	//BC의 개수
		vector<int> move_A;	//A의 이동정보
		vector<int> move_B;
		move_A.push_back(0);
		move_B.push_back(0);

		scanf("%d %d", &M, &A);
		for (int i = 0; i < M; i++) {
			int v;
			scanf("%d", &v);
			move_A.push_back(v);
		}
		for (int i = 0; i < M; i++) {
			int v;
			scanf("%d", &v);
			move_B.push_back(v);
		}
		for (int i = 1; i <= A; i++) {
			int x, y, C, P;
			scanf("%d %d %d %d", &y, &x, &C, &P);
			
			for (int a = 0; a < C; a++) {
				int sy = y - a;
				int ux = x - C+a;
				int dx = x + C - a;
				for (int b = 0; b < 2 * a + 1; b++) {
					int ny = sy + b;
					if (ux > 0 && ux <= N&&ny > 0 && ny <= N) {
						arr[ux][ny].push_back(make_pair(i, P));
					}
					if (dx > 0 && dx <= N&&ny > 0 && ny <= N) {
						arr[dx][ny].push_back(make_pair(i, P));
					}
				}
			}
			int sy = y - C;
			for (int b = 0; b < 2 * C + 1; b++) {
				int ny = sy + b;
				if (x > 0 && x <= N&&ny > 0 && ny <= N) {
					arr[x][ny].push_back(make_pair(i, P));
				}							
			}

		}

		//충전량 높은 순서대로 정렬
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (arr[i][j].size() > 1) {
					sort(arr[i][j].begin(), arr[i][j].end(), [](pair<int,int> v1, pair<int, int> v2) {
						return v1.second > v2.second;
					});
				}
			}
		}
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (arr[i][j].size() > 0) {
					cout<< arr[i][j][0].first << ' ';
				}
				else {
					cout << 0 << ' ';
				}
			}
			cout << endl;
		}
		int ax = 1;
		int ay = 1;
		int bx = 10;
		int by = 10;
		int sum_A = 0;
		int sum_B = 0;
		for (int i = 0; i <= M; i++) {
			int A = 0;
			int B = 0;
			ax += dx[move_A[i]];
			ay += dy[move_A[i]];
			bx += dx[move_B[i]];
			by += dy[move_B[i]];

			int a_sz = arr[ax][ay].size();
			int b_sz = arr[bx][by].size();
			if (a_sz == 0 && b_sz > 0) {
				B += arr[bx][by][0].second;
			}
			else if (a_sz > 0 && b_sz == 0) {
				A += arr[ax][ay][0].second;
			}
			else if (a_sz > 0 && b_sz > 0) {
				if (a_sz == 1 && b_sz == 1) {
					if (arr[ax][ay][0].first != arr[bx][by][0].first) {
						A += arr[ax][ay][0].second;
						B += arr[bx][by][0].second;
					}
					else {
						A += arr[ax][ay][0].second/2;
						B += arr[bx][by][0].second/2;
					}
				}
				else if (a_sz == 1 && b_sz >1) {
					if (arr[ax][ay][0].first != arr[bx][by][0].first) {
						A += arr[ax][ay][0].second;
						B += arr[bx][by][0].second;
					}
					else {
						A += arr[ax][ay][0].second;
						B += arr[bx][by][1].second;
					}
				}
				else if (a_sz > 1 && b_sz == 1) {
					if (arr[ax][ay][0].first != arr[bx][by][0].first) {
						A += arr[ax][ay][0].second;
						B += arr[bx][by][0].second;
					}
					else {
						A += arr[ax][ay][1].second;
						B += arr[bx][by][0].second;
					}
				}
				else if (a_sz > 1 && b_sz >1) {
					if (arr[ax][ay][0].first != arr[bx][by][0].first) {
						A += arr[ax][ay][0].second;
						B += arr[bx][by][0].second;
					}
					else {
						if (arr[ax][ay][1].second > arr[bx][by][1].second) {
							A += arr[ax][ay][1].second;
							B += arr[bx][by][0].second;
						}
						else {
							A += arr[ax][ay][0].second;
							B += arr[bx][by][1].second;
						}
						
					}
				}			
			}
			sum_A += A;
			sum_B += B;
			cout << "#### " << i << endl;
			cout << A << ' ' << B << endl;
		}

		ans = sum_A + sum_B;
		printf("#%d %d\n", t+1, ans);
		ans = 0;
		move_A.clear();
		move_B.clear();
		for (int i = 0; i <= N; i++) {
			for (int j = 0; j < N ; j++) {
				arr[i][j].clear();
			}
		}
	}
}