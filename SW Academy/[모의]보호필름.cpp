#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int D;
int W;
int K;
int arr[20][30];
int cpy[20][30];
int ans=987654321;
int set[30];
bool chk() {	
	for (int i = 0; i < W; i++) {
		int A = 0;
		int B = 0;
		bool ret = false;
		for (int j = 0; j < D; j++) {
			if (cpy[j][i] == 0) {
				//A
				A++;
				B = 0;
			}
			else {
				B++;
				A = 0;
			}

			if (A >= K || B >= K) {
				ret = true;
				break;
			}
		}

		if (ret == false) {
			return false;
		}
		
	}

	return true;
}

void go(int sz,int n,int k) {

	if (k == 0) {
		//copy
		int cnt = 0;
		for (int i = 0; i < sz; i++) {
			if (set[i] != 0) {
				cnt++;
			}
		}

		if (cnt >= ans) {
			return;
		}

		for (int i = 0; i < D; i++) {
			for (int j = 0; j < W; j++) {
				cpy[i][j] = arr[i][j];
			}
		}		

		for (int i = 0; i < sz; i++) {
			if (set[i] == 1) {
				//A로변환
				for (int j = 0; j < W; j++) {
					cpy[i][j] = 0;					
				}				
			}
			else if (set[i] == 2) {
				//B로 변환
				for (int j = 0; j < W; j++) {
					cpy[i][j] = 1;					
				}				
			}
		}

		if (chk()) {
			ans = min(ans, cnt);
		}		
		return;
	}
	for (int i = 0; i < n; i++) {
		set[sz] = i;
		go(sz + 1, n, k-1);
	}
}
int main() {
	int T;
	scanf("%d", &T);

	for (int t = 0; t < T; t++) {
		scanf("%d %d %d", &D, &W, &K);

		for (int i = 0; i < D; i++) {
			for (int j = 0; j < W; j++) {
				scanf("%d", &arr[i][j]);
				cpy[i][j] = arr[i][j];
			}
		}

		if (chk()) {
			printf("#%d %d\n", t + 1, 0);
			continue;
		}

		go(0, 3, D);

		printf("#%d %d\n", t + 1, ans);
		ans = 987654321;
		memset(set, 0, sizeof(set));
	}
}