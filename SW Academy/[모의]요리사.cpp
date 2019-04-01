#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cstring>
using namespace std;

int ans = 987654321;
int arr[20][20];
int N;
int set[20];

void comb(int sz, int n, int k) {
	if (k == 0) {
		vector<int> foodA;
		vector<int> foodB;

		for (int i = 0; i < n; i++) {			
			if (set[i] == 1) {
				foodA.push_back(i);
			}
			else {
				foodB.push_back(i);
			}
		}

		int sumA = 0;
		int sumB = 0;

		for (int i = 0; i < N / 2; i++) {
			for (int j = 0; j < N / 2; j++) {
				if (i == j) continue;
				sumA += arr[foodA[i]][foodA[j]];
				sumB += arr[foodB[i]][foodB[j]];
			}
		}

		ans = min(ans, abs(sumA - sumB));
		return;
	}
	else if (n==sz) {
		return;
	}

	set[sz] = 1;
	comb(sz + 1, n, k - 1);
	set[sz] = 0;
	comb(sz+1, n, k);
}
int main() {
	int T;
	scanf("%d", &T);

	for (int t = 0; t < T; t++) {
		scanf("%d", &N);

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				scanf("%d", &arr[i][j]);
			}
		}

		comb(0, N, N / 2);
		printf("#%d %d\n", t + 1, ans);
		ans = 987654321;
		memset(set, 0, sizeof(set));
	}
}