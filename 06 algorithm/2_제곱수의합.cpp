/*
문제
숫자 N을 제곱수의 합으로 표현하고자 할 때, 사용해야 하는 제곱 수의 최소 개수를 출력하는 프로그램을 작성하시오. 예를 들어, 숫자 45를 제곱수의 합으로 표현하고자 할 때 필요한 제곱 수의 최소 개수는 2개이며, 이는 다음과 같다.

45 = 3^2 + 6^2


입력
첫 번째 줄에 N이 주어진다. ( 1 ≤ N ≤ 100,000 )

출력
필요한 제곱 수의 최소 개수를 출력한다.



예제 입력
45
예제 출력
2


예제 입력
38
예제 출력
3*/

#include <stdio.h>
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int dp[100002];


vector<int> p;

int main() {
	int N;
	cin >> N;

	for (int i = 1; i <= N; i++) {
		dp[i] = 987654321;
	}
	for (int i = 1; i <= sqrt(N); i++) {
		dp[i*i] = 1;
		p.push_back(i*i);
	}

	for (int i = 2; i <= N; i++) {
		if (dp[i] != 1) {
			for (int j = 0; j<p.size() && p[j] <= i / 2; j++) {
				int num = p[j];
				dp[i] = min(dp[i], dp[num] + dp[i - num]);
			}
		}
	}

	cout << dp[N];
	return 0;
}