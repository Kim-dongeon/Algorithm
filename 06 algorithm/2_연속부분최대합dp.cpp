#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

int arr[1000002];
int dp[1000002];
int main() {

	int N;
	cin >> N;

	for (int i = 0; i<N; i++) {
		scanf("%d", &arr[i]);
	}

	dp[0] = arr[0];

	int ans = -1;
	for (int i = 1; i<N; i++) {
		dp[i] = max(dp[i - 1] + arr[i], arr[i]);
		ans = max(ans, dp[i]);
	}

	cout << ans;

	return 0;
}