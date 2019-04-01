#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int ans;
int arr[20];
int max_val = -987654321;
int min_val = 987654321;
int N;
int op[4];

void dfs(int num,int index) {
	if (index == N) {
		max_val = max(max_val, num);
		min_val = min(min_val, num);
		return;
	}

	if (op[0] > 0) {
		op[0]--;
		dfs(num + arr[index], index + 1);
		op[0]++;
	}
	if (op[1] > 0) {
		op[1]--;
		dfs(num - arr[index], index + 1);
		op[1]++;
	}
	if (op[2] > 0) {
		op[2]--;
		dfs(num * arr[index], index + 1);
		op[2]++;
	}
	if (op[3] > 0) {
		op[3]--;
		dfs(num / arr[index], index + 1);
		op[3]++;
	}
	
}
int main() {
	int T;
	scanf("%d", &T);

	for (int t = 0; t < T; t++) {
		scanf("%d", &N);
		for (int i = 0; i < 4; i++) {
			scanf("%d", &op[i]);
		}
		for (int i = 0; i < N; i++) {
			scanf("%d", &arr[i]);
		}
		dfs(arr[0], 1);

		ans = max_val - min_val;
		printf("#%d %d\n", t + 1, ans);
		ans = 0;
		max_val = -987654321;
		min_val = 987654321;
	}
}