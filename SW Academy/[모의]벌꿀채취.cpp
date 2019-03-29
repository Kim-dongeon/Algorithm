#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
int N;
int M;
int C;
int arr[12][12];
int ans = 0;
int set[300];
int tmp_sum;

void dfs(vector<int> &v,int sz,int num,int val) {
	if (num > C) {
		return;
	}

	if (sz==M) {
		//계산		
		tmp_sum = max(tmp_sum, val);
		return;
	}
	

	dfs(v, sz + 1, num + v[sz], val + (v[sz] * v[sz]));
	dfs(v, sz + 1, num, val);
}
void comb(int sz, int n,int k, int index) {
	if (k == 0) {
		int x1 = set[0] / (N - M + 1);
		int x2 = set[1] / (N - M + 1);
		int y1 = set[0] % (N - M + 1);
		int y2 = set[1] % (N - M + 1);
		for (int i = 0; i < M; i++) {
			if (x1 == x2 && y1+i == y2 ) {
				return;
			}
		}
		
		
		int idx = 0;
		vector<int> v1;
	
		int sum = 0;
		for (int i = 0; i < sz; i++) {
			int a = set[i] / (N-M+1) ;
			int b = set[i] % (N - M+1);

			for (int j = 0; j < M; j++) {
				v1.push_back(arr[a][b + j]);
			}
			//dfs로 최대값 찾기
			dfs(v1, 0, 0, 0);
			sum += tmp_sum;			
			tmp_sum = 0;
			v1.clear();
		}
		
		//ans 구해주기
		ans = max(ans, sum);
		return;
	}
	else if (n == index) {
		return;
	}

	set[sz] = index;
	comb(sz + 1, n, k - 1, index + 1);
	comb(sz, n, k, index + 1);
}
int main() {
	int T;
	scanf("%d", &T);


	for (int t = 0; t < T; t++) {
		scanf("%d %d %d", &N, &M, &C);
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				scanf("%d", &arr[i][j]);
			}
		}
		int n = (N - M + 1)*N;

		comb(0, n, 2, 0);

		printf("#%d %d\n", t + 1, ans);
		memset(set, 0, sizeof(set));
		ans = 0;
	}
}