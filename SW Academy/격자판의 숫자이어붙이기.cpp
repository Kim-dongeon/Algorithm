#include <cstdio>
#include <algorithm>
#include <iostream>
#include <string>
#include <set>
using namespace std;

int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };

int arr[6][6];
int N = 4;
int ans = 0;
set<string> ss;
void go(string str, int sz,int x,int y) {
	if (sz == 7) {
		ss.insert(str);
		return;
	}
	for (int k = 0; k < 4; k++) {
		int nx = x + dx[k];
		int ny = y + dy[k];

		if (nx >= 0 && nx < N&&ny >= 0 && ny < N) {
			go(str.append(1, arr[nx][ny] + '0'), sz + 1, nx, ny);
			str.erase(str.size() - 1, 1);
		}
	}
}
int main() {
	int T;
	cin >> T;

	for (int t = 1; t <= T; t++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				scanf("%d", &arr[i][j]);
			}
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				go(to_string(arr[i][j]), 1,i,j);
			}
		}

		ans = ss.size();

		for (set<string>::iterator it=ss.begin(); it != ss.end(); ++it) {
			cout << *it << endl;
		}
		printf("#%d %d\n", t, ans);
		ans = 0;
		ss.clear();
	}


}