/*
예제 입력
5 3
예제 출력
    3
   456
  21987
 3456789
987654321
*/

#include <stdio.h>
#include <iostream>

using namespace std;

int num[9] = { 1,2,3,4,5,6,7,8,9 };
int arr[102][1000];
int main() {

	int N, S;
	scanf("%d %d", &N, &S);
	S--;

	for (int i = 0; i<N; i++) {
		int j = 0;
		for (j; j<N - 1 - i; j++) {
			arr[i][j] = 0;
		}

		if (i % 2 == 0) {
			for (int k = 2 * i + j; k >= j; k--) {
				arr[i][k] = num[(S++) % 9];
			}
		}
		else {
			for (int k = j; k < 2 * i + 1 + j; k++) {
				arr[i][k] = num[(S++) % 9];
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 2 * N + 1; j++) {
			if (arr[i][j] == 0) {
				cout << ' ';
			}
			else {
				cout << arr[i][j];
			}
		}
		cout << endl;
	}
	return 0;
}