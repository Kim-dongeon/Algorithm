/*
입력
9 14
2 1 8 1 3 7 2 6 3

출력
3

n=9, k= 14일때 
몇개의 연속된 수를 합쳐야 k보다 커지는가?
최소한의 개수
*/
#include <stdio.h>
#include <iostream>

using namespace std;

int arr[100];
int n, k;
bool check(int interval) {
	int sum = 0;
	for (int i = 0; i<interval; i++) {
		sum += arr[i];
	}
	if (sum > k) return true;

	for (int i = 0; i<n - interval; i++) {
		sum = sum - arr[i] + arr[i + interval];
		if (sum > k) return true;
	}
	return false;
}

int main() {
	cin >> n >> k;

	for (int i = 0; i<n; i++) {
		cin >> arr[i];
	}

	int left = 0;
	int right = n;

	if (check(1)) {
		cout << "1";
		return 0;
	}
	if (!check(n)) {
		cout << "-1";
		return 0;
	}

	while (left + 1<right) {
		int mid = (left + right) / 2;
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