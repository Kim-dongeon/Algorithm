/*n명의 사람중 m명을 순서에 상관없이 뽑는 경우의 수를 조합이라고 하며 nCm으로 나타낸다.

nCm은 수식으로 n!/ m!(n - m)!으로 구할 수 있다. (5!= 12345)

n과 m이 주어졌을때 nCm의 끝자리 0의 개수를 출력하는 프로그램을 작성하시오.

입력
첫째 줄에 정수 n, m(0≤m≤n≤1, 000, 000)이 들어온다.



출력
첫째 줄에 0의 개수를 출력한다.



예제 입력
25 12
예제 출력
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