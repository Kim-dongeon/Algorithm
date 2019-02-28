/*
0 ≤ i ≤ len(A)이고 0 ≤ j ≤ len(B)일 때,
A[i] == B[j]일 경우 LCSTable(i, j) = LCSTable(i - 1, j - 1) + 1
아닐 경우 LCSTable(i, j) = 0
*/
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int dp[10000][10000];
int ans = 0;
int main() {
	string str1 = "abbbaca";
	string str2 = "bbzzzzzaca";

	for (int i = 1; i <= str1.size(); i++) {
		for (int j = 1; j <= str2.size(); j++) {
			if (str1[i-1] == str2[j-1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
				ans = max(ans, dp[i][j]);
			}
		}
	}
	
	cout << ans;
}