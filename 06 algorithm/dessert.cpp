/*
문제
농부 존은 소들의 저녁식사 줄 세우는 새로운 방법을 개발 했다. N(1~15)마리의 소들을 순서대로 세 워놓은 후, 각 소들 사이에 +, - , . 셋 중 1가지가 써져있는 냅킨을 배치해서 최종 결과가 0 이 되게 해야 하는 것이다. 점(.)이 써져있는 냅킨을 통해 더 큰 수를 만들 수 있게 된다. 아래와 같은 경우를 보자. (ps .이 써져있는 냅킨은 '공백'이라고 생각하면 된다.) 1-2.3-4.5+6.7 이와 같은 배치는 1-23-45+67 을 나타낸다. 결과는 0 이다. 10.11은 1011 로 해석된다.



입력
첫 째 줄에는 소들의 수 N(1 ≤ N ≤ 15)이 입력된다.



출력
처음 20줄에 대해 가능한 20가지 답을 출력하는데, 사전 순으로 앞선 것을 출력한다. 순서는 +가 가장 앞서고 -와 . 이 순서대로 뒤따른다. 답이 20개 미만이면 가능한 답을 각 숫자와 문자 사이에 공백을 두고 출력한다. 모두 출력한다. 마지막 줄에는 가능한 답의 총 가지수를 출력한다.



예제 입력
7
예제 출력
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