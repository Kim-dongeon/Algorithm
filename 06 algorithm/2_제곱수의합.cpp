/*
����
���� N�� �������� ������ ǥ���ϰ��� �� ��, ����ؾ� �ϴ� ���� ���� �ּ� ������ ����ϴ� ���α׷��� �ۼ��Ͻÿ�. ���� ���, ���� 45�� �������� ������ ǥ���ϰ��� �� �� �ʿ��� ���� ���� �ּ� ������ 2���̸�, �̴� ������ ����.

45 = 3^2 + 6^2


�Է�
ù ��° �ٿ� N�� �־�����. ( 1 �� N �� 100,000 )

���
�ʿ��� ���� ���� �ּ� ������ ����Ѵ�.



���� �Է�
45
���� ���
2


���� �Է�
38
���� ���
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