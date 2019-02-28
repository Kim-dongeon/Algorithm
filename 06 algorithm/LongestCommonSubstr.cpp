/*
0 �� i �� len(A)�̰� 0 �� j �� len(B)�� ��,
A[i] == B[j]�� ��� LCSTable(i, j) = LCSTable(i - 1, j - 1) + 1
�ƴ� ��� LCSTable(i, j) = 0
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