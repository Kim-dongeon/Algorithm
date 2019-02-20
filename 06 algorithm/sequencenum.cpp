/*ù° �ٿ� ���� ���� N�� �־�����. (3 <= N <= 1000) N���� �ٿ� N���� ���� ������ TABLE S�� �־�����.�� �������� 100000 �����̴�.TABLE S[i, j] �� A[i] + A[j] �� ���谡 �ִ�. (i �� j�� ���� ���� ��쿡�� �ش��ϰ�, ���� i �� j�� ���ٸ� S[i, j] = 0 �̴�.) S[i, j]�� ���̺��� i��° row�� j��° column�� �ǹ��Ѵ�.�׸��� A[i] �� ���� A�� i��° ��Ҹ� �ǹ��Ѵ�.� �Է� ���� ���ؼ� ���� ���� ���� A�� �� �ϳ� ������ ����ȴ�.
���
ù°�ٿ� ���� A�� ����Ѵ�. (N���� ���� ������ ������ ������ ����Ѵ�.)



���� �Է�
4
0 3 6 7
3 0 5 6
6 5 0 9
7 6 9 0
���� ���
2 1 4 5*/

#include <stdio.h>
#include <iostream>

using namespace std;
int arr[1002][1002];
int sub[1002][1002];
int main() {

	int N;
	scanf("%d", &N);
	for (int i = 0; i<N; i++) {
		for (int j = 0; j<N; j++) {
			scanf("%d", &arr[i][j]);
			if (j>i) {
				if (arr[i][j - 1] != 0) {
					sub[i][j] = arr[i][j] - arr[i][j - 1];
				}
			}
		}
	}

	int A[1002] = { 0, };

	for (int i = N - 1; i>1; i--) {
		int j = i - 1;
		int a = arr[0][i] - arr[0][j];
		int b = arr[i][j];

		A[i] = (b + a) / 2;
		A[j] = (b - a) / 2;
	}
	A[0] = arr[0][1] - A[1];

	for (int i = 0; i<N; i++) {
		cout << A[i] << ' ';
	}
	return 0;
}