#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;
int ans = 987654321;
vector<int> v;
int fee[4];
int set[20];
void go(int sz, int n, int k) {
	if (k==0) {
		int sum = 0;

		for (int i = 0; i < sz; i++) {
			if (set[i] == 0) {
				//하루치
				sum+= v[i] * fee[0];
			}
			else if (set[i] == 1) {
				//한달
				sum += fee[1];
			}
			else if (set[i] == 2) {
				//3개월
				sum += fee[2];
				i += 2;
			}

			if (sum > ans) {
				return;
			}
		}
		
		ans = min(ans, sum);
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
		for (int i = 0; i < 4; i++) {
			scanf("%d", &fee[i]);
		}
		for (int i = 0; i < 12; i++) {
			int a;
			scanf("%d", &a);
			if (a != 0) {
				v.push_back(a);
			}
		}

		//1년권
		ans = min(ans, fee[3]);

		go(0, 3, v.size());

		printf("#%d %d\n", t + 1, ans);
		ans = 987654321;
		v.clear();
		memset(set, 0, sizeof(set));
	}
}