/*
����
�� ������ �ε�ȣ ��ȣ ��<���� ��>���� k �� ������ ������ A�� �ִ�. �츮�� �� �ε�ȣ ��ȣ �յڿ� ���� �ٸ� �� �ڸ��� ���ڸ� �־ ��� �ε�ȣ ���踦 ������Ű���� �Ѵ�. ���� ���, ���õ� �ε�ȣ ������ A�� ������ ���ٰ� ����.

A �� < < < > < < > < >

�ε�ȣ ��ȣ �յڿ� ���� �� �ִ� ���ڴ� 0���� 9������ �����̸� ���õ� ���ڴ� ��� �޶�� �Ѵ�. �Ʒ��� �ε�ȣ ������ A�� ������Ű�� �� ���̴�.

3 < 4 < 5 < 6 > 1 < 2 < 8 > 7 < 9 > 0

�� ��Ȳ���� �ε�ȣ ��ȣ�� ������ ��, ���ڸ� ��� ���̸� �ϳ��� ���� ���� �� �ִµ� �� ���� �־��� �ε�ȣ ���踦 ������Ű�� ������� �Ѵ�. �׷��� �־��� �ε�ȣ ���踦 �����ϴ� ������ �ϳ� �̻� �����Ѵ�. ���� ��� 3456128790 �Ӹ� �ƴ϶� 5689023174�� �Ʒ��� ���� �ε�ȣ ���� A�� ������Ų��.

5 < 6 < 8 < 9 > 0 < 2 < 3 > 1 < 7 > 4

�������� ���õ� k ���� �ε�ȣ ������ �����ϴ� (k+1) �ڸ��� ���� �߿��� �ִ밪�� �ּҰ��� ã�ƾ� �Ѵ�. �ռ� ������ ��� �� �ε�ȣ�� �յڿ� ���� ���ڴ� { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 }�߿��� �����ؾ� �ϸ� ���õ� ���ڴ� ��� �޶�� �Ѵ�. ���α׷��� ����ð��� 0.5�ʸ� ���� �� ����.



�Է�
ù �ٿ� �ε�ȣ ������ ������ ��Ÿ���� ���� �� �־�����. �� ���� �ٿ��� k ���� �ε�ȣ ��ȣ�� �ϳ��� ������ �ΰ� �� �ٿ� ��� ���õȴ�. k �� ������ 2 <= k <= 9�̴�.



���
�������� ���õ� �ε�ȣ ���踦 �����ϴ� �ڸ��� �ִ�, �ּ� ������ ù° �ٰ� ��° �ٿ� ���� ����ؾ� �Ѵ�. �� �Ʒ� ��(1)�� ���� ù �ڸ��� 0�� ��쵵 ������ ���ԵǾ�� �Ѵ�. ��� �Է¿� ���� �׻� �����ϸ� ��� ������ �ϳ��� ���ڿ��� �ǵ��� �ؾ� �Ѵ�.



���� �Է�
2
< >
���� ���
897
021


���� �Է�
9
> < < < > > > < <
���� ���
9567843012
1023765489
*/
#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

string s;
long long maxVal = -1;
long long minVal = 11111111111;
string ansMin;
string ansMax;
void r_rotate(int arr[], int s, int t) {
	int tmp = arr[t];
	for (int i = t; i>s; i--) {
		arr[i] = arr[i - 1];
	}
	arr[s] = tmp;
}
void l_rotate(int arr[], int s, int t) {
	int tmp = arr[s];
	for (int i = s; i<t; i++) {
		arr[i] = arr[i + 1];
	}
	arr[t] = tmp;
}
void perm(int arr[], int sz, int n, int k) {

	if (k == 0) {
		int stringIdx = 0;
		string str = "";
		for (int i = 0; i<sz - 1; i++) {
			if (s[stringIdx] == '<') {
				if (arr[i] > arr[i + 1]) {
					return;
				}
			}
			else {
				if (arr[i] < arr[i + 1]) {
					return;
				}
			}
			stringIdx += 2;
		}
		long long num = 0;
		for (int i = 0; i<sz; i++) {
			str += arr[i] + '0';
			num = (num * 10) + arr[i];
		}
		if (minVal > num) {
			minVal = num;
			ansMin = str;

		}
		if (maxVal < num) {
			maxVal = num;
			ansMax = str;
		}
		return;
	}
	for (int i = sz; i<n; i++) {
		r_rotate(arr, sz, i);
		perm(arr, sz + 1, n, k - 1);
		l_rotate(arr, sz, i);
	}
}
int main() {

	int arr[11] = { 0, };
	for (int i = 0; i<11; i++) {
		arr[i] = i;
	}
	int n;
	scanf("%d ", &n);


	getline(cin, s);
	perm(arr, 0, 10, n + 1);

	printf("%s\n%s", ansMax.c_str(), ansMin.c_str());
	return 0;
}