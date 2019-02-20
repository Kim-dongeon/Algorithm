/*
문제
두 종류의 부등호 기호 ‘<’와 ‘>’가 k 개 나열된 순서열 A가 있다. 우리는 이 부등호 기호 앞뒤에 서로 다른 한 자릿수 숫자를 넣어서 모든 부등호 관계를 만족시키려고 한다. 예를 들어, 제시된 부등호 순서열 A가 다음과 같다고 하자.

A ⇒ < < < > < < > < >

부등호 기호 앞뒤에 넣을 수 있는 숫자는 0부터 9까지의 정수이며 선택된 숫자는 모두 달라야 한다. 아래는 부등호 순서열 A를 만족시키는 한 예이다.

3 < 4 < 5 < 6 > 1 < 2 < 8 > 7 < 9 > 0

이 상황에서 부등호 기호를 제거한 뒤, 숫자를 모두 붙이면 하나의 수를 만들 수 있는데 이 수를 주어진 부등호 관계를 만족시키는 정수라고 한다. 그런데 주어진 부등호 관계를 만족하는 정수는 하나 이상 존재한다. 예를 들어 3456128790 뿐만 아니라 5689023174도 아래와 같이 부등호 관계 A를 만족시킨다.

5 < 6 < 8 < 9 > 0 < 2 < 3 > 1 < 7 > 4

여러분은 제시된 k 개의 부등호 순서를 만족하는 (k+1) 자리의 정수 중에서 최대값과 최소값을 찾아야 한다. 앞서 설명한 대로 각 부등호의 앞뒤에 들어가는 숫자는 { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 }중에서 선택해야 하며 선택된 숫자는 모두 달라야 한다. 프로그램의 실행시간은 0.5초를 넘을 수 없다.



입력
첫 줄에 부등호 문자의 개수를 나타내는 정수 가 주어진다. 그 다음 줄에는 k 개의 부등호 기호가 하나의 공백을 두고 한 줄에 모두 제시된다. k 의 범위는 2 <= k <= 9이다.



출력
여러분은 제시된 부등호 관계를 만족하는 자리의 최대, 최소 정수를 첫째 줄과 둘째 줄에 각각 출력해야 한다. 단 아래 예(1)과 같이 첫 자리가 0인 경우도 정수에 포함되어야 한다. 모든 입력에 답은 항상 존재하며 출력 정수는 하나의 문자열이 되도록 해야 한다.



예제 입력
2
< >
예제 출력
897
021


예제 입력
9
> < < < > > > < <
예제 출력
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