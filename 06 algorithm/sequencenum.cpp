/*첫째 줄에 양의 정수 N이 주어진다. (3 <= N <= 1000) N개의 줄에 N개의 양의 정수가 TABLE S로 주어진다.각 정수들은 100000 이하이다.TABLE S[i, j] 는 A[i] + A[j] 의 관계가 있다. (i 는 j와 같지 않을 경우에만 해당하고, 만약 i 와 j가 같다면 S[i, j] = 0 이다.) S[i, j]는 테이블에서 i번째 row와 j번째 column을 의미한다.그리고 A[i] 는 수열 A의 i번째 요소를 의미한다.어떤 입력 값에 대해서 양의 정수 수열 A는 단 하나 뿐임이 보장된다.
출력
첫째줄에 수열 A를 출력한다. (N개의 양의 정수를 공백을 가지고 출력한다.)



예제 입력
4
0 3 6 7
3 0 5 6
6 5 0 9
7 6 9 0
예제 출력
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