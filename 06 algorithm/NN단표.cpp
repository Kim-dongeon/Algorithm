/*
�˷��̴� N�ܱ��� ���� ���ڵ� �߿��� K��°�� ���� ���� ã�� �;��Ѵ�.

�̶�, �ߺ��Ǵ� ���� ������ ����Ѵ�. �� N*N���� ��� ���� �߿��� K��° ���� ���ϴ� ���̴�.

�Է�
ù° �ٿ� �迭�� ũ�� N�� �־�����. N�� 100,000���� �۰ų� ���� �ڿ����̴�. ��° �ٿ� K�� �־�����. K�� N*N���� �۰ų� ���� �ڿ����̴�.

���
K��° ���Ҹ� ����Ѵ�.



���� �Է�
3
7
���� ���
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