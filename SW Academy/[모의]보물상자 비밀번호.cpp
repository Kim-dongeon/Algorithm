#include <iostream>
#include <cstdio>
#include <algorithm>
#include <set>
#include <functional>
#include <string>
using namespace std;

int N, K;
char arr[30];
int ans = 0;

void rotate() {
	int tmp = arr[N - 1];
	for (int i = N - 1; i > 0; i--) {
		arr[i] = arr[i - 1];
	}
	arr[0] = tmp;
}
int main() {
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		cin >> N >> K;
		for (int i = 0; i < N; i++) {
			scanf(" %c", &arr[i]);
		}

		set<int, greater<int>> s;

		int M = N / 4;
		for (int i = 0; i < M; i++) {//회전 숫자
			//숫자 만들어서
			for (int j = 0; j < 4; j++) {//4변
				string str;
				for (int a = 0; a < M; a++) {//1변당					
					str += arr[j*M + a];
				}
				s.insert(stoi(str, 0, 16));
				cout << str << endl;
			}
			//회전
			rotate();
		}
		set<int, greater<int>>::iterator it = s.begin();
		for (int i=0; i<K-1 ;i++) {
			++it;
		}
		ans = *it;

		printf("#%d %d\n", t + 1, ans);
		ans = 0;
	}
}