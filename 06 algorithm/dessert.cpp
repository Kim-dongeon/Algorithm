/*
����
��� ���� �ҵ��� ����Ļ� �� ����� ���ο� ����� ���� �ߴ�. N(1~15)������ �ҵ��� ������� �� ������ ��, �� �ҵ� ���̿� +, - , . �� �� 1������ �����ִ� ��Ų�� ��ġ�ؼ� ���� ����� 0 �� �ǰ� �ؾ� �ϴ� ���̴�. ��(.)�� �����ִ� ��Ų�� ���� �� ū ���� ���� �� �ְ� �ȴ�. �Ʒ��� ���� ��츦 ����. (ps .�� �����ִ� ��Ų�� '����'�̶�� �����ϸ� �ȴ�.) 1-2.3-4.5+6.7 �̿� ���� ��ġ�� 1-23-45+67 �� ��Ÿ����. ����� 0 �̴�. 10.11�� 1011 �� �ؼ��ȴ�.



�Է�
ù ° �ٿ��� �ҵ��� �� N(1 �� N �� 15)�� �Էµȴ�.



���
ó�� 20�ٿ� ���� ������ 20���� ���� ����ϴµ�, ���� ������ �ռ� ���� ����Ѵ�. ������ +�� ���� �ռ��� -�� . �� ������� �ڵ�����. ���� 20�� �̸��̸� ������ ���� �� ���ڿ� ���� ���̿� ������ �ΰ� ����Ѵ�. ��� ����Ѵ�. ������ �ٿ��� ������ ���� �� �������� ����Ѵ�.



���� �Է�
7
���� ���
1 + 2 - 3 + 4 - 5 - 6 + 7
1 + 2 - 3 - 4 + 5 + 6 - 7
1 - 2 + 3 + 4 - 5 + 6 - 7
1 - 2 - 3 - 4 - 5 + 6 + 7
1 - 2 . 3 + 4 + 5 + 6 + 7
1 - 2 . 3 - 4 . 5 + 6 . 7
6*/
#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;


int num[20];
char oper[3] = { '+','-','.' };
int cnt = 0;
void r_perm(int arr[], int sz, int n, int k) {
	if (k == 0) {
		long long cal[20] = { 0, };
		int op[20] = { 0, };
		long long cal_num = 0;
		int cal_idx = 0;
		int op_idx = 0;
		bool flag = false;

		for (int i = 0; i < sz; i++) {
			if (arr[i] == 2) {
				cal_num = cal_num * 10 + num[i] * 10;
				if (num[i + 1] > 9) {
					cal_num = cal_num * 10;
				}
				flag = true;
			}
			else {
				op[op_idx++] = arr[i];
				if (flag) {
					cal_num += num[i];
					cal[cal_idx++] = cal_num;
					flag = false;
					cal_num = 0;
				}
				else {
					cal[cal_idx++] = num[i];
				}
			}

			if (i == sz - 1) {
				if (arr[i] == 2) {
					cal_num += num[i + 1];
					cal[cal_idx++] = cal_num;
				}
				else {
					cal[cal_idx++] = num[i + 1];
				}
			}
		}
		long long sum = cal[0];
		for (int i = 0; i < op_idx; i++) {
			if (op[i] == 0) {
				sum += cal[i + 1];
			}
			else {
				sum -= cal[i + 1];
			}
		}

		if (sum == 0) {
			cnt++;
			if (cnt <= 20) {
				for (int i = 0; i < sz; i++) {
					printf("%d %c ", num[i], oper[arr[i]]);
				}
				printf("%d\n", num[sz]);
			}


		}



		return;
	}
	for (int i = 0; i<n; i++) {
		arr[sz] = i;
		r_perm(arr, sz + 1, n, k - 1);
	}
}
int main() {
	int n;
	cin >> n;
	if (n == 1) {
		printf("0");
		return 0;
	}
	for (int i = 0; i <= n; i++) {
		num[i] = i + 1;
	}
	int arr[20] = { 0, };

	r_perm(arr, 0, 3, n - 1);
	printf("%d\n", cnt);
	return 0;
}