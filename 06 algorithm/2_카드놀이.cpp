/*
문제
N개의 카드가 주어지고, 각각은 자연수의 점수를 가진다. 철수는 이제 이 카드를 가져감으로써 카드에 적혀있는 수 만큼의 점수를 얻는다. 단, 카드를 가져갈 때 한가지 규칙이 있는데, 이는 연속하여 3개의 카드는 가져갈 수 없다는 것이다. 예를 들어, 6개의 카드 “1 3 5 2 7 3”가 주어질 경우, 3+5+7+3 = 18 만큼의 점수를 얻는 것이 최대이다. N개의 카드가 주어질 때, 얻을 수 있는 점수의 최댓값을 출력하는 프로그램을 작성하시오.



입력
첫 번째 줄에 N이 주어진다. ( 1 ≤ N ≤ 100,000 ) 두 번째 줄에 N개의 숫자가 주어지며, 이는 각 카드의 점수를 나타낸다.

출력
얻을 수 있는 점수의 최댓값을 출력한다.



예제 입력
6
1 3 5 2 7 3
예제 출력
18*/
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

long long  arr[100002];
long long  dp[100002];
int main() {

	int N;
	cin >> N;
	for (int i = 0; i<N; i++) {
		scanf("%lld", &arr[i]);
	}

	dp[0] = arr[0];
	dp[1] = dp[0] + arr[1];
	dp[2] = max(arr[0], arr[1]) + arr[2];

	long long _max = max(max(dp[0], dp[1]), dp[2]);
	for (int i = 3; i<N; i++) {
		dp[i] = max(dp[i - 3] + arr[i - 1], dp[i - 2]) + arr[i];
		dp[i] = max(dp[i], dp[i - 1]);
	}
	cout << dp[N - 1];

	return 0;
}