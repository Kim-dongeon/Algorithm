/*
����
������ [s, e] �� ��Ÿ����, �� �ǹ̴� s, (s+1), (s+2), ��, (e-1), e �� ���� ���ڸ� ������ ���� �ǹ��Ѵ�. ���� ���, [1, 4]�� 1, 2, 3, 4�� ���ڸ� ������ ���� �ǹ��Ѵ�. n���� ������ �ְ�, �� �������� ���ڸ� ��δ� ���ο� �迭 S�� �־� ������ �Ѵ�. �� �� S[i] �� ���� �������� ����ϴ� ���α׷��� �ۼ��Ͻÿ�. ���� ���, 3���� ���� [1, 3], [2, 10], [1, 8] �� �ְ�, S[5]�� �˰�ʹٰ� ����. �׷��� S = [1, 1, 2, 2, 2, 3, 3, 3, 4, 4, 5, 5, 6, 6, 7, 7, 8, 8, 9, 10] �� �ǰ�, ���� S[5]�� 3�� �ȴ�. �迭�� �ε����� 0���� �����Ѵٴ� �Ϳ� ��������.



�Է�
ù ��° �ٿ� ������ ���� n�� �־����� ( 1 �� n �� 10,000 ) �� ��° �ٺ��� �� ������ ��Ÿ���� ���� s, e�� �־�����. ( 1 �� s �� e �� 1,000,000,000 ) �� ��, ������ �ٿ��� ���� �˰� ���� ������ ��ġ i�� �־�����. ( 1 �� i �� 10,000,000,000,000 ) i��° ��ġ���� �׻� ���ڰ� �����Ѵٰ� �����Ѵ�.

���
S[i]�� ����Ѵ�.

���� �Է�
2
1 4
3 5
3
���� ���
3
���� �Է�
3
1 3
2 10
1 8
5
���� ���
3*/
#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

long long N;
long long I;
long long arr[10002][2];
bool check(long long mid) {
	long long cnt = 0;
	for (int i = 0; i<N; i++) {
		if (mid >= arr[i][0]) {
			if (mid >= arr[i][1]) {
				cnt += (arr[i][1] - arr[i][0] + 1);
			}
			else {
				cnt += (mid - arr[i][0] + 1);
			}
		}


		if (cnt >= I) { return true; }
	}

	return false;
}
int main() {
	cin >> N;


	long long left = 0;
	long long right = -1;
	for (int i = 0; i<N; i++) {
		cin >> arr[i][0] >> arr[i][1];
		right = max(right, arr[i][1]);
	}
	cin >> I;
	I++;
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