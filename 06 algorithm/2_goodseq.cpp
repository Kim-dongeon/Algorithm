/* 좋은수열
문제
숫자 1, 2, 3으로만 이루어지는 수열이 있다. 임의의 길이의 인접한 두 개의 부분 수열이 동일한 것 이 있으면, 그 수열을 나쁜 수열이라고 부른다. 그렇지 않은 수열은 좋은 수열이다.

다음은 나쁜 수열의 예이다.

33

32121323

123123213

다음은 좋은 수열의 예이다.

2

32

32123

1232123

길이가 N인 좋은 수열들을 N자리의 정수로 보아 그중 가장 작은 수를 나타내는 수열을 구하는 프로그램 을 작성하라. 예를 들면, 1213121과 2123212는 모두 좋은 수열이지만 그 중에서 작은 수를 나타내는 수 열 1213121이다.



입력
입력은 숫자 N하나로 이루어진다. N은 1 이상 80 이하이다.



출력
첫 번째 줄에 1, 2, 3으로만 이루어져 있는 길이가 N인 좋은 수열들 중에서 가장 작은 수를 나타내 는 수열만 출력한다. 수열을 이루는 1, 2, 3들 사이에는 빈칸을 두지 않는다.



예제 입력
7
예제 출력
1213121
*/
#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

int arr[100];
bool stop = false;
bool promising(string str) {
	int str_len = str.size();
	int loop = str_len / 2;
	for (int i = 1; i <= loop; i++) {
		if (str.substr(str_len - i, i).compare(str.substr(str_len - i * 2, i)) == 0) {
			return false;
		}
	}

	return true;
}
void good_seq(int len, int N, string str) {
	if (stop) {
		return;
	}

	if (len == N) {
		cout << str;
		stop = true;
		return;
	}

	for (int i = 1; i<4; i++) {
		string tmp_str = str;
		tmp_str += to_string(i);
		if (promising(tmp_str)) {
			good_seq(len + 1, N, tmp_str);
		}
	}
}
int main() {
	int N;
	cin >> N;

	good_seq(0, N, "");
	return 0;
}