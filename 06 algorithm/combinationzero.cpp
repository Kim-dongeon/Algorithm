/*n���� ����� m���� ������ ������� �̴� ����� ���� �����̶�� �ϸ� nCm���� ��Ÿ����.

nCm�� �������� n!/ m!(n - m)!���� ���� �� �ִ�. (5!= 12345)

n�� m�� �־������� nCm�� ���ڸ� 0�� ������ ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� ���� n, m(0��m��n��1, 000, 000)�� ���´�.



���
ù° �ٿ� 0�� ������ ����Ѵ�.



���� �Է�
25 12
���� ���
2*/

#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

int cal(int num, int divide) {
	int sum = 0;
	for (int i = 2; i <= num; i++) {
		int temp = i;
		while (temp%divide == 0) {
			sum++;
			temp /= divide;
		}
	}

	return sum;
}
int main() {
	int n, m;

	cin >> n >> m;

	cout << min((cal(n, 2) - cal(m, 2) - cal(n - m, 2)), (cal(n, 5) - cal(m, 5) - cal(n - m, 5)));

	return 0;
}