#include <iostream>
#include <cstdio>
#include <algorithm>
#include <functional>
using namespace std;

int N, K;
int ans = 0;
int arr[102];

int main() {
	int T;
	cin >> T;

	for (int t = 0; t <T; t++) {
		cin >> N >> K;
		for (int i = 0; i < N; i++) {
			cin >> arr[i];
		}
		sort(arr, arr + N,greater<int>());
		for (int i = 0; i < K; i++) {
			ans += arr[i];
		}
		printf("#%d %d\n", t + 1, ans);
		ans = 0;
	}
	
	
}