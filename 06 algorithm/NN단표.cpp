/*
알랩이는 N단까지 나온 숫자들 중에서 K번째로 작은 수를 찾고 싶어한다.

이때, 중복되는 여러 수들을 고려한다. 즉 N*N개의 모든 수들 중에서 K번째 수를 구하는 것이다.

입력
첫째 줄에 배열의 크기 N이 주어진다. N은 100,000보다 작거나 같은 자연수이다. 둘째 줄에 K가 주어진다. K는 N*N보다 작거나 같은 자연수이다.

출력
K번째 원소를 출력한다.



예제 입력
3
7
예제 출력
6*/
#include <stdio.h>
#include <algorithm>
#include <iostream>

using namespace std;
long long arr[100002] = { 0, };
int N;
long long K;
bool check(long long mid) {
	long long cnt = 0;
	for (long long i = 0; i<N; i++) {
		long long tmp = mid / arr[i];
		if (tmp > N) {
			tmp = N;
		}
		cnt += tmp;
		if (cnt >= K) {
			return true;
		}

	}
	return false;
}
int main() {
	cin >> N >> K;
	for (int i = 0; i<N; i++) {
		arr[i] = i + 1;
	}

	long long left = 0;
	long long right = N*N;

	while (left + 1<right) {
		long long mid = (left + right) / 2;

		if (check(mid)) {
			right = mid;
		}
		else {
			left = mid;
		}
	}
	cout << right;
	return 0;
}