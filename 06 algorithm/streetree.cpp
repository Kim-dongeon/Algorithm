/*
����
�������� �Ǿ��ִ� ������ �� ���� ���μ��� ������ �������� �ɾ����ִ�. KOI �ÿ����� ���μ����� ��� ���� ������ �ǵ��� ���μ��� �߰��� �ɴ� ����� �����ϰ� �ִ�. KOI �ÿ����� ���깮���� ������ �� ���� ���� ���� ������ �ɰ� �ʹ�.

���ǻ� ���μ��� ��ġ�� ���������� ���� ������ �ִ� �Ÿ��� ǥ���Ǹ�, ���μ��� ��ġ�� ��� ���� �����̴�.

���� ���, ���μ��� (1, 3, 7, 13)�� ��ġ�� �ִٸ� (5, 9, 11)�� ��ġ�� ���μ��� �� ������ ��� ���μ����� ������ ���� �ȴ�. ����, ���μ��� (2, 6, 12, 18)�� �ִٸ� (4, 8, 10, 14, 16)�� ���μ��� �� �ɾ�� �Ѵ�.

�ɾ��� �ִ� ���μ��� ��ġ�� �־��� ��, ��� ���μ��� ���� ������ �ǵ��� ���� �ɾ�� �ϴ� ���μ��� �ּҼ��� ���ϴ� ���α׷��� �ۼ��϶�. ��, �߰��Ǵ� ������ ������ ������ ���̿��� ���� �� �ִ�.

�Է�
ù° �ٿ��� �̹� �ɾ��� �ִ� ���μ��� ���� ��Ÿ���� �ϳ��� ���� N�� �־�����(3��N��100,000). ��° �ٺ��� N���� �ٿ��� �� �ٸ��� �ɾ��� �ִ� ���μ��� ��ġ�� ���� ������ �־�����, ���μ��� ��ġ�� ��Ÿ���� ������ 1,000,000,000 �����̴�. ���μ��� ��ġ�� ��Ÿ���� ������ ��� �ٸ��� ����� ��ġ�� �ִ� ���μ����� �־�����.



���
��� ���μ��� ���� ������ �ǵ��� ���� �ɾ�� �ϴ� ���μ��� �ּҼ��� ù ��° �ٿ� ����Ѵ�.



���� �Է�
4
1
3
7
13
���� ���
3*/

#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

int gcd(int a, int b) {
	if (b == 0) {
		return a;
	}
	gcd(b, a%b);
}
int main() {

	int N;
	int arr[100002] = { 0, };
	cin >> N;
	for (int i = 0; i<N; i++) {
		scanf("%d", &arr[i]);
	}
	int maxGcd = arr[1] - arr[0];

	for (int i = 3; i<N; i++) {
		maxGcd = gcd(maxGcd, arr[i] - arr[i - 1]);
	}

	int cnt = 0;
	int a1 = arr[0];
	for (int i = 1; i<N;) {
		if (arr[i] != a1 + maxGcd) {
			cnt++;
			a1 = a1 + maxGcd;

		}
		else {
			a1 = arr[i];
			i++;
		}
	}
	printf("%d", cnt);
	return 0;
}