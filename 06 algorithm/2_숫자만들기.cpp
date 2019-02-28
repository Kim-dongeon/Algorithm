/*문제
숫자 1, 2, 3을 이용하여 숫자 N을 만드는 경우의 수를 출력하는 프로그램을 작성하시오.예를 들어, N이 4일 경우에는 다음의 7가지 경우가 존재한다.단, 경우의 수가 매우 많을 수 있으므로, 경우의 수를 1, 000, 007 로 나눈 나머지를 출력한다.

1 + 1 + 1 + 1
1 + 1 + 2
1 + 2 + 1
2 + 1 + 1
2 + 2
1 + 3
3 + 1


입력
첫 번째 줄에 N이 주어진다. (1 ≤ N ≤ 100, 000)

출력
1, 2, 3을 이용하여 N을 만들 수 있는 경우의 수를 1, 000, 007 로 나눈 나머지를 출력한다.

예제 입력
4
예제 출력
7


예제 입력
200
예제 출력
290816*/

#include <cstdio>
#include <iostream>

using namespace std;
long long dp[100001];
int main() {

	int N;
	cin >> N;

	for (int i = 1; i <= 3; i++) {
		long long sum = 0;
		for (int j = 1; j <= i; j++) {
			sum += dp[j];
		}
		dp[i] = sum + 1;
	}

	for (int i = 4; i <= N; i++) {
		dp[i] = dp[i - 3] + dp[i - 2] + dp[i - 1];
		dp[i] %= 1000007;
	}

	cout << dp[N];

	return 0;
}