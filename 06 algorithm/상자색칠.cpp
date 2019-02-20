/*문제
면이 6개인 상자가 있다.이를 여러 가지 색으로 칠하려 하는데, 단 조건이 있다.같은 색깔을 인접한 면에 칠하면 안 된다는 것이다.여러 가지 색깔이 주어졌을 때, 그 색깔들로 조건을 만족하여 상자의 모든 면을 칠할 수 있는지 판별하는 프로그램을 작성하시오.

입력
첫째 줄에 색깔의 개수 N(1 <= N <= 1, 000) 이 주어진다.둘째 줄에 색깔을 나타내는 N개의 숫자가 주어진다.색깔은 양의 정수로 이루어져 있고, 1부터 N까지의 범위의 수이다.

출력
조건을 만족하면서 상자를 칠할 수 있으면 “YES”, 아니면 “NO”를 출력한다.

예제 입력
6
1 1 1 2 2 3
예제 출력
NO

예제 입력
6
1 2 3 4 5 6
예제 출력
YES

예제 입력
8
1 2 2 2 1 1 1 3
예제 출력
NO
*/
#include <stdio.h>
#include <iostream>
#include <set>
using namespace std;
int main() {

	bool flag = true;
	set<int> s;
	int N;
	scanf("%d", &N);

	int chk[1002] = { 0, };
	for (int i = 0; i<N; i++) {
		int color;
		scanf("%d", &color);
		s.insert(color);
		chk[color]++;
	}

	int sz = s.size();
	int two = 0;
	for (int i = 1; i <= N; i++) {
		if (chk[i] >= 2) {
			two++;
		}
	}
	if (sz >= 6) {
		cout << "YES";
	}
	else if (sz >= 3 && sz <= 5) {
		if (two >= 6 - sz) {
			cout << "YES";
		}
		else {
			cout << "NO";
		}
	}
	else {
		cout << "NO";
	}
	return 0;
}