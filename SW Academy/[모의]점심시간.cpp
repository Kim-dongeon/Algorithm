#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>
#include <queue>
using namespace std;

int N;
int arr[12][12];
int ans = 987564321;
vector<pair<int,int>> stairs;
vector<pair<int, int>> people;
int set[12];

void go(int sz, int n, int k) {

	if (k == 0) {		
		vector<int> dis[2];
		for (int i = 0; i < sz; i++) {
			int px = people[i].first;
			int py = people[i].second;
			int sx = stairs[set[i]].first;
			int sy = stairs[set[i]].second;
			
			int m = abs(sx - px) + abs(sy - py);
			dis[set[i]].push_back(m);
		}
		
		int cur = 0;
		for (int i = 0; i < 2; i++) {
			sort(dis[i].begin(), dis[i].end());
			int len = dis[i].size();
			int stairs_len = arr[stairs[i].first][stairs[i].second];
			queue<int> que;
			for (int j = 0; j < len; j++) {
				if (que.size() < 3) {
					que.push(dis[i][j] + 1 + stairs_len);
				}
				else {
					int waiting = que.front();
					que.pop();
					que.push(max(waiting, dis[i][j] + 1) + stairs_len);
				}
			}
			while (!que.empty()) {
				cur = max(cur, que.front());
				que.pop();
			}			
		}
		ans = min(cur, ans);

		cout << cur << endl;

		return;
	}
	for (int i = 0; i < n; i++) {
		set[sz] = i;
		go(sz + 1, n, k - 1);
	}
}
int main() {
	int T;
	scanf("%d", &T);

	for (int t = 0; t < T; t++) {
		scanf("%d", &N);

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				scanf("%d", &arr[i][j]);
				if (arr[i][j] == 1) {
					people.push_back(make_pair(i, j));
				}
				else if (arr[i][j] > 1) {
					stairs.push_back(make_pair(i, j));
				}
			}
		}
		
		go(0, stairs.size(), people.size());


		printf("#%d %d\n", t + 1, ans);
		ans = 987654321;
		people.clear();
		stairs.clear();
		memset(set, 0, sizeof(set));
	}
}