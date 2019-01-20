#include <iostream>
#include <queue>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int min_h = 101;
int max_h = -1;
int arr[102][102];
int arr_temp[102][102];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1, -1,0,0};
bool isVisited[102][102];
queue < pair<int, int>> que;
int max_area = 0;
int ans = 1;
void flood(int rain, int N) {	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (arr[i][j] <= rain) {
				arr_temp[i][j] = 0;
			}
			else {
				arr_temp[i][j] = arr[i][j];
			}
		}
	}
	
	int area = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (arr_temp[i][j] != 0 && isVisited[i][j] == false) {
				que.push(make_pair(i, j));
				isVisited[i][j] = true;
				while (!que.empty()) {
					int x = que.front().first;
					int y = que.front().second;
					que.pop();
					for (int k = 0; k < 4; k++) {
						int nx = dx[k] + x;
						int ny = dy[k] + y;
						if (nx >= 0 && nx < N && ny >= 0 && ny < N && isVisited[nx][ny] == false && arr_temp[nx][ny] !=0) {
							que.push(make_pair(nx, ny));
							isVisited[nx][ny] = true;
						}
					}
				}				
				area++;
			}
		}
	}
	for (int i = 0; i < N; i++) {
		memset(isVisited[i], 0, sizeof(bool)*N);
		memset(arr_temp[i], 0, sizeof(int)*N);
	}
	//cout << rain << ' ' << area << endl;
	if (max_area <= area) {
		max_area = area;
		ans = area;
	}
}
int main() {
	int N = 0;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &arr[i][j]);
			min_h = min(arr[i][j], min_h);
			max_h = max(arr[i][j], max_h);
		}
	}
	for (int i = min_h; i < max_h; i++) {
		flood(i,N);
	}
	printf("%d", ans);
}